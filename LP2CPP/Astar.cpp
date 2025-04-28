#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <cmath>

struct Node {
    std::pair<int, int> position;
    Node* parent;
    double g; // Cost from start to current Node
    double h; // Heuristic (estimated cost from current to goal)
    double f; // Total cost (g + h)

    Node(std::pair<int, int> pos, Node* p = nullptr) : position(pos), parent(p), g(0), h(0), f(0) {}
};

// Comparison function for priority queue
struct CompareNode {
    bool operator()(const Node* a, const Node* b) const {
        return a->f > b->f; // Min-heap based on f value
    }
};

// Hash function for pair to use in unordered_set
struct PairHash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

// Manhattan distance heuristic
double heuristic(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return std::abs(a.first - b.first) + std::abs(a.second - b.second);
}

std::vector<std::pair<int, int>> astar(const std::vector<std::vector<int>>& grid, 
                                       const std::pair<int, int>& start, 
                                       const std::pair<int, int>& end) {
    std::priority_queue<Node*, std::vector<Node*>, CompareNode> open_list;
    std::unordered_set<std::pair<int, int>, PairHash> closed_set;
    
    Node* start_node = new Node(start);
    open_list.push(start_node);
    
    while (!open_list.empty()) {
        Node* current_node = open_list.top();
        open_list.pop();
        
        // Add to closed set
        closed_set.insert(current_node->position);
        
        // Check if reached goal
        if (current_node->position == end) {
            std::vector<std::pair<int, int>> path;
            while (current_node) {
                path.push_back(current_node->position);
                current_node = current_node->parent;
            }
            std::reverse(path.begin(), path.end());
            return path;
        }
        
        // Get neighbors
        int x = current_node->position.first;
        int y = current_node->position.second;
        std::vector<std::pair<int, int>> neighbors = {
            {x-1, y}, {x+1, y}, {x, y-1}, {x, y+1} // Up, Down, Left, Right
        };
        
        for (const auto& next_pos : neighbors) {
            int nx = next_pos.first;
            int ny = next_pos.second;
            
            // Check if valid and walkable
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 0) {
                // Skip if in closed set
                if (closed_set.find(next_pos) != closed_set.end()) {
                    continue;
                }
                
                // Create new node
                Node* neighbor = new Node(next_pos, current_node);
                neighbor->g = current_node->g + 1;
                neighbor->h = heuristic(neighbor->position, end);
                neighbor->f = neighbor->g + neighbor->h;
                
                // Check if already in open list with better f score
                bool skip = false;
                std::priority_queue<Node*, std::vector<Node*>, CompareNode> temp_queue = open_list;
                while (!temp_queue.empty()) {
                    Node* open_node = temp_queue.top();
                    temp_queue.pop();
                    if (open_node->position == neighbor->position && open_node->f <= neighbor->f) {
                        skip = true;
                        break;
                    }
                }
                
                if (!skip) {
                    open_list.push(neighbor);
                }
            }
        }
    }
    
    // No path found
    return {};
}

int main() {
    // Example grid (0 = walkable, 1 = obstacle)
    std::vector<std::vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0}
    };

    std::pair<int, int> start = {0, 0};
    std::pair<int, int> end = {4, 4};

    std::vector<std::pair<int, int>> path = astar(grid, start, end);

    if (!path.empty()) {
        std::cout << "Path found: ";
        for (const auto& p : path) {
            std::cout << "(" << p.first << "," << p.second << ") ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No path found" << std::endl;
    }

    return 0;
}
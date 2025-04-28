#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>

void bfs(const std::unordered_map<char, std::vector<char>>& graph, char start) {
    std::unordered_set<char> visited;
    std::queue<char> queue;
    
    queue.push(start);
    
    while (!queue.empty()) {
        char vertex = queue.front();
        queue.pop();
        
        if (visited.find(vertex) == visited.end()) {
            std::cout << vertex << " ";
            visited.insert(vertex);
            
            // Check if vertex exists in graph
            auto it = graph.find(vertex);
            if (it != graph.end()) {
                for (char neighbor : it->second) {
                    if (visited.find(neighbor) == visited.end()) {
                        queue.push(neighbor);
                    }
                }
            }
        }
    }
}

int main() {
    // Example usage
    std::unordered_map<char, std::vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'A', 'D', 'E'}},
        {'C', {'A', 'F'}},
        {'D', {'B'}},
        {'E', {'B', 'F'}},
        {'F', {'C', 'E'}}
    };

    std::cout << "\n\nBFS traversal:" << std::endl;
    bfs(graph, 'A');
    
    return 0;
}
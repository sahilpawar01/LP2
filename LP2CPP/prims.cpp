#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

// Define edge structure for MST output
struct Edge {
    std::string from;
    std::string to;
    int weight;
    
    Edge(std::string f, std::string t, int w) : from(f), to(t), weight(w) {}
};

// Structure for priority queue
struct Node {
    std::string name;
    int cost;
    
    Node(std::string n, int c) : name(n), cost(c) {}
    
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

std::pair<int, std::vector<Edge>> prims_mst(
    const std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>& graph, 
    const std::string& start_node) {
    
    std::unordered_set<std::string> visited;
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> min_heap;
    std::unordered_map<std::string, std::string> parent;
    
    min_heap.push(Node(start_node, 0)); // (node, cost)
    int total_cost = 0;
    std::vector<Edge> mst_edges;
    
    while (!min_heap.empty()) {
        Node current = min_heap.top();
        min_heap.pop();
        
        std::string node = current.name;
        int cost = current.cost;
        
        if (visited.find(node) != visited.end()) {
            continue;
        }
        
        visited.insert(node);
        total_cost += cost;
        
        if (cost != 0) { // To avoid adding the starting node to MST edges
            mst_edges.push_back(Edge(parent[node], node, cost));
        }
        
        auto it = graph.find(node);
        if (it != graph.end()) {
            for (const auto& neighbor_info : it->second) {
                std::string neighbor = neighbor_info.first;
                int weight = neighbor_info.second;
                
                if (visited.find(neighbor) == visited.end()) {
                    min_heap.push(Node(neighbor, weight));
                    parent[neighbor] = node;
                }
            }
        }
    }
    
    return {total_cost, mst_edges};
}

int main() {
    // Example Graph (Undirected, Weighted)
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> graph = {
        {"A", {{"B", 2}, {"C", 3}}},
        {"B", {{"A", 2}, {"C", 1}, {"D", 4}}},
        {"C", {{"A", 3}, {"B", 1}, {"D", 5}}},
        {"D", {{"B", 4}, {"C", 5}}}
    };
    
    std::string start_node = "A";
    auto result = prims_mst(graph, start_node);
    int cost = result.first;
    std::vector<Edge> mst = result.second;
    
    std::cout << "Minimum Spanning Tree edges:" << std::endl;
    for (const Edge& edge : mst) {
        std::cout << edge.from << " - " << edge.to << " : " << edge.weight << std::endl;
    }
    
    std::cout << "\nTotal cost of MST: " << cost << std::endl;
    
    return 0;
}
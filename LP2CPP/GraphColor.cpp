#include <iostream>
#include <vector>
#include <unordered_map>

bool is_safe(int node, int color, const std::vector<int>& colors, 
             const std::unordered_map<int, std::vector<int>>& graph) {
    auto it = graph.find(node);
    if (it != graph.end()) {
        for (int neighbor : it->second) {
            if (colors[neighbor] == color) {
                return false;
            }
        }
    }
    return true;
}

bool graph_coloring(const std::unordered_map<int, std::vector<int>>& graph, 
                    int m_colors, std::vector<int>& colors, int node) {
    if (node == graph.size()) {
        return true;
    }
    
    for (int color = 1; color <= m_colors; ++color) {
        if (is_safe(node, color, colors, graph)) {
            colors[node] = color;
            if (graph_coloring(graph, m_colors, colors, node + 1)) {
                return true;
            }
            colors[node] = 0; // Backtrack
        }
    }
    
    return false;
}

int main() {
    // Example Graph (Undirected)
    std::unordered_map<int, std::vector<int>> graph = {
        {0, {1, 2}},
        {1, {0, 2, 3}},
        {2, {0, 1, 3}},
        {3, {1, 2}}
    };
    
    int m_colors = 3; // Number of colors
    std::vector<int> colors(graph.size(), 0);
    
    if (graph_coloring(graph, m_colors, colors, 0)) {
        std::cout << "Solution Exists: Colors assigned are" << std::endl;
        for (int i = 0; i < colors.size(); ++i) {
            std::cout << "Node " << i << ": Color " << colors[i] << std::endl;
        }
    } else {
        std::cout << "No solution exists." << std::endl;
    }
    
    return 0;
}
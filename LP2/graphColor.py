def is_safe(node, color, colors, graph):
    for neighbor in graph[node]:
        if colors[neighbor] == color:
            return False
    return True

def graph_coloring(graph, m_colors, colors, node):
    if node == len(graph):
        return True

    for color in range(1, m_colors + 1):
        if is_safe(node, color, colors, graph):
            colors[node] = color
            if graph_coloring(graph, m_colors, colors, node + 1):
                return True
            colors[node] = 0  # Backtrack

    return False

# Example Graph (Undirected)
graph = {
    0: [1, 2],
    1: [0, 2, 3],
    2: [0, 1, 3],
    3: [1, 2]
}

m_colors = 3  # Number of colors
colors = [0] * len(graph)

if graph_coloring(graph, m_colors, colors, 0):
    print("Solution Exists: Colors assigned are")
    print(colors)
else:
    print("No solution exists.")

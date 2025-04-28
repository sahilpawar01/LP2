# in dfs stack is implement or used 


def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
        
    print(start , end = ' ')    
    visited.add(start)
    
    for neighbour in graph[start]:
        if neighbour not in visited:
            dfs(graph, neighbor, visited)





graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}

print("DFS traversal:")
dfs(graph, 'A')
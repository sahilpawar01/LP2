import heapq

def prims_mst(graph, start_node):
    visited = set()
    min_heap = [(0, start_node)]  # (cost, node)
    total_cost = 0
    mst_edges = []

    while min_heap:
        cost, node = heapq.heappop(min_heap)
        if node in visited:
            continue
        visited.add(node)
        total_cost += cost

        if cost != 0:  # To avoid adding the starting node to MST edges
            mst_edges.append((parent[node], node, cost))

        for neighbor, weight in graph[node]:
            if neighbor not in visited:
                heapq.heappush(min_heap, (weight, neighbor))
                parent[neighbor] = node

    return total_cost, mst_edges

# Example Graph (Undirected, Weighted)
graph = {
    'A': [('B', 2), ('C', 3)],
    'B': [('A', 2), ('C', 1), ('D', 4)],
    'C': [('A', 3), ('B', 1), ('D', 5)],
    'D': [('B', 4), ('C', 5)]
}

parent = {}

start_node = 'A'
cost, mst = prims_mst(graph, start_node)

print("Minimum Spanning Tree edges:")
for u, v, w in mst:
    print(f"{u} - {v} : {w}")

print("\nTotal cost of MST:", cost)

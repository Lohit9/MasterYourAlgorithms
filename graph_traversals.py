# Graph DFS implementation, assuming that a graph is
# represented using an adjacency list

def dfs(graph, start):
    visited, stack, inorder = set(), [start], list()
    while stack:
        vertex = stack.pop()
        if vertex not in visited:
            visited.add(vertex)
            inorder.append(vertex)
            stack.extend(graph[vertex] - visited)
    return inorder

def bfs(graph, start):
    visited, queue, inorder = set(), [start], list()
    while queue:
        vertex = queue.pop(0)
        if vertex not in visited:
            visited.add(vertex)
            inorder.append(vertex)
            queue.extend(graph[vertex]-visited)
    return inorder


graph = {'A':set(['B','C']),
         'B':set(['A','D','E']),
         'C':set(['A','F']),
         'D':set(['B']),
         'E':set(['B','F']),
         'F':set(['C','E'])
         }

print dfs(graph, 'A')
print bfs(graph, 'A')

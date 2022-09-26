class Solution:
    def findMinHeightTrees(self, nodes: int, edges: List[List[int]]) -> List[int]:
        if nodes <= 0:
            return []

        if nodes == 1:
            return [0]
        
        adjacency = defaultdict(list)
        indegrees = defaultdict(int)
        
        for start, end in edges:
            adjacency[start].append(end)
            adjacency[end].append(start)

            indegrees[start] += 1
            indegrees[end] += 1

        leaves = deque([vertex for vertex, value in indegrees.items() if value == 1])
        while nodes > 2:
            size = len(leaves)
            nodes -= size
            for _ in range(size):
                vertex = leaves.popleft()
                for successor in adjacency[vertex]:
                    indegrees[successor] -= 1
                    if indegrees[successor] == 1:
                        leaves.append(successor)

        return leaves
        

#     O(V2), O(V), using BFS on graph, TLE
#     def findMinHeightTrees(self, nodes: int, edges: List[List[int]]) -> List[int]:
#         mht = []
#         adjacency = defaultdict(set)
#         for start, end in edges:
#             adjacency[start].add(end)
#             adjacency[end].add(start)

#         minheight = math.inf
#         for source in range(nodes):
#             visited = [False] * nodes

#             height = 0
#             visited[source] = True
#             queue = deque([source])
#             while queue:
#                 for _ in range(len(queue)):
#                     rear = queue.popleft()
#                     for successor in adjacency[rear]:
#                         if not visited[successor]:
#                             visited[successor] = True
#                             queue.append(successor)
                        
#                 height += 1
            
#             if height < minheight:
#                 minheight = height
#                 mht = [source]
#             elif height == minheight:
#                   mht.append(source)


#         return mht
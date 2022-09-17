from heapq import *


class Solution:
    '''
    shrink boundary from all 4 sides
    '''
#     O(mn), O(mn)
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        boundary = []
        visited = [[False for j in range(len(heightMap[0]))] for i in range(len(heightMap))]
        
        for i in range(len(heightMap)):
             for j in range(len(heightMap[0])):
                    if i == 0 or j == 0 or i == len(heightMap) - 1 or j == len(heightMap[0]) - 1:
                        heappush(boundary, (heightMap[i][j], (i, j)))
                        visited[i][j] = True
                
        water = 0
        min_height = 0
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        while boundary:
            smallest, (i, j) = heappop(boundary)
            min_height = max(min_height, smallest)
            
            for direction in directions:
                insidei = i + direction[0]
                insidej = j + direction[1]
                
                if insidei >= 0 and insidej >= 0 and insidei < len(heightMap) and insidej < len(heightMap[0]) and not visited[insidei][insidej]:
                    heappush(boundary, (heightMap[insidei][insidej], (insidei, insidej)))
                    visited[insidei][insidej] = True
                    
                    if heightMap[insidei][insidej] < min_height:
                        water += (min_height - heightMap[insidei][insidej])

                        
        return water
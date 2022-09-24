import math

class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        
        min_distance = math.inf
        for i in range(len(arr) - 1):
            min_distance = min(min_distance, abs(arr[i] - arr[i + 1]))
            
        return [[arr[i], arr[i + 1]] for i in range(len(arr) - 1) if min_distance == abs(arr[i] - arr[i + 1])]
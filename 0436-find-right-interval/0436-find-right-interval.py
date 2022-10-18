class Solution:
    # O(nlogn), O(n)
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        right_interval = [-1] * len(intervals)
        
        start_heap, end_heap = [], []
        for i in range(len(intervals)):
            heappush(start_heap, (-intervals[i][0], i))
            heappush(end_heap, (-intervals[i][1], i))
            
        while end_heap:
            top = heappop(end_heap)
            
            start, idx = None, None
            while start_heap and -start_heap[0][0] >= -top[0]:
                start, idx = heappop(start_heap)
            
            if idx is not None:
                right_interval[top[1]] = idx
                heappush(start_heap, (start, idx))
            
        return right_interval
        
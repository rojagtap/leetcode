class Solution:
#     O(n), O(n), but shorter
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        merged = []
        i, start, end = 0, 0, 1
        
        while i < len(intervals) and intervals[i][end] < newInterval[start]:
            merged.append(intervals[i])
            i += 1

        while i < len(intervals) and intervals[i][start] <= newInterval[end]:
            newInterval[start] = min(intervals[i][start], newInterval[start])
            newInterval[end] = max(intervals[i][end], newInterval[end])
            i += 1

        merged.append(newInterval)

        while i < len(intervals):
            merged.append(intervals[i])
            i += 1
        
        return merged

        
#     O(n), O(n)
#     def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
#         if len(intervals) == 0:
#             return [newInterval]
                    
#         l, r = 0, len(intervals) - 1
#         mid = (l + r) // 2
#         while l < r:
#             if newInterval[0] < intervals[mid][0]:
#                 r = mid
#             elif newInterval[0] > intervals[mid][0]:
#                 l = mid + 1
#             else:
#                 break
                
#             mid = (l + r) // 2
        
#         if newInterval[0] > intervals[mid][0]:
#             mid += 1

#         intervals.insert(mid, newInterval)
#         return self.merge(intervals)
        
    
#     def merge(self, intervals: List[List[int]]) -> List[List[int]]:
#         merged = []
        
#         # already sorted
#         # intervals.sort(key=lambda x: x[0])
        
#         start, end = intervals[0]
#         for i in range(1, len(intervals)):
#             interval = intervals[i]
            
#             if self.overlap(end, interval[0]):
#                 end = self.coalesce(end, interval[1])
#             else:
#                 merged.append([start, end])
#                 start, end = interval
        
#         merged.append([start, end])
#         return merged    
    
#     def coalesce(self, y1, y2):
#         return max(y1, y2)

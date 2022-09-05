"""
# Definition for an Interval.
class Interval:
    def __init__(self, start: int = None, end: int = None):
        self.start = start
        self.end = end
"""
from heapq import *


class WorkTime:
    def __init__(self, interval, employee, index):
        self.interval = interval
        self.employee = employee
        self.index = index
        
    def __lt__(self, other):
        return self.interval.start < other.interval.start


class Solution:
    def employeeFreeTime(self, schedule: '[[Interval]]') -> '[Interval]':
        # Step 1: take first of all employees in heap
        heap = []
        for i in range(len(schedule)):
            heappush(heap, WorkTime(schedule[i][0], i, 0))
            
        # Step 2: Check for free time from lowest to highest in heap and update heap
        free = []
        previous = heap[0]
        while heap:
            current = heappop(heap)
            if current.interval.start > previous.interval.end:
                free.append(Interval(previous.interval.end, current.interval.start))
        
            if current.interval.end > previous.interval.end:
                previous = current
                
            if current.index + 1 < len(schedule[current.employee]):
                heappush(heap, WorkTime(schedule[current.employee][current.index + 1], current.employee, current.index + 1))
                
        return free
                
        
#     O(nlogn), O(n)
#     def employeeFreeTime(self, schedule: '[[Interval]]') -> '[Interval]':
#         intervals = []
#         # Step 1: flatten
#         for employee in schedule:
#             for time in employee:
#                 intervals.append(time)
                
#         # Step 2: Sort
#         intervals.sort(key=lambda interval: interval.start)
        
#         # Step 3: gaps
#         free = []
#         previous = intervals[0]
#         for i in range(1, len(intervals)):
#             current = intervals[i]
            
#             if current.start > previous.end:
#                 free.append(Interval(previous.end, current.start))
                
#             if current.end > previous.end:
#                 previous = current
            
#         return free
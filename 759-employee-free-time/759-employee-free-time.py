"""
# Definition for an Interval.
class Interval:
    def __init__(self, start: int = None, end: int = None):
        self.start = start
        self.end = end
"""


class Solution:
    def employeeFreeTime(self, schedule: '[[Interval]]') -> '[Interval]':
        intervals = []
        # Step 1: flatten
        for employee in schedule:
            for time in employee:
                intervals.append(time)
                
        intervals.sort(key=lambda interval: interval.start)
        
        free = []
        previous = intervals[0]
        for i in range(1, len(intervals)):
            current = intervals[i]
            
            if current.start > previous.end:
                free.append(Interval(previous.end, current.start))
                
            if current.end > previous.end:
                previous = current
            
        return free
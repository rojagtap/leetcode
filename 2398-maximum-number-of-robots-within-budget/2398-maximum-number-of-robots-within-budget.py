from heapq import *
from collections import deque


class Solution:
    '''
    sliding window (because they have asked to return the maximum number of "consecutive" robots):
    
    Keep a running sum of runningCosts from window start to end
    For sliding window maximum see: https://leetcode.com/problems/sliding-window-maximum/
    
    Combine both techniques and calculate cost
    if cost exceeds budgets shrink window from left until it doesnt
    '''
    
#     O(n), O(r) where r is max robots within budget
#     O(n) because all the elements even though iterated thru a queue, are traversed only twice
#     def maximumRobots(self, chargeTimes: List[int], runningCosts: List[int], budget: int) -> int:
#         def update_max(i):
#             while maxtimes and chargeTimes[maxtimes[-1]] < chargeTimes[i]:
#                 maxtimes.pop()
                
#             maxtimes.append(i)
            
#         robots = 0
#         maxtimes = deque()
        
#         left = 0
#         costsum = 0
#         for right in range(len(runningCosts)):
#             costsum += runningCosts[right]
#             update_max(right)
            
#             cost = chargeTimes[maxtimes[0]] + (right - left + 1) * costsum
#             while cost > budget:
#                 costsum -= runningCosts[left]
#                 if maxtimes and maxtimes[0] == left:
#                     maxtimes.popleft()
                
#                 left += 1
#                 if left > right:
#                     break
                    
#                 cost = chargeTimes[maxtimes[0]] + (right - left + 1) * costsum
                
#             robots = max(robots, right - left + 1)
            
#         return robots
    
#     O(nlog(r)), O(r) where r is max robots within budget
    def maximumRobots(self, chargeTimes: List[int], runningCosts: List[int], budget: int) -> int:
        robots = 0
        maxtimes = []
        
        left = 0
        costsum = 0
        for right in range(len(runningCosts)):
            costsum += runningCosts[right]
            heappush(maxtimes, (-chargeTimes[right], right))
            
            cost = -maxtimes[0][0] + (right - left + 1) * costsum
            while cost > budget:
                costsum -= runningCosts[left]
                
                left += 1
                while maxtimes and maxtimes[0][1] < left:
                    heappop(maxtimes)
                
                if left > right:
                    break
                    
                cost = -maxtimes[0][0] + (right - left + 1) * costsum
                
            robots = max(robots, right - left + 1)
            
        return robots

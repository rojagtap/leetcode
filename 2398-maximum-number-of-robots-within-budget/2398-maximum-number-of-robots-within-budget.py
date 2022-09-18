from collections import deque


class Solution:
    '''
    sliding window (because they have asked to return the maximum number of "consecutive" robots):
    
    Keep a running sum of runningCosts from window start to end
    For sliding window maximum see: https://leetcode.com/problems/sliding-window-maximum/
    
    Combine both techniques and calculate cost
    if cost exceeds budgets shrink window from left until it doesnt
    '''
    
#     O(nr), O(r) where k is max robots within budget
    def maximumRobots(self, chargeTimes: List[int], runningCosts: List[int], budget: int) -> int:
        def update_max(i):
            while maxtimes and chargeTimes[maxtimes[-1]] < chargeTimes[i]:
                maxtimes.pop()
                
            maxtimes.append(i)
            
        robots = 0
        maxtimes = deque()
        
        left = 0
        costsum = 0
        for right in range(len(runningCosts)):
            costsum += runningCosts[right]
            update_max(right)
            
            cost = chargeTimes[maxtimes[0]] + (right - left + 1) * costsum
            while cost > budget:
                costsum -= runningCosts[left]
                if maxtimes and maxtimes[0] == left:
                    maxtimes.popleft()
                
                left += 1
                if left > right:
                    break
                    
                cost = chargeTimes[maxtimes[0]] + (right - left + 1) * costsum
                
            robots = max(robots, right - left + 1)
            
        return robots
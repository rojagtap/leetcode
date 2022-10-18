# class Solution:
# #     # O(n), O(n), stack, TLE
# #     def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
# #         stack = []
# #         answer = [0] * len(temperatures)
        
# #         for i in range(len(temperatures)):
# #             while stack and temperatures[i] > temperatures[stack[-1]]:
# #                 day = stack.pop()
# #                 answer[day] = i - day
                
# #             stack.append(i)
            
# #         return answer
    
#     # O(n), O(1)
#     def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
#         answer = [0] * len(temperatures)
        
#         rightmax = -inf
#         for i in range(len(temperatures) - 1, -1, -1):
#             if temperatures[i] >= rightmax:
#                 rightmax = temperatures[i]
#             else:
#                 days = 1
#                 while temperatures[i + days] <= temperatures[i]:
#                     days += answer[i + days]
                
#                 answer[i] = days
                
#         return answer
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        n, right_max = len(T), float('-inf')
        res = [0] * n
        for i in range(n-1, -1, -1):
            t = T[i]
            if right_max <= t:
                right_max = t
            else:
                days = 1
                while T[i+days] <= t:
                    days += res[i+days]
                res[i] = days
        return res

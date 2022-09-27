import math

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = math.inf
        profit = 0
        
        for price in prices:
            min_price = min(min_price, price)
            profit = max(profit, price - min_price)
        
        return profit
    
#     # O(n2), O(1)
#     def maxProfit(self, prices: List[int]) -> int:
#         profit = 0
#         for i in range(len(prices) - 1):
#             for j in range(i + 1, len(prices)):
#                 profit = max(profit, prices[j] - prices[i])
                
#         return profit
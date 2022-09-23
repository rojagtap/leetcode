class Solution:
  def numTrees(self, n: int) -> int:
    def count_trees(start, end):
      if end - start in dp:
        return dp[end - start]
      
      if end <= start:
        return 1

      count = 0
      for i in range(start, end):
        left = count_trees(start, i)
        right = count_trees(i + 1, end)
        
        count += (left * right)

      dp[end - start] = count
      return count
    
    dp = dict()
    return count_trees(1, n + 1)
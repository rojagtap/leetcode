class Solution:
    # O(n2), O(n), backtracking + memoization
    def numTrees(self, n: int) -> int:
        @cache
        def permutate(start, end):
            if start >= end:
                return 0
            elif start == end - 1:
                return 1
            
            trees = 0
            for i in range(start, end):
                left_trees = permutate(start, i) or 1
                right_trees = permutate(i + 1, end) or 1
                
                trees += (left_trees * right_trees)
                      
            return trees
        
        return permutate(1, n + 1)
                
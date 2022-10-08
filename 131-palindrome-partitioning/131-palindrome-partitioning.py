class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def palindrome(string):
            return string == string[::-1]
        
        # O(n2n), O(n), backtracking
        def backtrack(start, end):
            if start < end:
                for i in range(start + 1, end + 1):
                    sub = s[start: i]
                    if palindrome(sub):
                        partition.append(sub)
                        backtrack(i, end)
                        partition.pop()
            else:
                partitions.append(partition[:])

        partition = []
        partitions = []
        
        backtrack(0, len(s))
        
        return partitions
        
#         O(n2n), O(n), backtracking + memoization
#         @lru_cache(maxsize=None)
#         def backtrack(start, end, partition):
#             if start < end:
                
#                 partitions = []
#                 for i in range(start + 1, end + 1):
#                     sub = s[start: i]
#                     if palindrome(sub):
#                         partitions.extend(backtrack(i, end, partition + (sub,)))
                
#                 return partitions
#             else:
#                 return [list(partition)]
                         
#         return backtrack(0, len(s), ())

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def palindrome(string):
            i, j = 0, len(string) - 1
            while i < j:
                if string[i] == string[j]:
                    i += 1
                    j -= 1
                else:
                    return False
            
            return True
        
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

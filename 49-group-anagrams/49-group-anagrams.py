class Solution:
#     O(gk), g is number of groups, k is str len
#     def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
#         def is_anagram(a, b):
#             if not len(a) == len(b):
#                 return False
            
#             matches = 0
#             counts = Counter(b)
#             for c in a:
#                 if c not in counts:
#                     return False
#                 else:
#                     counts[c] -= 1
#                     if counts[c] == 0:
#                         matches += 1
            
#             return matches == len(counts)
                
#         groups = []
#         for i in range(len(strs)):
#             if strs[i] == 0:
#                 continue
            
#             group = [strs[i]]
#             for j in range(i + 1, len(strs)):
#                 if strs[j] != 0 and is_anagram(strs[i], strs[j]):
#                     group.append(strs[j])
#                     strs[j] = 0
            
#             groups.append(group)
        
#         return groups

#     O(nklogk)
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = defaultdict(list)
        for s in strs:
            groups[tuple(sorted(s))].append(s)
        
        return groups.values()
            
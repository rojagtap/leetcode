import math

class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        MOD = 1000000007
        hash = dict()
        count = 0
        
        for item in deliciousness:
            # sum can exceed the range 0 <= deliciousness[i] <= 2 ** 20
            for k in range(22):
                if (2 ** k) - item in hash:
                    count += hash[(2 ** k) - item]
            
            hash[item] = hash.get(item, 0) + 1
            
        return count % 1000000007
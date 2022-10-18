class Solution:
    # O(nn!), O(n!)
    def permute(self, nums: List[int]) -> List[List[int]]:
        def permutate(perm, nums):
            if len(nums) == 1:
                permutations.append(perm + [next(iter(nums))])
                
            for num in set(nums):
                nums.remove(num)
                perm.append(num)
                
                permutate(perm, nums)
                
                nums.add(num)
                perm.pop()
                
        permutations = []
        permutate([], set(nums))
        
        return permutations
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        setnums1 = set(nums1)
        setnums2 = set(nums2)
        
        intersection = []
        for num in setnums1:
            if num in setnums2:
                intersection.append(num)
                
        return intersection
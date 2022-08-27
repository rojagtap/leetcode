class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        count = 0
        
        freq1 = Counter(nums1)
        freq2 = Counter(nums2)
        freq3 = Counter(nums3)
        freq4 = Counter(nums4)
        
        f1plusf2 = dict()
        for f1 in freq1:
            for f2 in freq2:
                f1plusf2[f1 + f2] = f1plusf2.get(f1 + f2, 0) + (freq1[f1] * freq2[f2])
                
        f3plusf4 = dict()
        for f3 in freq3:
            for f4 in freq4:
                f3plusf4[-(f3 + f4)] = f3plusf4.get(-(f3 + f4), 0) + (freq3[f3] * freq4[f4])
                                           
        
        for f in f3plusf4:
            count += f1plusf2.get(f, 0) * f3plusf4[f]
        
        return count
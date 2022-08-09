class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        merge = []
        i = j = 0
        l1, l2 = len(nums1), len(nums2)
        total = l1 + l2
        mid = total // 2
        count = 0
        
        while i < l1 and j < l2:
            if nums1[i] <= nums2[j]:
                merge.append(nums1[i])
                i += 1
            else:
                merge.append(nums2[j])
                j += 1
                
            count += 1
            if count == (mid + 1):
                if total % 2 == 0:
                    return float((merge[-1] + merge[-2]) / 2)
                else:
                    return float(merge[-1])
                
        while i < l1:
            merge.append(nums1[i])
            i += 1
            count += 1
            if count == (mid + 1):
                if total % 2 == 0:
                    return float((merge[-1] + merge[-2]) / 2)
                else:
                    return float(merge[-1])
                
        while j < l2:
            merge.append(nums2[j])
            j += 1
            count += 1
            if count == (mid + 1):
                if total % 2 == 0:
                    return float((merge[-1] + merge[-2]) / 2)
                else:
                    return float(merge[-1])
class Solution:
    '''
    O(log(min(m, n)))
    
    
    '''
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        a, b = nums1, nums2
        m, n = len(a), len(b)
        
        if m > n:
            a, b = b, a
            m, n = n, m
        
        total = m + n
        half = total // 2
        
        l, r = 0, m - 1
                
        while True:
            mid_a = (l + r) // 2
            mid_b = half - mid_a - 2
            
            left_a = a[mid_a] if mid_a >= 0 else float("-inf")
            right_a = a[mid_a + 1] if (mid_a + 1) < m else float("inf")
            
            left_b = b[mid_b] if mid_b >= 0 else float("-inf")
            right_b = b[mid_b + 1] if (mid_b + 1) < n else float("inf")
            
            if left_a <= right_b and left_b <= right_a:
                if total & 1:
                    return min(right_a, right_b)
                else:
                    return self.median(max(left_a, left_b), min(right_a, right_b))
                
            elif left_a > right_b:
                r = mid_a - 1
            elif left_b > right_a:
                l = mid_a + 1
        
    
    def median(self, x, y):
        return (x + y) / 2.0
        
    
#     O(m + n)
#     def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
#         merge = []
#         i = j = 0
#         l1, l2 = len(nums1), len(nums2)
#         total = l1 + l2
#         mid = total // 2
#         count = 0
        
#         while i < l1 and j < l2:
#             if nums1[i] <= nums2[j]:
#                 merge.append(nums1[i])
#                 i += 1
#             else:
#                 merge.append(nums2[j])
#                 j += 1
                
#             count += 1
#             if count == (mid + 1):
#                 if total % 2 == 0:
#                     return float((merge[-1] + merge[-2]) / 2)
#                 else:
#                     return float(merge[-1])
                
#         while i < l1:
#             merge.append(nums1[i])
#             i += 1
#             count += 1
#             if count == (mid + 1):
#                 if total % 2 == 0:
#                     return float((merge[-1] + merge[-2]) / 2)
#                 else:
#                     return float(merge[-1])
                
#         while j < l2:
#             merge.append(nums2[j])
#             j += 1
#             count += 1
#             if count == (mid + 1):
#                 if total % 2 == 0:
#                     return float((merge[-1] + merge[-2]) / 2)
#                 else:
#                     return float(merge[-1])
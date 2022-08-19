class Solution:
    '''
    O(log(min(m, n)))
    
    Merging the arrays and then fetching the mid is a O(m + n) solution. But since the arrays are sorted we can do it in an even faster way using binary search.
    
    So the idea is, we don't require to merge the whole array for a median, just the mid(s)
    For this, we know that the mid will lie at the mid or (mid, mid + 1) position of the merged array, i.e., it's ok to consider only half the length of the whole merged array
    
    Now we can take the first 'n' elements from the start of the first array and consequently, 'half - n' elements from the start of the second array
    Then we check if these two subarrays actually make the correct 'first half' of the merged array. For this, we take advantage of the fact that these are sorted
    
    Let's take an example of a = [1, 2, 3, 4, 5, 6, 7, 8] and b = [3, 4, 5, 6, 7, 8]
    Now the total length is 8 + 6 = 14, so the median will be the average of the 7th and 8th element in the merged array. Thus our half array will have 7 elements
    
    So let's pick the first 4 elements from a and ofcourse,  the first 3 from b (as 7 - 4 = 3)
    So [1, 2, 3, 4] and [3, 4, 5] are the two subarrays we picked. Now we want to check if merging them actually makes up the correct first half of the merged array
    For this, 5 (from [3, 4, 5]) should be less than or equal to the next element in a (which is 5 after [1, 2, 3, 4]) and
    4 (from [1, 2, 3, 4]) should be less than or equal to the next element in b (which is 6 after [3, 4, 5])
    This concludes that all the elements in the subarrays if merged and sorted, would make the first half of merged final array
    
    Note that this holds only because the two arrays are sorted ascending
    
    Further, if the above conditions are not satisfied, we will have to adjust our subarrays (i.e., shrinking one and expanding the other) based on which condition of the above to is violated
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
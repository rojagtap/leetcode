/*
median is the middle element in the merged array

so just the first n/2 elements can give the median
but we are not concerned with all the n/2 elements, just the max 1 or 2 (in case of even)
so we split both the arrays nums1 and nums2 such that all the elements in split1 and split2 are the true elements in the left side of the median
we are not concerned with the order as the highest is enough to give the median

so we split nums1 and nums2 into left1, right1 and left2, right2
where len(left1 + left2) ~ n/2

to confirm if this is the true left side of the median in the merged array, we just need to make sure that left1[-1] < all elements of right2 and left2[-1] < all elements of right1
and since both arrays are sorted, we just need to make sure that left1[-1] < right2[0] and left2[-1] < right1[0]
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
        
        int l = 0, r = nums1.size();
        while (l <= r) {
            int mid1 = l + (r - l) / 2;
            int mid2 = ((nums1.size() + nums2.size() + 1) / 2) - mid1;
            
            int left1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
            int right1 = (mid1 < nums1.size()) ? nums1[mid1] : INT_MAX;
            
            int left2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
            int right2 = (mid2 < nums2.size()) ? nums2[mid2] : INT_MAX;

            if (left1 <= right2 && left2 <= right1) {
                if ((nums1.size() + nums2.size()) % 2 == 0) {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    return (double) max(left1, left2);
                }
            } else if (left1 > right2) {
                r = mid1 - 1;
            } else if (left2 > right1) {
                l = mid1 + 1;
            }
        }
        
        return 0.0;
    }
};
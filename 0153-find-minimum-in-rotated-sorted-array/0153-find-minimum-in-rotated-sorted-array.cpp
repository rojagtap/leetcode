/*
find the max element using binary search

ideally, in a ascending sorted array, the first element is smallest and last is largest
so in a rotated array, the first element will always be larger that the last as its left element is sent to the back
so we take a mid and adjust based on comparison with the first element
so if arr[mid] > arr[0] then we try to the right if we can find anything bigger that this
if not, we go left as the rotation point may be far left than mid
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        
        if (nums[l] <= nums[n - 1]) {
            return nums[l];
        }
        
        int maxnum = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] >= nums[0]) {
                maxnum = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return nums[maxnum + 1];
    }
};
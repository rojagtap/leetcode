/*
first find the max (last in ascending) element in the array using binary search (https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)
split the array by max
apply binary search to look for target in one of the splits based on start value
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int maxindex = get_max(nums, 0, nums.size() - 1);
        
        if (target >= nums[0]) {
            return binary_search(nums, 0, maxindex, target);
        } else {
            return binary_search(nums, maxindex + 1, nums.size() - 1, target);
        }
    }
    
private:
    int binary_search(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] < target) l = mid + 1;
            else if (nums[mid] > target) r = mid - 1;
            else return mid;
        }
        
        return -1;
    }

    int get_max(vector<int>& nums, int l, int r) {
        if (nums[0] <= nums.back()) {
            return nums.size() - 1;
        }

        int maxindex = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] >= nums[0]) {
                maxindex = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return maxindex;
    }
};
/*
similar to take/don't take
just one choice is '+' and other is '-'
*/

// backtracking
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return recurse(nums, target, 0);
    }

private:
    int recurse(vector<int>& nums, int target, int i) {
        if (i == nums.size()) {
            return target == 0;
        }
    
        // take/don't take (- or +)
        return recurse(nums, target - nums[i], i + 1) + recurse(nums, target + nums[i], i + 1);
    }
};
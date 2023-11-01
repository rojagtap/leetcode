/*
similar to take/don't take
just one choice is '+' and other is '-'
*/

// backtracking + memoization, top-down dp
// O(n * target) in time and space
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return recurse(nums, target, 0);
    }

private:
    map<pair<int, int>, int> dp;

    int recurse(vector<int>& nums, int target, int i) {
        if (i == nums.size()) {
            return target == 0;
        }
    
        if (dp.find({target, i}) != dp.end()) {
            return dp[{target, i}];
        }

        // take/don't take (- or +)
        return dp[{target, i}] = recurse(nums, target - nums[i], i + 1) + recurse(nums, target + nums[i], i + 1);
    }
};

// // backtracking, O(2^n) in time and O(n) in space (recursion stack)
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         return recurse(nums, target, 0);
//     }

// private:
//     int recurse(vector<int>& nums, int target, int i) {
//         if (i == nums.size()) {
//             return target == 0;
//         }
    
//         // take/don't take (- or +)
//         return recurse(nums, target - nums[i], i + 1) + recurse(nums, target + nums[i], i + 1);
//     }
// };
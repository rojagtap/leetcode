/*
for nums = [2,7,9,3,1]
for all i, we can either take i or i + 1 and then increment i by 2 or 3
or we can cache the max for each i where max[i] = max(max[i - 1], nums[i] + max[i - 2])
*/

// iterative
class Solution {
public:
    int rob(vector<int>& nums) {
        // easier to understand
        // for (int i = 1; i < nums.size(); ++i) {
        //     int iminus2 = i - 2 >= 0 ? nums[i - 2] : 0;
        //     nums[i] = max(nums[i - 1], iminus2 + nums[i]);
        // }

        int iminus2 = 0, iminus1 = 0, i = 0;
        for (int x = 0; x < nums.size(); ++x) {
            i = max(nums[x] + iminus2, iminus1);
            iminus2 = iminus1;
            iminus1 = i;
        }
        
        return i;
    }
};


// // recursive will give TLE as O(2^n) without caching
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         recurse(nums, 0, 0);
//         return maxcash;
//     }
// private:
//     int maxcash = 0;

//     void recurse (vector<int>& nums, int i, int cash) {
//         if (i == nums.size() - 1) {
//             maxcash = max(maxcash, cash + nums[i]);
//             return;
//         }

//         if (i >= nums.size()) {
//             maxcash = max(maxcash, cash);
//             return;
//         }

//         recurse(nums, i + 2, cash + nums[i]);
//         recurse(nums, i + 3, cash + nums[i + 1]);
//     }
// };
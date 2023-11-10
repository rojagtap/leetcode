/*
the obvious solution is (n * (n + 1) / 2) - sum(nums)
but we can also do bit manipulation

xor with self gives 0
so we can do xor of all nums and all numbers from 0 to n
all numbers will be canceled out except for the missing
*/

// xor
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            // we can also do separate but this will be faster
            missing ^= (nums[i] ^ i);
        }

        return missing;
    }
};

// // math
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int sum = 0;
//         for (auto& num : nums) {
//             sum += num;
//         }

//         return (nums.size() * (nums.size() + 1) / 2) - sum;
//     }
// };
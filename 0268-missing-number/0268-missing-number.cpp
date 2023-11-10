/*
the obvious solution is (n * (n + 1) / 2) - sum(nums)
but we can also do bit manipulation

xor with self gives 0
so we can do xor of all nums and all numbers from 0 to n
all numbers will be canceled out except for the missing
*/

// math
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (auto& num : nums) {
            sum += num;
        }

        return (nums.size() * (nums.size() + 1) / 2) - sum;
    }
};
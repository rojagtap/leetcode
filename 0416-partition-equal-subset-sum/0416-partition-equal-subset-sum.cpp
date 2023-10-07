/*
take/don't take + memoization
make sure that you also memoize false cases
i.e., if you take boolean cache and keep false as default and return only when condition is true
all the false cases will be repeated
instead, prefer taking an int cache with -1, 1 and 0
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        this->nums = nums;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        int half = sum / 2;
        this->dp = vector<vector<int>>(half + 1, vector<int>(nums.size(), -1));

        return recurse(half, 0);
    }

private:
    vector<vector<int>> dp;
    vector<int> nums;

    bool recurse(int half, int start) {
        if (start == nums.size() || half < 0) return false;
        if (half == 0) return true;
        
        if (dp[half][start] != -1) return dp[half][start];

        dp[half][start] = recurse(half - nums[start], start + 1) || recurse(half, start + 1);
        // for (int i = start; i < nums.size(); ++i) {
        //     if (recurse(half - nums[start], start + 1)) {
        //         dp[half][start] = true;
        //         return dp[half][start];
        //     } else {
        //         dp[half][start] = false;
        //     }
        // }

        return dp[half][start];
    }
};
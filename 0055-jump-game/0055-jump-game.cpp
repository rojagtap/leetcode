class Solution {
public:
    bool canJump(vector<int>& nums) {
        dp = vector<int>(nums.size(), -1);
        return recurse(nums, 0);
    }

private:
    vector<int> dp;
    bool recurse(vector<int>& nums, int idx) {        
        if (dp[idx] != -1) {
            return dp[idx];
        }

        if (idx == nums.size() - 1) {
            return true;
        }

        if (nums[idx] == 0) {
            return dp[idx] = false;
        }

        for (int i = 1; i <= nums[idx]; ++i) {
            if (idx + i < nums.size() && dp[idx + i] == -1 && recurse(nums, idx + i)) {
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }
};
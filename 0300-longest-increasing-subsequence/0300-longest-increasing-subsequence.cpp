/*
for nums = [0,1,0,3,2,3]
i = 0: 0
i = 1: 0, 1
i = 2:
decreased, search for nums[j] < nums[i]
not found, created new subsequence for j = 2
i = 3: add to both i = 0 and i = 3
0, 1, 3 and 0, 3
i = 4:
decreased, look for nums[j] < nums[i]
found: 0, 1, 2
subsequences so far:
[0, 1, 3], [0, 1, 2], [0, 3], [0, 2]
i = 5: 0, 1, 2, 3 and 0, 2, 3
subsequences so far:
[0, 1, 3], [0, 1, 2, 3], [0, 3], [0, 2, 3]

longest = [0, 1, 2, 3], length = 4

instead of having all the sequences, we can have a array containing the LIS until each i in nums
for each i find j < i such that nums[j] < nums[i] and dp[j] is max
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 1);
        dp[0] = 1;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
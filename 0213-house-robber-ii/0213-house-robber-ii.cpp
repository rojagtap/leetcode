/*
same as https://leetcode.com/problems/house-robber/
just do it once from 0 to n-1 and once from 1 to n and take max
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums.front();
        return max(robrange(nums, 0, nums.size() - 1), robrange(nums, 1, nums.size()));
    }

private:
    int robrange(vector<int>& nums, int start, int end) {
        int iminus2 = 0, iminus1 = 0, i = 0;
        for (int x = start; x < end; ++x) {
            i = max(nums[x] + iminus2, iminus1);
            iminus2 = iminus1;
            iminus1 = i;
        }
        
        return i;
    }
};
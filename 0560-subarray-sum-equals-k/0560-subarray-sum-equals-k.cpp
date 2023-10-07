/*
just like every subarray sum/product problem, we can do this very easily using sliding window/prefixsum
but the problem comes when there are -ve values

in this case, this is very similar to two-sum but here instead of individual numbers, we have to hash prefixsum
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumcount = {{0, 1}};

        int count = 0, runningsum = 0;
        for (auto& num : nums) {
            runningsum += num;
            count += sumcount[runningsum - k];
            ++sumcount[runningsum];
        }

        return count;
    }
};
class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();

        int rightmax = 0;
        vector<int> suffix(n);

        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = rightmax;
            rightmax = max(rightmax, nums[i]);
        }

        vector<int> valids;

        int leftmax = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] > leftmax || nums[i] > suffix[i]) {
                valids.push_back(nums[i]);
            }
            leftmax = max(leftmax, nums[i]);
        }

        return valids;
    }
};
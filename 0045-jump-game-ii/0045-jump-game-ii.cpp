class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int n = nums.size() - 1;

        int goal = n;
        while (goal) {
            int mingoal = INT_MAX;
            for (int i = 0; i < n; ++i) {
                if (i + nums[i] >= goal) {
                    mingoal = min(mingoal, i);
                }
            }
            goal = mingoal;
            ++jumps;
        }

        return jumps;
    }
};
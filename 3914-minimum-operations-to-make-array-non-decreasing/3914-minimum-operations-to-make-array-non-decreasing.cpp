class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n = nums.size();

        stack<int> mono;
        vector<int> leftbig(n, -1);

        for (int i = 0; i < n; ++i) {
            while (mono.size() && nums[mono.top()] < nums[i]) {
                mono.pop();
            }
            if (mono.size()) leftbig[i] = mono.top();
            mono.push(i);
        }

        long long x = 0;
        vector<long long> add(n);

        for (int i = 0; i < n; ++i) {
            add[i] = x;
            if (leftbig[i] == -1) continue;

            long long diff = (nums[leftbig[i]] + add[leftbig[i]]) - (x + nums[i]);

            if (diff <= 0) {
                continue;
            }

            x += diff;
            add[i] += diff;
        }

        return x;
    }
};
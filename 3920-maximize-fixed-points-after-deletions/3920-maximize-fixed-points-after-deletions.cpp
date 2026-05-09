class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> tuples;
        for (int i = 0; i < n; ++i) {
            if (i - nums[i] >= 0) {
                tuples.push_back({i - nums[i], nums[i]});
            }
        }

        sort(begin(tuples), end(tuples));

        vector<int> lis;

        for (auto& [diff, num] : tuples) {
            auto it = lower_bound(begin(lis), end(lis), num);

            if (it == end(lis)) {
                lis.push_back(num);
            } else {
                *it = num;
            }
        }

        return lis.size();
    }
};

// class Solution {
// public:
//     int maxFixedPoints(vector<int>& nums) {
//         cache.resize(nums.size());
//         visited.assign(nums.size(), 0);
//         return dfs(nums, 0, 0);
//     }

// private:
//     vector<bool> visited;
//     vector<unordered_map<int, int>> cache;

//     int dfs(vector<int>& nums, int i, int carry) {
//         if (i == nums.size()) {
//             return 0;
//         }

//         if (cache[i].count(carry)) {
//             return cache[i][carry];
//         }

//         int fixed = 0;

//         if (!visited[nums[i]] && i - carry >= nums[i]) {
//             visited[nums[i]] = 1;
//             fixed = max(fixed, 1 + dfs(nums, i + 1, carry + (i - carry -
//             nums[i]))); visited[nums[i]] = 0;
//         }

//         fixed = max(fixed, dfs(nums, i + 1, carry));

//         return cache[i][carry] = fixed;
//     }
// };
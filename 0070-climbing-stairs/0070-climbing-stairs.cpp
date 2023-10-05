/*
for n = 5
1   2   3   4   5
1   1   1   1   1
1   1   1   2   0
1   1   2   0   1
1   2   0   1   1
1   2   0   2   0
2   0   1   1   1
2   0   1   2   0
2   0   2   0   1

nways = nways(n - 1) + nways(n - 2)
basically, nways so far + nways of the last odd/even n

and nways(1) = 1, nways(2) = 2
*/

// iterative
class Solution {
public:
    int climbStairs(int n) {
        // vector<int> dp(n + 1);
        // dp[1] = 1;
        // dp[2] = 2;
        
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);
        dp.push_back(2);
        for (int i = 3; i <= n; ++i) {
            dp.push_back(dp[i - 1] + dp[i - 2]);
        }
        
        return dp[n];
    }
};

// // recursive
// class Solution {
// public:
//     int climbStairs(int n) {
//         if (cache.find(n) != cache.end()) return cache[n];
//         if (n == 1) return 1;
//         if (n == 2) return 2;

//         int result = climbStairs(n - 1) + climbStairs(n - 2);
//         cache[n] = result;

//         return result;
//     }

// private:
//     unordered_map<int, int> cache;
// };
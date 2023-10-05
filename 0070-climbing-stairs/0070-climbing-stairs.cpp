/*
for n = 5
1   2   3   4   5   // stair #
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
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        int iminus2 = 1;
        int iminus1 = 2;
        int nways = iminus1;
        for (int i = 3; i <= n; ++i) {
            iminus1 = nways;
            nways = iminus1 + iminus2;
            iminus2 = iminus1;
        }
        
        return nways;
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
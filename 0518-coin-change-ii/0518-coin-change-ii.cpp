/*
this is a simple take/don't take problem
*/

// bottom-up dp, translate top-down
// O(n^2 * amount) in time, and O(n * amount) in space
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));
        for (int i = 0; i < coins.size(); ++i) {
            dp[i][0] = 1;
        }

        for (int a = 1; a <= amount; ++a) {
            for (int start = 0; start < coins.size(); ++start) {
                for (int i = start; i < coins.size(); ++i) {
                    if (a - coins[i] >= 0) {
                        dp[start][a] += dp[i][a - coins[i]];
                    }
                }
            }
        }

        return dp[0][amount];
    }
};

// // backtracking + memoization, top-down dp
// // O(n^2 * amount) in time, and O(n * amount) in space + O(amount) for recursion stack
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         dp = vector<vector<int>>(coins.size(), vector<int>(amount + 1, -1));
//         return recurse(coins, amount, 0);
//     }

// private:
//     vector<vector<int>> dp;

//     int recurse(vector<int>& coins, int amount, int start) {
//         if (amount == 0) {
//             return 1;
//         }

//         if (dp[start][amount] != -1) {
//             return dp[start][amount];
//         }

//         int ways = 0;
//         for (int i = start; i < coins.size(); ++i) {
//             if (amount - coins[i] >= 0) {
//                 ways += recurse(coins, amount - coins[i], i);
//             }
//         }

//         return dp[start][amount] = ways;
//     }
// };

// // backtracking
// // O(2^n) in time and O(amount) in space for recursion stack
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         return recurse(coins, amount, 0);
//     }

// private:
//     int recurse(vector<int>& coins, int amount, int start) {
//         if (amount == 0) {
//             return 1;
//         }

//         int ways = 0;
//         for (int i = start; i < coins.size(); ++i) {
//             if (amount - coins[i] >= 0) {
//                 ways += recurse(coins, amount - coins[i], i);
//             }
//         }

//         return ways;
//     }
// };
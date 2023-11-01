/*
this is a simple take/don't take problem
*/

// approach 2: classic take/dont take

// bottom-up dp, O(n * amount) in time and space
// translate top-down
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i < coins.size() + 1; ++i) {
            dp[i][0] = 1;
        }

        for (int a = 1; a <= amount; ++a) {
            for (int i = coins.size() - 1; i >= 0; --i) {
                dp[i][a] = dp[i + 1][a] + (a - coins[i] >= 0 ? dp[i][a - coins[i]] : 0);
            }
        }

        return dp[0][amount];
    }
};

// // backtracking + memoization, top-down dp
// // O(n * amount) in time and space + O(amount) for recursion stack
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         dp = vector<vector<int>>(coins.size(), vector<int>(amount + 1, -1));
//         return recurse(coins, amount, 0);
//     }

// private:
//     vector<vector<int>> dp;

//     int recurse(vector<int>& coins, int amount, int i) {
//         if (amount == 0) {
//             return 1;
//         }

//         if (amount < 0 || i == coins.size()) {
//             return 0;
//         }

//         if (dp[i][amount] != -1) {
//             return dp[i][amount];
//         }

//         // don't take
//         int ways = recurse(coins, amount, i + 1);

//         // take
//         if (amount - coins[i] >= 0) {
//             ways += recurse(coins, amount - coins[i], i);
//         }

//         return dp[i][amount] = ways;
//     }
// };

// // backtracking
// // O(2^n) in time and O(amount) in space for recursion stack
// // here n = amount / min(coins)
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         return recurse(coins, amount, 0);
//     }

// private:
//     int recurse(vector<int>& coins, int amount, int i) {
//         if (amount == 0) {
//             return 1;
//         }

//         if (amount < 0 || i == coins.size()) {
//             return 0;
//         }

//         // don't take
//         int ways = recurse(coins, amount, i + 1);

//         // take
//         if (amount - coins[i] >= 0) {
//             ways += recurse(coins, amount - coins[i], i);
//         }

//         return ways;
//     }
// };

// approach 1: run loop from start to end for each recursion

// // bottom-up dp, translate top-down
// // O(n^2 * amount) in time, and O(n * amount) in space
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));
//         for (int i = 0; i < coins.size(); ++i) {
//             dp[i][0] = 1;
//         }

//         for (int a = 1; a <= amount; ++a) {
//             for (int start = 0; start < coins.size(); ++start) {
//                 for (int i = start; i < coins.size(); ++i) {
//                     if (a - coins[i] >= 0) {
//                         dp[start][a] += dp[i][a - coins[i]];
//                     }
//                 }
//             }
//         }

//         return dp[0][amount];
//     }
// };

// // // backtracking + memoization, top-down dp
// // // O(n^2 * amount) in time, and O(n * amount) in space + O(amount) for recursion stack
// // class Solution {
// // public:
// //     int change(int amount, vector<int>& coins) {
// //         dp = vector<vector<int>>(coins.size(), vector<int>(amount + 1, -1));
// //         return recurse(coins, amount, 0);
// //     }

// // private:
// //     vector<vector<int>> dp;

// //     int recurse(vector<int>& coins, int amount, int start) {
// //         if (amount == 0) {
// //             return 1;
// //         }

// //         if (dp[start][amount] != -1) {
// //             return dp[start][amount];
// //         }

// //         int ways = 0;
// //         for (int i = start; i < coins.size(); ++i) {
// //             if (amount - coins[i] >= 0) {
// //                 ways += recurse(coins, amount - coins[i], i);
// //             }
// //         }

// //         return dp[start][amount] = ways;
// //     }
// // };

// // // backtracking
// // // O(2^n) in time and O(amount) in space for recursion stack
// // // here n = amount / min(coins)
// // class Solution {
// // public:
// //     int change(int amount, vector<int>& coins) {
// //         return recurse(coins, amount, 0);
// //     }

// // private:
// //     int recurse(vector<int>& coins, int amount, int start) {
// //         if (amount == 0) {
// //             return 1;
// //         }

// //         int ways = 0;
// //         for (int i = start; i < coins.size(); ++i) {
// //             if (amount - coins[i] >= 0) {
// //                 ways += recurse(coins, amount - coins[i], i);
// //             }
// //         }

// //         return ways;
// //     }
// // };
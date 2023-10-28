/*
take/don't for both
if chars match, take both
if not try take one of both once

for top-down it is simple recursion with memoization

bottom up is fairly simple as well
notice that for every recursion we are going either i + 1 or j + 1 or both
so basically we will be doing a i vs j for each (i,j) pair where i is iterator for text1 and j for text2
*/

// bottom-up dp O(m x n) in time and space
class Solution {
public:
    int longestCommonSubsequence(string& text1, string& text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = text1.size() - 1; i >= 0; --i) {
            for (int j = text2.size() - 1; j >= 0; --j) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};

// // top-down with memoization O(m x n) in time and space
// // with an additional O(m + n) for recursion stack
// class Solution {
// public:
//     int longestCommonSubsequence(string& text1, string& text2) {
//         dp = vector<vector<int>>(text1.size(), vector<int>(text2.size(), -1));
//         return recurse(text1, text2, 0, 0);
//     }

// private:
//     vector<vector<int>> dp;

//     int recurse(string& text1, string& text2, int i, int j) {
//         if (i == text1.size() || j == text2.size()) {
//             return 0;
//         }

//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }

//         int length;
//         if (text1[i] == text2[j]) {
//             length = 1 + recurse(text1, text2, i + 1, j + 1);
//         } else {
//             length = max(recurse(text1, text2, i + 1, j), recurse(text1, text2, i, j + 1));
//         }

//         return dp[i][j] = length;
//     }
// };
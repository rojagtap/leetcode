/*
backtracking with take/don't take
forced take and don't take as we need to try forward as well
*/

// bottom-up dp, O(m * n) in time and space
class Solution {
public:
    int numDistinct(string& s, string& t) {
        if (s.size() < t.size()) {
            return 0;
        }

        vector<vector<unsigned long>> dp(s.size() + 1, vector<unsigned long>(t.size() + 1, 0));
        for (auto& row : dp) {
            row[t.size()] = 1;
        }

        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = t.size() - 1; j >= 0; --j) {
                if (s[i] == t[j]) {
                    dp[i][j] += dp[i + 1][j + 1];
                }

                dp[i][j] += dp[i + 1][j];
            }
        }

        return dp[0][0];
    }
};

// // backtracking + memoization, top-down dp
// // O(m * n) in time and space + O(m) space for recursion stack
// class Solution {
// public:
//     int numDistinct(string& s, string& t) {
//         if (s.size() < t.size()) {
//             return 0;
//         }

//         dp = vector<vector<int>>(s.size(), vector<int>(t.size(), -1));
//         return recurse(s, t, 0, 0);
//     }

// private:
//     vector<vector<int>> dp;
//     int recurse(string& s, string& t, int i, int j) {
//         if (j == t.size()) {
//             return 1;
//         }

//         if (i == s.size()) {
//             return 0;
//         }

//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }

//         int ways = 0;
//         if (s[i] == t[j]) {
//             ways += recurse(s, t, i + 1, j + 1);
//         }

//         ways += recurse(s, t, i + 1, j);

//         return dp[i][j] = ways;
//     }
// };

// // backtracking O(2^m) in time and O(m) in space for recursion stack
// // where m is the length of s
// class Solution {
// public:
//     int numDistinct(string& s, string& t) {
//         if (s.size() < t.size()) {
//             return 0;
//         }

//         return recurse(s, t, 0, 0);
//     }

// private:
//     int recurse(string& s, string& t, int i, int j) {
//         if (j == t.size()) {
//             return 1;
//         }

//         if (i == s.size()) {
//             return 0;
//         }

//         int ways = 0;
//         if (s[i] == t[j]) {
//             ways += recurse(s, t, i + 1, j + 1);
//         }

//         ways += recurse(s, t, i + 1, j);

//         return ways;
//     }
// };
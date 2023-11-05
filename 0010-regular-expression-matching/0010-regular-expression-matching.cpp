/*
take/don't take with the following conditions:
1. if p[j + 1] is * then
        if p[j] == s[i] or p[j] is "." then try take/don't take
3. if p[j] == s[i] or p[j] is ".", then take and move ahead

terminate if j reaches end then true if i too reaches the end else false
if i reaches end, then let j reach the end
*/

// optimized bottom-up
// we only need dp array for dp[i + 1][j], dp[i + 1][j + 1] and dp[i][j + 2]
// so basically we only need current and next row
// why not just keep that instead of entire m * n array
// O(m * n) in time, O(m) in space
// where m is p.size() and n is s.size()
class Solution {
public:
    bool isMatch(string& s, string& p) {
        vector<bool> nextdp(p.size() + 2, false);
        vector<bool> currdp(p.size() + 2, false);

        for (int i = s.size(); i >= 0; --i) {
            for (int j = p.size() + 1; j >= 0; --j) {
                if (i >= s.size() && j >= p.size()) {
                    currdp[j] = true;
                } else if (j >= p.size()) {
                    currdp[j] = false;
                } else {
                    bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');
                    if (j + 1 < p.size() && p[j + 1] == '*') {
                        currdp[j] = (match && nextdp[j]) || currdp[j + 2];
                    } else if (match) {
                        currdp[j] = nextdp[j + 1];
                    } else {
                        currdp[j] = false;
                    }
                }
            }

            nextdp = currdp;
        }

        return currdp[0];
    }
};

// // bottom-up dp
// // translate top-down
// // O(m * n) in time and space
// // where m is p.size() and n is s.size()
// class Solution {
// public:
//     bool isMatch(string& s, string& p) {
//         vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 2, false));
//         dp[s.size()][p.size()] = true;
//         dp[s.size()][p.size() + 1] = true;

//         for (int i = s.size(); i >= 0; --i) {
//             for (int j = p.size() + 1; j >= 0; --j) {
//                 if (i >= s.size() && j >= p.size()) {
//                     dp[i][j] = true;
//                 } else if (j >= p.size()) {
//                     dp[i][j] = false;
//                 } else {
//                     bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');
//                     if (j + 1 < p.size() && p[j + 1] == '*') {
//                         dp[i][j] = (match && dp[i + 1][j]) || dp[i][j + 2];
//                     } else if (match) {
//                         dp[i][j] = dp[i + 1][j + 1];
//                     } else {
//                         dp[i][j] = false;
//                     }
//                 }
//             }
//         }

//         return dp[0][0];
//     }
// };

// // backtracking + memoization, top-down dp
// // O(m * n) in time and space + O(n) space for recursion stack
// // where m is p.size() and n is s.size()
// class Solution {
// public:
//     bool isMatch(string& s, string& p) {
//         dp = vector<vector<int>>(s.size() + 1, vector<int>(p.size(), -1));
//         return match(s, p, 0, 0);
//     }

// private:
//     vector<vector<int>> dp;

//     bool match(string& s, string& p, int i, int j) {
//         if (i >= s.size() && j >= p.size()) {
//             return true;
//         } else if (j >= p.size()) {
//             return false;
//         }

//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }

//         bool charmatches = i < s.size() && (s[i] == p[j] || p[j] == '.');
//         if (j + 1 < p.size() && p[j + 1] == '*') {
//             return dp[i][j] = (charmatches && match(s, p, i + 1, j)) || match(s, p, i, j + 2);
//         } else if (charmatches) {
//             return dp[i][j] = match(s, p, i + 1, j + 1);
//         } else {
//             return dp[i][j] = false;
//         }
//     }
// };

// // backtracking, O(2^n) in time and O(n) in space for recursion stack
// // where n is s.size()
// class Solution {
// public:
//     bool isMatch(string& s, string& p) {
//         return match(s, p, 0, 0);
//     }

// private:
//     bool match(string& s, string& p, int i, int j) {
//         if (i >= s.size() && j >= p.size()) {
//             return true;
//         } else if (j >= p.size()) {
//             return false;
//         }

//         bool charmatches = i < s.size() && (s[i] == p[j] || p[j] == '.');
//         if (j + 1 < p.size() && p[j + 1] == '*') {
//             return (charmatches && match(s, p, i + 1, j)) || match(s, p, i, j + 2);
//         } else if (charmatches) {
//             return match(s, p, i + 1, j + 1);
//         } else {
//             return false;
//         }
//     }
// };
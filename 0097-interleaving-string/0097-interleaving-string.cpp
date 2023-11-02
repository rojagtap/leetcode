/*
do similar to lcs, but for both
basically try take from s1 if equal then take from s2 or else return false

in top-down case, we are typically getting the result for each (i, j, k) pair
but k = i + j, so we can condense it to (i, j) pair for memoization

in bottom up, we can simply translate the top-down approach and traverse the dp array in reverse
finally since we only need the ith and the (i + 1)th row, we can use a 1-D dp array instead
*/

// bottom-up dp with space optimization
// we only need the ith and the (i + 1)th row, not the entire dp array
// O(m * n) in time and O(n) in space
// here m is s1.size() and n is s2.size()
class Solution {
public:
    bool isInterleave(string& s1, string& s2, string& s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        vector<bool> curr(s2.size() + 1, false);
        curr[s2.size()] = true;
        vector<bool> next(s2.size() + 1, false);
        next[s2.size()] = true;

        for (int i = s1.size(); i >= 0; --i) {
            for (int j = s2.size(); j >= 0; --j) {
                if (i < s1.size() && s1[i] == s3[i + j] && next[j]) {
                    curr[j] = true;
                }
                if (j < s2.size() && s2[j] == s3[i + j] && curr[j + 1]) {
                    curr[j] = true;
                }
            }
            next = curr;
            curr = vector<bool>(s2.size() + 1, false);
        }

        return next[0];
    }
};

// // bottom-up dp
// // translate top-down
// // O(m * n) in time and space
// // here m is s1.size() and n is s2.size()
// class Solution {
// public:
//     bool isInterleave(string& s1, string& s2, string& s3) {
//         if (s1.size() + s2.size() != s3.size()) {
//             return false;
//         }

//         vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
//         dp[s1.size()][s2.size()] = true;

//         for (int i = s1.size(); i >= 0; --i) {
//             for (int j = s2.size(); j >= 0; --j) {
//                 if (i < s1.size() && s1[i] == s3[i + j] && dp[i + 1][j]) {
//                     dp[i][j] = true;
//                 }
//                 if (j < s2.size() && s2[j] == s3[i + j] && dp[i][j + 1]) {
//                     dp[i][j] = true;
//                 }
//             }
//         }

//         return dp[0][0];
//     }
// };

// // backtracking + memoization, top-down dp
// // O(m * n) in time and space + O(m + n) space for recursion stack
// // here m is s1.size() and n is s2.size()
// class Solution {
// public:
//     bool isInterleave(string& s1, string& s2, string& s3) {
//         if (s1.size() + s2.size() != s3.size()) {
//             return false;
//         }

//         dp = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, -1));
//         return subsequence(s1, s2, s3, 0, 0);
//     }

// private:
//     vector<vector<int>> dp;

//     bool subsequence(string& s1, string& s2, string& s3, int i, int j) {
//         if (i == s1.size() && j == s2.size()) {
//             return true;
//         }

//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }

//         if (i < s1.size() && s1[i] == s3[i + j] && subsequence(s1, s2, s3, i + 1, j)) {
//             return dp[i][j] = true;
//         }

//         if (j < s2.size() && s2[j] == s3[i + j] && subsequence(s1, s2, s3, i, j + 1)) {
//             return dp[i][j] = true;
//         }

//         return dp[i][j] = false;
//     }
// };

// // backtracking
// // O(2^n) in time and O(n) in space (recursion stack), TLE
// // here n is s3.size()
// class Solution {
// public:
//     bool isInterleave(string& s1, string& s2, string& s3) {
//         if (s1.size() + s2.size() != s3.size()) {
//             return false;
//         }
//         return subsequence(s1, s2, s3, 0, 0);
//     }

// private:
//     // bool subsequence(string& s1, string& s2, string& s3, int i, int j, int k) {
//     //     if (i == s1.size() && j == s2.size() && k == s3.size()) {
//     //         return true;
//     //     } else if ((i == s1.size() && j == s2.size()) || k == s3.size()) {
//     //         return false;
//     //     }

//     //     if (i < s1.size() && s1[i] == s3[k] && subsequence(s1, s2, s3, i + 1, j, k + 1)) {
//     //         return true;
//     //     }

//     //     if (j < s2.size() && s2[j] == s3[k] && subsequence(s1, s2, s3, i, j + 1, k + 1)) {
//     //         return true;
//     //     }

//     //     return false;
//     // }

//     // notice that k is always i + j
//     bool subsequence(string& s1, string& s2, string& s3, int i, int j) {
//         if (i == s1.size() && j == s2.size()) {
//             return true;
//         }

//         if (i < s1.size() && s1[i] == s3[i + j] && subsequence(s1, s2, s3, i + 1, j)) {
//             return true;
//         }

//         if (j < s2.size() && s2[j] == s3[i + j] && subsequence(s1, s2, s3, i, j + 1)) {
//             return true;
//         }

//         return false;
//     }
// };
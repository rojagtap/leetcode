/*
backtracking with take/don't take
forced take and don't take as we need to try forward as well
*/

// backtracking + memoization, top-down dp
class Solution {
public:
    int numDistinct(string& s, string& t) {
        if (s.size() < t.size()) {
            return 0;
        }

        dp = vector<vector<int>>(s.size(), vector<int>(t.size(), -1));
        return recurse(s, t, 0, 0);
    }

private:
    vector<vector<int>> dp;
    int recurse(string& s, string& t, int i, int j) {
        if (j == t.size()) {
            return 1;
        }

        if (i == s.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ways = 0;
        if (s[i] == t[j]) {
            ways += recurse(s, t, i + 1, j + 1);
        }

        ways += recurse(s, t, i + 1, j);

        return dp[i][j] = ways;
    }
};

// // backtracking O(2^m) in time and O(m) in space
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
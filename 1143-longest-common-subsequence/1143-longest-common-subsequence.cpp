/*
take/don't for both
if chars match, take both
if not try take one of both once
*/
class Solution {
public:
    int longestCommonSubsequence(string& text1, string& text2) {
        dp = vector<vector<int>>(text1.size(), vector<int>(text2.size(), -1));
        return recurse(text1, text2, 0, 0);
    }

private:
    int longest = 0;
    vector<vector<int>> dp;

    int recurse(string& text1, string& text2, int i, int j) {
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int length = 0;
        if (text1[i] == text2[j]) {
            length = 1 + recurse(text1, text2, i + 1, j + 1);
        } else {
            length = max(recurse(text1, text2, i + 1, j), recurse(text1, text2, i, j + 1));
        }

        return dp[i][j] = length;
    }
};
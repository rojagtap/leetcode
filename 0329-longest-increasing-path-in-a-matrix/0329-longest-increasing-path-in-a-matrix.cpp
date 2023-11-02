/*
dfs on each cell but visited array can be a memo
*/
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), -1));

        int longest = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                longest = max(longest, 1 + recurse(matrix, i, j));
            }
        }

        return longest;
    }

private:
    vector<vector<int>> dp;
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int recurse(vector<vector<int>>& matrix, int i, int j) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int longest = 0;
        for (auto& direction : directions) {
            int newi = i + direction.first, newj = j + direction.second;
            if (newi >= 0 && newi < matrix.size() && newj >= 0 && newj < matrix[0].size() && matrix[newi][newj] > matrix[i][j]) {
                longest = max(longest, 1 + recurse(matrix, newi, newj));
            }
        }

        return dp[i][j] = longest;
    }
};
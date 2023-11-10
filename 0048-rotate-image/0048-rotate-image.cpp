/*
to visualize this try this with a piece of paper:
1. take mirror image across principal diagonal
2. reverse columns

and mirror image across principal diagonal is transpose
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < matrix.size(); ++i) {
            // for (int j = 0; j < matrix[0].size() / 2; ++j) {
            //     swap(matrix[i][j], matrix[i][matrix[0].size() - j - 1]);
            // }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
/*
use set, O(m + n) space

for O(1) space
if any cell is 0, set the (i, 0) and (0, j) for that cell to 0
to identify if the 0th col is actually 0 and doesnt just have other cell's 0s, keep a flag
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstcol = false;
        
        // set first row and first col to 0 as marker
        for (int i = 0; i < matrix.size(); ++i) {
            if (!matrix[i][0]) firstcol = true;
            for (int j = 1; j < matrix[i].size(); ++j) {
                if (!matrix[i][j]) {                    
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // set col to 0 if 0th row has 0
        for (int j = 1; j < matrix[0].size(); ++j) {
            if (!matrix[0][j]) {
                for (int i = 0; i < matrix.size(); ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        // set row to 0 if 0th col has 0
        for (int i = 0; i < matrix.size(); ++i) {
            if (!matrix[i][0]) {
                for (int j = 1; j < matrix[i].size(); ++j) {
                    matrix[i][j] = 0;
                }
            }

            // set first col to 0 if it has a legit 0
            if (firstcol) matrix[i][0] = 0;
        }
        
    }
};
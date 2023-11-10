/*
cleaner way would be recursion

iterative is also possible
the idea is take right, down, left, and top boundaries and go on shrinking them
and traverse until spiral.size() < m x n
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        traverse(matrix, 0, 0);
        return spiral;
    }

private:
    vector<int> spiral;
    set<pair<int, int>> visited;

    void traverse(vector<vector<int>>& matrix, int i, int j) {
        visited.insert({i, j});
        spiral.push_back(matrix[i][j]);

        // for first condition try removing it and take matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
        if ((i - 1 < 0 || visited.find({i - 1, j}) != visited.end()) && j + 1 < matrix[0].size() && visited.find({i, j + 1}) == visited.end()) {
            traverse(matrix, i, j + 1);
        } else if (i + 1 < matrix.size() && visited.find({i + 1, j}) == visited.end()) {
            traverse(matrix, i + 1, j);
        } else if (j - 1 >= 0 && visited.find({i, j - 1}) == visited.end()) {
            traverse(matrix, i, j - 1);
        } else if (i - 1 >= 0 && visited.find({i - 1, j}) == visited.end()) {
            traverse(matrix, i - 1, j);
        }
    }
};
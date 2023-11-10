/*
cleaner way would be recursion
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
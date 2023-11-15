/*
simple addition based solution
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle = {{1}};
        if (numRows == 1) {
            return triangle;
        }

        triangle.push_back({1, 1});
        for (int i = 3; i < numRows + 1; ++i) {
            triangle.push_back({1});
            for (int j = 1; j < i - 1; ++j) {
                triangle.back().push_back(triangle[triangle.size() - 2][j - 1] + triangle[triangle.size() - 2][j]);
            }
            triangle.back().push_back(1);
        }

        return triangle;
    }
};
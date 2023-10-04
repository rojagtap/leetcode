/*
all the internal cells HAVE TO pass through the border cells to enter the ocean
so start dfs from borders and go reverse (i.e., go to cells with higher values)
all cells that have a path to atlantic as well as pacific ocean will go in results
*/
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        
        vector<vector<bool>> atlanticpaths(rows, vector<bool>(cols, false)), pacificpaths(rows, vector<bool>(cols, false));
        
        // first col os pacific and last col is atlantic
        for (int i = 0; i < rows; ++i) {
            dfs(heights, pacificpaths, i, 0);
            dfs(heights, atlanticpaths, i, cols - 1);
        }
        
        // first row is pacific and last row is atlantic
        for (int j = 0; j < cols; ++j) {
            dfs(heights, pacificpaths, 0, j);
            dfs(heights, atlanticpaths, rows - 1, j);
        }
        
        vector<vector<int>> result;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (pacificpaths[i][j] && atlanticpaths[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }

private:
    int rows, cols;
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    void dfs (vector<vector<int>>& grid, vector<vector<bool>>& paths, int starti, int startj) {        
        paths[starti][startj] = true;
        
        for (auto& direction : directions) {
            int newi = starti + direction.first;
            int newj = startj + direction.second;
            if (newi >= 0 && newi < rows && newj >= 0 &&  newj < cols && !paths[newi][newj] && grid[newi][newj] >= grid[starti][startj]) {
                dfs(grid, paths, newi, newj);
            }
        }
    }
};
/*
bfs on all ones
visited become 0
for each visit increment area
*/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        int maxarea = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j]) {
                    grid[i][j] = 0;
                    maxarea = max(maxarea, bfs(grid, i, j));
                }
            }
        }
        
        return maxarea;
    }

private:
    int rows, cols;
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int bfs(vector<vector<int>>& grid, int starti, int startj) {
        queue<pair<int, int>> q;
        q.push({starti, startj});
        
        int area = 0;
        while (!q.empty()) {
            ++area;

            pair<int, int> land = q.front();
            q.pop();

            for (auto& direction : directions) {
                int newi = land.first + direction.first;
                int newj = land.second + direction.second;

                if (newi >= 0 && newi < rows && newj >= 0 && newj < cols && grid[newi][newj]) {
                    q.push({newi, newj});
                    grid[newi][newj] = 0;
                }
            }
        }
        
        return area;
    }
};
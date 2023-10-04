/*
do the level order traversal of the graph
initially the level is the existing rotten oranges
from there we expand all top level oranges at once and increment the level
once all oranges are rotten we check if all are rotten and return the number of levels (minutes)
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        int rows = grid.size(), cols = grid[0].size();

        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) ++fresh;
            }
        }
        
        if (fresh == 0) return 0;

        int time = -1;
        while(!q.empty()) {
            ++time;
            int qsize = q.size();
            for (int i = 0; i < qsize; ++i) {
                pair<int, int> rotten = q.front();
                q.pop();
                for (auto& direction : directions) {
                    int newi = rotten.first + direction.first;
                    int newj = rotten.second + direction.second;

                    if (newi >= 0 && newi < rows && newj >= 0 && newj < cols && grid[newi][newj] == 1) {
                        --fresh;
                        grid[newi][newj] = 2;
                        q.push({newi, newj});
                    }
                }
            }
        }
        
        return fresh == 0 ? time : -1;
    }
};
/*
for each '1' bfs into the grid and set visited to '#'
this will ensure that this island wouldnt be traversed again
do this for all '1's

note grid[newi][newj] = '0'; this step is v v imp
basically if you place it after q.pop(),
then all the fronts will consider this element again and again as they encounter it
instead if we set it to 0 as soon as we add it to the back of the queue
the front pops will automatically ignore them as they are visited
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int islands = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    ++islands;
                    bfs(grid, i, j);
                }
            }
        }
        
        return islands;
    }
    
private:
    int rows, cols;
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    void bfs(vector<vector<char>>& grid, int starti, int startj) {
        queue<pair<int, int>> q; q.push({starti, startj});
        
        while (!q.empty()) {
            pair<int, int> land = q.front(); q.pop();
            
            for (auto& direction : directions) {
                int newi = land.first + direction.first;
                int newj = land.second + direction.second;
                
                if (newi >= 0 && newi < rows && newj >= 0 && newj < cols && grid[newi][newj] == '1') {
                    q.push({newi, newj});
                    grid[newi][newj] = '0';
                }
            }
        }
    }
};
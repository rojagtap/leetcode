/*
bfs but queue is a min-heap with top as minimum elevation from grid
*/
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int time = grid[0][0];

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // <time, i, j>
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({time, 0, 0});
        visited[0][0] = true;

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty()) {
            if (time < q.top()[0]) {
                time = q.top()[0];
            }
            while (time >= q.top()[0]) {
                int i = q.top()[1], j = q.top()[2];
                q.pop();
                
                if (i == n - 1 && j == n - 1) return time;

                for (auto& direction : directions) {
                    int newi = i + direction[0], newj = j + direction[1];
                    if (newi >= 0 && newi < n && newj >= 0 && newj < n && !visited[newi][newj]) {
                        q.push({grid[newi][newj], newi, newj});
                        visited[newi][newj] = true;
                    }
                }
            }
        }

        return time;
    }
};
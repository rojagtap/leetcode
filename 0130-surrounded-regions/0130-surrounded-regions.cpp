/*
all the Os that are not surrounded by Xs will ALWAYS be connected to a O which is at the border
so do dfs on all Os at the border and set all paths to N
all the remaining Os are surrounded
capture them and set Ns back to Os as they cannot be captured
*/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        
        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][cols - 1] == 'O') dfs(board, i, cols - 1);
        }
        
        for (int j = 0; j < cols; ++j) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[rows - 1][j] == 'O') dfs(board, rows - 1, j);
        }
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'N') board[i][j] = 'O';
            }
        }
    }
    
private:
    int rows, cols;
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs (vector<vector<char>>& board, int starti, int startj) {
        board[starti][startj] = 'N';

        for (auto& direction : directions) {
            int newi = starti + direction.first;
            int newj = startj + direction.second;
            
            if (newi >= 0 && newi < rows && newj >= 0 && newj < cols && board[newi][newj] == 'O') {
                dfs(board, newi, newj);
            }
        }
    }
};
/*
classic backtracking with dfs
stop traversing once there is mismatch
only start dfs for cells that have word[0]
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == word[0] && search(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }

private:
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool search (vector<vector<char>>& board, string& word, int& r, int& c, int wordindex) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[r].size() || board[r][c] == '#') return false;

        char backup = board[r][c];
        if (word[wordindex] != backup) return false;

        if (wordindex == word.size() - 1) return true;

        board[r][c] = '#';

        bool exists = false;
        for (auto &direction : directions) {
            int newr = r + direction.first, newc = c + direction.second;
            if (search(board, word, newr, newc, wordindex + 1)) {
                exists = true;
                break;
            }
        }

        board[r][c] = backup;

        return exists;
    }
};
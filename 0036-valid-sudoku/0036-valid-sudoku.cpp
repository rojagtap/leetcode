class Solution {
public:
    pair<int, int> getBox(const int& i, const int& j) {
        return make_pair(i / 3, j / 3);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<unordered_set<char>>> boxes(3);
        for (auto& box: boxes) {
            box = vector<unordered_set<char>>(3);
        }
        
        vector<unordered_set<char>> rowVisited(9), colVisited(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    pair<int, int> box = getBox(i, j);
                    if (
                        rowVisited[i].find(board[i][j]) != rowVisited[i].end() ||
                        colVisited[j].find(board[i][j]) != colVisited[j].end() ||
                        boxes[box.first][box.second].find(board[i][j]) != boxes[box.first][box.second].end()
                    ) {
                        return false;
                    }
                    rowVisited[i].insert(board[i][j]);
                    colVisited[j].insert(board[i][j]);
                    boxes[box.first][box.second].insert(board[i][j]);
                }
            }
        }
        
        return true;
    }
};
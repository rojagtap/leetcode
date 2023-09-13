/*
we need one set of 1-9 without repetition across
1. row
2. column
3. box

1. since we are traversing one row a time, take one set for row
2. since each column will need a lookup once per row loop, have 9 column sets
3. have a 3x3xset for box

traverse the board and if the entry is not empty,
1. check if row has already seen the number, if not, add
2. check if that column set has seen that number, if not, add
3. finally check if the box in which the cell is has already seen the number, if not, add

in this traversal, if ever there is an existing entry in row/column/box return false
if traversal was successful, return true
*/
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
        
        unordered_set<char> rowVisited;
        vector<unordered_set<char>> colVisited(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    pair<int, int> box = getBox(i, j);
                    if (
                        rowVisited.find(board[i][j]) != rowVisited.end() ||
                        colVisited[j].find(board[i][j]) != colVisited[j].end() ||
                        boxes[box.first][box.second].find(board[i][j]) != boxes[box.first][box.second].end()
                    ) {
                        return false;
                    }
                    rowVisited.insert(board[i][j]);
                    colVisited[j].insert(board[i][j]);
                    boxes[box.first][box.second].insert(board[i][j]);
                }
            }
            
            rowVisited.clear();
        }
        
        return true;
    }
};
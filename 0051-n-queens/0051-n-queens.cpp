/*
for each row, start from 0 to board.size
see which col cannot be captured from 0 to board.size try that col
recursively try the next row
note that since we want all solutions we might need to start at row > 0
so the next row needs to be (row + 1) % n
*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        int qcount = 0;
        vector<string> board(n, string(n, '.'));

        recurse(board, qcount, 0);

        return solutions;
    }

private:
    vector<vector<string>> solutions;    
    set<pair<int, int>> visitedboxes;

    bool captures (int i, int j) {
        for (auto& box : visitedboxes) {
            if (i == box.first || j == box.second || abs(box.first - i) == abs(box.second - j)) {
                return true;
            }
        }

        return false;
    }

    void recurse (vector<string>& board, int& qcount, int i) {
        if (qcount == board.size()) {
            solutions.push_back(board);
            return;
        }

        for (int j = 0; j < board.size(); ++j) {
            if (!captures(i, j)) {
                pair<int, int> index = {i, j};

                board[i][j] = 'Q';
                visitedboxes.insert(index);

                ++qcount;
                recurse(board, qcount, (i + 1) % board.size());
                --qcount;

                visitedboxes.erase(index);
                board[i][j] = '.';
            }
        }
    }
};
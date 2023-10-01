/*
use trie for words
and do dfs starting from each i, j to check if there is a startswith match
*/
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            insert(words[i], i);
        }

        unordered_set<string> visited;
        stack<tuple<int, int, TrieNode*>> traversal;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                search(board, words, trie, i, j);
            }
        }

        return matches;
    }

private:
    vector<string> matches;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  

    struct TrieNode {
        int subwordindex;
        unordered_map<char, TrieNode*> next;

        TrieNode() {
            subwordindex = -1;
        }
    } *trie = new TrieNode();

    void insert(string word, int index) {
        TrieNode *ptr = trie;
        for (auto& ch : word) {
            if (ptr->next.find(ch) == ptr->next.end()) {
                ptr->next[ch] = new TrieNode();
            }
            ptr = ptr->next.at(ch);
        }
        ptr->subwordindex = index;
    }

    void search(vector<vector<char>>& board, vector<string>& words, TrieNode* ptr, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] == '#') return;

        char backup = board[i][j];

        if (ptr->next.find(backup) == ptr->next.end()) return;
        ptr = ptr->next.at(backup);

        if (ptr->subwordindex != -1) {
            matches.push_back(words[ptr->subwordindex]);
            ptr->subwordindex = -1;
        }

        board[i][j] = '#';

        for (auto& direction : directions) {
            search(board, words, ptr, i + direction.first, j + direction.second);
        }

        board[i][j] = backup;
    }
};
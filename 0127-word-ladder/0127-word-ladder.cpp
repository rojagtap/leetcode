/*
create a map of each word in wordlist with offset 1 with the words that match
for example: Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
"_ot": ["hot", "dot", "lot"]
"h_t": ["hot"]
"ho_": ["hot"]
"d_t": ["dot"]
"do_": ["dot", "dog"]
"l_t": ["lot"]
"lo_": ["lot", "log"]
...

create a set of all words with beginWord offset 1 as it is not in wordList

finally do a level order bfs starting from endWord (must be in wordList)
traverse using the above 1 offset list
if the current word is found in the beginWord offset 1 set, then return the level
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        unordered_map<string, unordered_set<string>> onecharoffset;

        for (auto word : wordList) {
            string wordcp = word;
            for (int j = 0; j < word.size(); ++j) {
                wordcp[j] = '_';
                onecharoffset[wordcp].insert(word);
                wordcp[j] = word[j];
            }
        }

        unordered_set<string> closestbegin;
        for (int j = 0; j < beginWord.size(); ++j) {
            char backup = beginWord[j];
            beginWord[j] = '_';
            for (auto& word : onecharoffset[beginWord]) {
                closestbegin.insert(word);
            }
            beginWord[j] = backup;
        }

        queue<string> q;
        q.push(endWord);
        int distance = 1;
        unordered_set<string> visited;
        while (!q.empty()) {
            ++distance;
            int qsize = q.size();
            for (int _ = 0; _ < qsize; ++_) {
                string front = q.front();
                q.pop();

                if (closestbegin.find(front) != closestbegin.end()) {
                    return distance;
                }

                for (int j = 0; j < front.size(); ++j) {
                    char backup = front[j];
                    front[j] = '_';

                    for (auto& word : onecharoffset[front]) {
                        if (visited.find(word) == visited.end()) {
                            visited.insert(word);
                            q.push(word);
                        }
                    }

                    front[j] = backup;
                }
            }
        }

        return 0;
    }
};
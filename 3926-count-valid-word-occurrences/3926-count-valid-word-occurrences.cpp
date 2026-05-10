class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";
        for (auto chunk : chunks) {
            s += chunk;
        }

        int n = s.size();
        
        string word = "";
        unordered_map<string, int> dict;
        for (int i = 0; i < n; ++i) {
            bool sep = true;

            if (isalpha(s[i])) {
                sep = false;
            }

            if (s[i] == '-') {
                if (i > 0 && isalpha(s[i - 1]) && i < n - 1 && isalpha(s[i + 1])) {
                    sep = false;
                }
            }

            if (sep) {
                if (word.size()) {
                    ++dict[word];
                }

                word = "";
            } else {
                word += s[i];
            }
        }

        if (word.size()) {
            ++dict[word];
        }

        vector<int> counts;
        for (auto& query : queries) {
            counts.push_back(dict[query]);
        }

        return counts;
    }
};
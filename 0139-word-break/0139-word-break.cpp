/*
use trie for dictionary
traverse s from left to right and perform a word search on the trie
for each match, continue to the next words till the end
memoize the results for avoiding repetition
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        trie = new TrieNode();
        for (auto& word : wordDict) {
            addword(word);
        }

        return matches(s, 0);
    }
    
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> next;
        bool wordend;
        
        TrieNode (): wordend(false) {}
        TrieNode (char ch): wordend(false) {
            next[ch] = new TrieNode();
        }
        TrieNode (char ch, bool end): wordend(end) {
            next[ch] = new TrieNode();
        }
    } *trie;
    
    void addword(string& word) {
        TrieNode *ptr = trie;
        for (auto& ch : word) {
            if (ptr->next.find(ch) == ptr->next.end()) {
                ptr->next[ch] = new TrieNode();
            }
            ptr = ptr->next[ch];
        }
        ptr->wordend = true;
    }
    
    unordered_map<int, bool> dp;
    bool matches (string& s, int idx) {
        int i = idx;
        if (i == s.size()) {
            return true;
        }
        
        if (dp.find(idx) != dp.end()) {
            return dp[idx];
        }

        TrieNode *ptr = trie;
        while (i < s.size() && ptr->next.find(s[i]) != ptr->next.end()) {
            ptr = ptr->next[s[i]];
            ++i;
            if (ptr->wordend) {
                dp[idx] = true;
                if (matches(s, i)) {
                    return true;
                }
            }
        }

        dp[idx] = false;
        return false;
    }
};
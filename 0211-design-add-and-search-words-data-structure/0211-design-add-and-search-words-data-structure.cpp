class WordDictionary {
public:
    WordDictionary() {
        trie = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *ptr = trie;
        
        for (auto& ch : word) {
            if (ptr->next.find(ch) == ptr->next.end()) {
                ptr->next[ch] = new TrieNode();
            }
            
            ptr = ptr->next.at(ch);
        }
        
        ptr->subwordend = true;
    }
    
    bool search(string word) {
        return find(trie, word, 0);
    }
    
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> next;
        bool subwordend;
        
        TrieNode() {
            subwordend = false;
        }
    } *trie;
    
    bool find(TrieNode *ptr, string word, int curr) {
        if (curr == word.size()) return ptr->subwordend;
        
        if ((char) word[curr] == '.') {
            for (auto& entry : ptr->next) {
                if (find(entry.second, word, curr + 1)) return true;
            }
            return false;
        } else if (ptr->next.find(word[curr]) != ptr->next.end()) {
            return find(ptr->next.at(word[curr]), word, curr + 1);
        } else {
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
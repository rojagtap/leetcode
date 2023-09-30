/*
for each character's path at any given level, create a map of character vs next pointer
we can also add a char array of size 26 instead of the map, but map is more flexible

we also add a flag called subwordend to indicate that the subword was explicitly inserted
for example insert("app") and insert("apple") will have the same tree, so there is no way to tell if app was explicitly inserted
hence we keep a flag at 'l' indicating that the previous subword ended here
*/
class Trie {
public:
    Trie() {
        trie = new TreeNode();
    }
    
    void insert(string word) {
        TreeNode *ptr = trie;
        
        for (auto& ch : word) {
            if (ptr->next.find(ch) == ptr->next.end()) {
                ptr->next[ch] = new TreeNode();
            }
            ptr = ptr->next.at(ch);
        }
        
        ptr->subwordend = true;
    }
    
    bool search(string word) {
        TreeNode *ptr = trie;
        for (auto& ch : word) {
            if (ptr->next.find(ch) == ptr->next.end()) {
                return false;
            }
            ptr = ptr->next.at(ch);
        }

        return ptr->subwordend;
    }
    
    bool startsWith(string prefix) {
        TreeNode *ptr = trie;
        for (auto& ch : prefix) {
            if (ptr->next.find(ch) == ptr->next.end()) return false;
            ptr = ptr->next.at(ch);
        }

        return true;
    }
    
private:
    struct TreeNode {
        unordered_map<char, TreeNode*> next;
        bool subwordend = false;
        TreeNode () {}
    } *trie;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
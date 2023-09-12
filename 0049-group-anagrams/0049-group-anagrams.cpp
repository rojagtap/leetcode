/*
create a map of str vs list of str
for each string, sort it and use it as a key
in value list, append the original string
anagrams will be grouped. return the list of values
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (int i = 0; i < strs.size(); ++i) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (groups.find(str) == groups.end()) {
                groups[str] = vector<string>{strs[i]};
            } else {
                groups[str].push_back(strs[i]);
            }
        }
        
        vector<vector<string>> result;
        for (auto it : groups) {
            result.push_back(it.second);
        }
        
        return result;
    }
};
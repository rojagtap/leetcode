class Solution {
public:
    vector<string> getString(vector<int>& ids, vector<string>& strs) {
        vector<string> result;
        for (auto id : ids) {
            result.push_back(strs[id]);
        }
        
        return result;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp = strs;
        for (auto& str : temp) {
            sort(str.begin(), str.end());
        }
        
        unordered_map<string, vector<int>> groups;
        for (int i = 0; i < temp.size(); ++i) {
            if (groups.find(temp[i]) == groups.end()) {
                groups[temp[i]] = vector<int>{i};
            } else {
                groups[temp[i]].push_back(i);
            }
        }
        
        vector<vector<string>> result;
        for (auto it : groups) {
            result.push_back(getString(it.second, strs));
        }
        
        return result;
    }
};
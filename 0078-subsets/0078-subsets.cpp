/*
start with empty vector and add new numbers to all current subsets to make new subsets
something like
[] -> [], [1] -> [], [1], [2], [1,2] -> [], [1], [2], [1,2], [3], [1,3], [2,3], [1,2,3]

add a new number to all existing subsets at each iteration
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets = {{}};
        for (auto& num : nums) {
            int subsetssize = subsets.size();
            for (int i = 0; i < subsetssize; ++i) {
                vector<int> subseti(subsets[i].begin(), subsets[i].end());
                subseti.push_back(num);
                subsets.push_back(subseti);
            }
        }
        
        return subsets;
    }
};
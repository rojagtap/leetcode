/*
another way of solving this problem is classic backtracking
so for [1,2,3]
we start with:
[] -> [1] -> [1,2] -> [1,2,3]
then we come back and try the next available value
[] -> [1] -> [1,3]
do that again
[] -> [2] and [] -> [3]
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        generate(nums, subset, 0);
        
        return powerset;
    }
    
private:
    vector<vector<int>> powerset;
    
    void generate(vector<int>& nums, vector<int>& subset, int numsindex) {
        powerset.push_back(subset);
        if (numsindex == nums.size()) return;
        
        for (int i = numsindex; i < nums.size(); ++i) {
            subset.push_back(nums[i]);
            generate(nums, subset, i + 1);
            subset.pop_back();
        }
    }
};

// /*
// start with empty vector and add new numbers to all current subsets to make new subsets
// something like
// [] -> [], [1] -> [], [1], [2], [1,2] -> [], [1], [2], [1,2], [3], [1,3], [2,3], [1,2,3]

// add a new number to all existing subsets at each iteration
// */
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> subsets = {{}};
//         for (auto& num : nums) {
//             int subsetssize = subsets.size();
//             for (int i = 0; i < subsetssize; ++i) {
//                 vector<int> subseti(subsets[i].begin(), subsets[i].end());
//                 subseti.push_back(num);
//                 subsets.push_back(subseti);
//             }
//         }
        
//         return subsets;
//     }
// };
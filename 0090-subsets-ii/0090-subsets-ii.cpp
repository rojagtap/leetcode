/*
this too, just like https://leetcode.com/problems/subsets/, can be solved using a classic backtracking approach

at each level try adding the next element from nums to the subset
at the same level, if the element is same as the previous, skip as it will give the same result
so for [1,2,2] we do
[] -> [1] -> [1,2] -> [1,2,2]
then we come back and try the next available number
[] -> [2] -> [2,2] (notice that after [1] we can again generate [1,2] with the third 2 but we skip that as they are at the same level in the tree)
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> subset;
        recurse (nums, subset, 0);
        
        return subsets;
    }

private:
    vector<vector<int>> subsets;

    void recurse (vector<int>& nums, vector<int>& subset, int numsindex) {
        subsets.push_back(subset);
        
        if (numsindex == nums.size()) return;
        
        for (int i = numsindex; i < nums.size(); ++i) {
            if (i == numsindex || nums[i] != nums[i - 1]) {
                subset.push_back(nums[i]);
                recurse (nums, subset, i + 1);
                subset.pop_back();
            }
        }
    }
};

// /*
// []
// [],[1]
// [],[1],[2],[1,2]
// [],[1],[2],[1,2],[2,2],[1,2,2] 
// only add to the subsets generated by the last element if there is a duplicate
// for this, keep track of where the last one ended (prev subsetsize), this will be the current start
// */
// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
        
//         int subsetsize = 0;
//         vector<vector<int>> subsets = {{}};
//         for (int i = 0; i < nums.size(); ++i) {
//             int j = i > 0 && nums[i] == nums[i - 1] ? subsetsize : 0;
//             subsetsize = subsets.size();
//             for (; j < subsetsize; ++j) {
//                 vector<int> subsetj (subsets[j].begin(), subsets[j].end());
//                 subsetj.push_back(nums[i]);
//                 subsets.push_back(subsetj);
//             }
//         }
        
//         return subsets;
//     }
// };
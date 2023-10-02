/*
similar to https://leetcode.com/problems/permutations/
take a pivot for each position and try all the elements at that position
just in this case, at the same position (recursion level), skip the try if the ith element is already seen at that level, this will lead to the same permutation again
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        recurse (nums, 0);
        return permutations;
    }
    
private:
    vector<vector<int>> permutations;
    
    void recurse (vector<int>& nums, int startindex) {
        if (startindex == nums.size()) {
            permutations.push_back(nums);
            return;
        }
        
        unordered_set<int> visited;
        for (int i = startindex; i < nums.size(); ++i) {
            if (visited.find(nums[i]) == visited.end()) {
                visited.insert(nums[i]);
                swap(nums[i], nums[startindex]);
                recurse (nums, startindex + 1);
                swap(nums[i], nums[startindex]);
            }
        }
    }
};
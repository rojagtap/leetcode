class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> numset (nums.begin(), nums.end());
        
        vector<int> permutation;
        recurse (numset, permutation);
        return permutations;
    }

private:
    vector<vector<int>> permutations;
    
    void recurse (unordered_set<int>& nums, vector<int>& permutation) {
        if (nums.size() == 0) {
            permutations.push_back(vector<int>(permutation.begin(), permutation.end()));
            return;
        }
        
        unordered_set<int> numscopy(nums.begin(), nums.end());
        for (auto num : numscopy) {
            nums.erase(num);
            permutation.push_back(num);
            
            recurse (nums, permutation);
            
            permutation.pop_back();
            nums.insert(num);
        }
    }
};
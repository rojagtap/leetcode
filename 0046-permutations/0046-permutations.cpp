/*
each perm will be of size nums.size()
so at each position from 0 to nums.size() we try each of the element from nums once

one way to do that is to
take nums as a set of available elements
iterate all nums one by one
in each iteration remove that element from nums and insert it to perm
now we can recursively iterate through the remaining of nums to try various orders on remaining length of perm
see code for better understanding
*/
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
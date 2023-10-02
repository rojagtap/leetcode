/*
another way to solve this is to take a pivot for each position and try all the elements at that position
recursively do this for each position
so first we will try all for last position
then second to last and so on...

see the code for better understanding
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
        
        for (int i = startindex; i < nums.size(); ++i) {
            swap(nums[i], nums[startindex]);
            recurse (nums, startindex + 1);
            swap(nums[i], nums[startindex]);
        }
    }

};

// /*
// each perm will be of size nums.size()
// so at each position from 0 to nums.size() we try each of the element from nums once

// one way to do that is to
// take nums as a set of available elements
// iterate all nums one by one
// in each iteration remove that element from nums and insert it to perm
// now we can recursively iterate through the remaining of nums to try various orders on remaining length of perm
// see code for better understanding
// */
// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         unordered_set<int> numset (nums.begin(), nums.end());
        
//         vector<int> permutation;
//         recurse (numset, permutation);
//         return permutations;
//     }

// private:
//     vector<vector<int>> permutations;
    
//     void recurse (unordered_set<int>& nums, vector<int>& permutation) {
//         if (nums.size() == 0) {
//             permutations.push_back(vector<int>(permutation.begin(), permutation.end()));
//             return;
//         }
        
//         unordered_set<int> numscopy(nums.begin(), nums.end());
//         for (auto num : numscopy) {
//             nums.erase(num);
//             permutation.push_back(num);
            
//             recurse (nums, permutation);
            
//             permutation.pop_back();
//             nums.insert(num);
//         }
//     }
// };
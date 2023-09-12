/*
create a reverse map of num -> index
num1 + numx = target is the condition
so num1 = target - numx
therefore if target - numx is in the map,
then we can return the current index and numx's index
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> reverse;
        for (int i = 0; i < nums.size(); ++i) {
            if (reverse.find(target - nums[i]) == reverse.end()) {
                reverse[nums[i]] = i;
            } else {
                return vector<int>{reverse[target - nums[i]], i};
            }
        }
        
        return vector<int>();
    }
};
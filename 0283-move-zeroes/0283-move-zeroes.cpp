/*
it is easier if r starts from l + 1, that way the 0 always moves forward
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, r = 0;
        
        while (l < nums.size() && nums[l]) ++l;
        if (l == nums.size()) return;
        
        for (r = l; r < nums.size(); ++r) {
            if (nums[r]) {
                swap(nums[l++], nums[r]);
            }
        }
    }
};
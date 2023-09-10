/*
insert all elements in set
compare set and list size
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> unique;
        for (auto num : nums) {
            unique.insert(num);
        }

        return nums.size() != unique.size();
    }
};
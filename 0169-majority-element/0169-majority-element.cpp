/*
the idea here is to keep a running count which increments if we see the current element and decrements if we dont
if count comes to 0, we take the current mismatch

the reason this works is:
1. the count of the majority element can never be 0 as it appears MORE than n / 2 times
2. it is guaranteed to come across this element and not miss it as all the other elements are guaranteed to get a 0 count and the majority element even if is missed during all (count == 0) mismatches, will be there at the last mismatch (well, because it appears n / 2 times)

this is O(n) in time and O(1) in space
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr = nums[0], count = 0;

        for (auto& num : nums) {
            count += (curr == num) - (curr != num);
            if (count == 0) {
                count = 1;
                curr = num;
            }
        }

        return curr;
    }
};
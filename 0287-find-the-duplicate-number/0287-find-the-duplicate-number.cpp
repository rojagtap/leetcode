/*
if O(n) space is allowed, use hash
if modifying array is allowed, use visited flags -1
if nothing is allowed use floyds

the idea is
first given that numbers from 1-n are fitted in array of size n + 1, it is guaranteed that at least 1 is repeated
if we use elements as index numbers to other elements, then there will be two elements that point to the same index as there is a repetition, hence, cycle.
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        slow = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
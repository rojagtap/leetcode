/*
this can be done with xor
xor gives 1 only if one value is 0 and the other is 1 (both different, exclusively or)
so if we xor one number with itself, it is guaranteed to give 0
so all duplicate numbers will cancel out and the single number will remain if we xor in loop
about overwriting values:
for example, a = 6 (00110), b = 22 (10110)
c = a ^ b = 10000 (16)
then a ^ c = 10110
so xorring 6 twice cancelled out 6 from the result
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int unique = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            unique ^= nums[i];
        }

        return unique;
    }
};
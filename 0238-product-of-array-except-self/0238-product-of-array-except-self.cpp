/*
for any position, the result is
(product of elements in the left) * (product of elements to the right)
so we take two arrays prefix and postfix where
prefix will have the running product of all the elements in the left for each position
and postfix will have a product of all the elements in the right for each position
and the return array will be just a point wise multiplication of prefix and postfix
this is O(n) in space and O(n) in time

Can you solve the problem in O(1) extra space complexity?
(The output array does not count as extra space for space complexity analysis.)
The way to do this would be to do prefix and postfix in two passes
in the first pass, we do a prefix product directly in the return array
and in the second pass, we directly multiply the postfix with the existing prefix in the return array and overwrite the value.
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix = prefix * nums[i];
        }
                
        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] = result[i] * postfix;
            postfix = postfix * nums[i];
        }
        
        return result;
    }
};

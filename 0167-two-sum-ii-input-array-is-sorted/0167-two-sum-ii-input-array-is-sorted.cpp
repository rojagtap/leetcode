/*
take a left index and right index
since array is sorted,
if left goes forward, the sum will increase
if right come back, the sum will decrease
hence if sum < target, we move left ahead
if sum > target, we move right backward
if it equals, we return the indices
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum < target) {
                ++l;
            } else if (sum > target) {
                --r;
            } else {
                return vector<int>{l + 1, r + 1};
            }
        }
        
        return vector<int>{};
    }
};
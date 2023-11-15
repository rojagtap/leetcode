/*
take 2 pointers left and right
everything before left will be 0
everything after right will be 2
and everything in between is 1

so traverse with an additional iterator such that
if value at i is 2 then swap with right and move right inside
if value at i is 1, just move ahead
and if value is 0 then swap with left and move left inside

for example: nums = [0,0,1,2,0,1,2]
    0, 0, 1, 2, 0, 1, 2
   l,i                r
    0, 0, 1, 2, 0, 1, 2
      l,i             r
    0, 0, 1, 2, 0, 1, 2
         l,i          r
    0, 0, 1, 2, 0, 1, 2
          l  i        r
    0, 0, 1, 2, 0, 1, 2
          l  i     r
    0, 0, 1, 1, 0, 2, 2
          l  i  r
    0, 0, 1, 1, 0, 2, 2
          l    i,r
    0, 0, 0, 1, 1, 2, 2
             l  r  i
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, i = 0;

        while (i <= right) {
            switch(nums[i]) {
                case 0:
                    swap(nums[left++], nums[i++]);
                    break;
                case 1:
                    ++i;
                    break;
                case 2:
                    swap(nums[i], nums[right--]);
                    break;
            }
        }
    }
};
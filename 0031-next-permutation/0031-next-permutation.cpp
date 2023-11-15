/*
the bruteforce approach here is to generate all the permutations (using backtracking)
for the sorted array and match it with the current sequence. The next permutation will be the answer
this will be O(n * n!) in time (n for matching and n! different permutations for each sequence)
need a better approach

to rephrase the question, what we want is given a number with digits in the array,
get the smallest number greater than the current number which can be formed using the same digitis
for example: nums = [1,5,2,3]
then we want nums = [1,5,3,2]
if you observe closely, we got this just by swapping the last two (units and tens places)

now think about nums = [1,5,3,2]
this time we want nums = [2,1,3,5]
we cannot do anymore swapping with units and tens places as this will bring down to the smaller number
so we consider the hundreds place
see that if we swap any number with this, it will always lead to a smaller number (because 5 is the greatest in the array)
so we move on to the thousands place
here, if we swap the one with the next smallest digit in the array (which is 2) and construct the smallest number from the rest of the array, then we have our answer

similarly, for nums = [2,1,5,4,3,0,0]
we want nums = [2,3,0,0,1,4,5]
if you calculate, we have to go until 1 and then do the swapping

so all in all, we see that as long as the ith place number is >= (i + 1)st place, swapping cannot happen and we need to go back and consider more digits
once we reach a point where swapping can happen, we need to take the next smallest digit after ith and swap it
and finally we can obtain the smallest number now by simply reversing the digits from i + 1 till n as they will be always in descending order (see by observation how it makes sense)
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while (i > 0 && nums[i] <= nums[i - 1]) {
            --i;
        }

        if (i) {
            int j = nums.size() - 1;
            while (j >= i && nums[j] <= nums[i - 1]) {
                --j;
            }
            swap(nums[i - 1], nums[j]);
        }

        reverse(nums.begin() + i, nums.end());
    }
};
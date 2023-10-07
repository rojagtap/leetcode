/*
ideally the max product subarray will be the entire array's product
but the problem comes when there are negative values and zeros
so for nums = [2,3,-2,4]
we can take the running product and when the value turns negative, nums[i] will be > running product:
so running product will look like this: 2, 6, -12
so at i = 2, -2 > -12 so we take -2 as the new running product
similarly, at i = 3, runningprod = -8 which is < nums[i] = 4
so overall max product is 6

but there is a problem here
for nums = [2,3,-2,-4] the above solution fails
runningprod = 2, 6, -2, 8
the above approach will output 8 but the actual answer should be 2, 6, -12, 48 (since the -ves cancel)
but our solution discards the running product on -ves
instead, we can keep a runningmax and runningmin (i.e., on a single -ve value, runningmax becomes the min)
and now the comparison wont be between max(nums[i], runningprod)
instead it will be max(nums[i], runningmax, runningmin). this way we are also preserving the -12 in the above example
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = INT_MIN, runningmax = 1, runningmin = 1;
        for (auto& num : nums) {
            int temp = runningmax * num;
            runningmax = max({num, temp, runningmin * num});
            runningmin = min({num, temp, runningmin * num});
            maxprod = max(maxprod, runningmax);
        }

        return maxprod;
    }
};
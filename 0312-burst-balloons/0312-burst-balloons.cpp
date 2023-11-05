/*
why take/don't take doesn't work?
in this problem, to implement take/don't take, we will start from 0 and either burst the balloon or won't burst and move ahead.
the issue with this is if we don't burst the balloon and move ahead, it will NEVER be burst. That is, in this problem, we want
to try various ORDERS of bursting balloons and not decide whether or not bursting a balloon will give us a solution. in the end
of the day, we want ALL the balloons to be burst and this cannot be done with take/don't take

the naive approach here is to iterate over all balloons, burst one, and move to the next level in the recursion tree.
there we will have the left side of the burst balloon and the right side of it. then try bursting each side once and taking
each of the opposite side's ballon as the outer left and right and continue this recursion
for example: for nums = [3,1,5,8],
let's say we go to i = 2, nums[2] = 5
here after bursting 5, we have a few options:
1. iterate over [3, 1] with 8 as the right end
2. iterate over [3, 1] with 1 as the right end (index 4 + 1 exceeds the array, so we take 1 as the value)
3. burst 8 with 3 as its left
4. burst 8 with 1 as its left

and we do this recursively for everything
this will be O(n^2n) in time and O(n) in space

we can try memoizing this, but the issue is,
for any subarray (like [8] in the above example), we have to try every element in the other subarray as its left bound
so this is not really a "subproblem" that we can cache

so we can think in a different sense:
here the biggest issue is we cannot just take one value from the array and then get the optimal solution recursively for left and right subarrays because the left and right subarrays are dependent on each other for the right/left bounds respectively
so instead of BURSTING each balloon iteratively and then going left and right for obtaining the optimal solution for that balloon, why don't we RETAIN that balloon and go left and right to obtain the optimal solution such that this balloon is burst LAST
for example: for nums = [3,1,5,8],
in this case, if we go to i = 2, nums[2] = 5, it means we will burst 5 in the end this time
then we have the left subarray [3, 1] and the right subarray [8]
the advantage of this approach is, whatever we do in the subarrays is independent of each other, since the right bound of [3, 1] is 5 and the left bound of [8] is 5
so they can operate independent of each other
similarly we can go over [3, 1] iteratively RETAINING each of them first once
*/

// bottom-up dp, O(n^3) in time and O(n^2) in space
// the translation is a bit tricky here
// we start from the end of nums as in any bottom-up solution
// we want to start with leftbound = n and rightbound = n, i.e., the independent value of nums[leftbound (or rightbound)] (basically the value if it is left alone)
// now next, we get the value of n - 1 (independent)
// and we use both these values (n - 1) and n to get the optimal value for leftbound = n - 1 and rightbound = n
// we repeat this for leftbound = n - 2 and rightbound = n, leftbound = n - 3 and rightbound = n, ..., leftbound = 0 and rightbound = n
// this is the final value that we are looking for (optimal value for leftbound = 0 and rightbound = n)
// there is still one catch here
// based on the above description, one might think of iterating leftbound from n to 0 and fixing the rightbound to n
// running a loop for i from leftbound to rightbound and doing the calculation
// but this is not correct
// in this implementation we will only calculate values for [leftbound, n], however we also need values for [leftbound, leftbound <= rightbound <= n], those intermediate optimal values for subarrays is lost. hence we need to iterate 3 nested loops:
// one that iterates the leftbound
// one that iterates the rightbound (from leftbound to n)
// and the individual element loop running from leftbound to rightbound
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int leftbound = n; leftbound >= 1; --leftbound) {
            for (int rightbound = leftbound; rightbound <= n; ++rightbound) {
                int coins = 0;
                for (int i = leftbound; i <= rightbound; ++i) {
                    coins = max(coins, dp[leftbound][i - 1] + nums[leftbound - 1] * nums[i] * nums[rightbound + 1] + dp[i + 1][rightbound]);
                }

                dp[leftbound][rightbound] = coins;
            }
        }

        return dp[1][n];
    }
};

// // backtracking + memoization
// // now since the left and right subarrays are independent
// // we can simply cache the left and right bounds of the current subarray as the result will be always unique
// // O(n^3) in time and O(n^2) in space + O(n) recursion stack
// class Solution {
// public:
//     int maxCoins(vector<int>& nums) {
//         dp = vector<vector<int>>(nums.size(), vector<int>(nums.size(), -1));
//         return recurse(nums, 0, nums.size() - 1);
//     }

// private:
//     vector<vector<int>> dp;

//     int recurse(vector<int>& nums, int leftbound, int rightbound) {
//         if (leftbound > rightbound) {
//             return 0;
//         }

//         if (dp[leftbound][rightbound] != -1) {
//             return dp[leftbound][rightbound];
//         }

//         int coins = 0;
//         for (int i = leftbound; i <= rightbound; ++i) {
//             int prev = (leftbound - 1 < 0) ? 1 : nums[leftbound - 1];
//             int next = (rightbound + 1 >= nums.size()) ? 1 : nums[rightbound + 1];
//             coins = max(coins, recurse(nums, leftbound, i - 1) + prev * nums[i] * next + recurse(nums, i + 1, rightbound));
//         }

//         return dp[leftbound][rightbound] = coins;
//     }
// };

// // backtracking
// // in this, similar to the naive approach we are traversing the array at each level
// // the only difference is we don't have to do it with each element in the right subarray which made it n^2
// // hence this is O(n^n) in time and O(n) in space, TLE
// class Solution {
// public:
//     int maxCoins(vector<int>& nums) {
//         return recurse(nums, 0, nums.size() - 1);
//     }

// private:
//     int recurse(vector<int>& nums, int left, int right) {
//         if (left > right) {
//             return 0;
//         }

//         int coins = 0;
//         for (int i = left; i <= right; ++i) {
//             int prev = (left - 1 < 0) ? 1 : nums[left - 1];
//             int next = (right + 1 >= nums.size()) ? 1 : nums[right + 1];
//             coins = max(coins, recurse(nums, left, i - 1) + prev * nums[i] * next + recurse(nums, i + 1, right));
//         }

//         return coins;
//     }
// };
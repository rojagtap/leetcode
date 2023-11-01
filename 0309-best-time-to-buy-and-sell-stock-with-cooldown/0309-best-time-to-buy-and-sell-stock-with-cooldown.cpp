/*
take/don't take with cooldown
here the sub-problem is given a day (index),
what is the maximum profit that can be gained either by buy/hold or sell/hold at that day
hence we memoize the 2 choices buy/sell and the max profit earned by that choice
Note that it is a very obvious choice to also send the current profit and
pass on -price + profit for buy and price + profit for sell and just profit for hold for all function calls
however, this doesn't work as this does not repeat. i.e., the same profit for a given buy/sell choice for an index won't repeat, only the buy/sell + index will. so we want to just obtain the profit of the function independent of the previous gain
*/

// backtracking + memoization, top-down dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        dp = vector<vector<int>>(2, vector<int>(prices.size(), INT_MIN));
        return recurse(prices, 0, true);
    }

private:
    vector<vector<int>> dp;
    int recurse(vector<int>& prices, int i, bool canbuy) {
        if (i >= prices.size()) {
            return 0;
        }
        
        if (dp[canbuy][i] != INT_MIN) {
            return dp[canbuy][i];
        }

        if (canbuy) {
            return dp[canbuy][i] = max(
                -prices[i] + recurse(prices, i + 1, false),
                recurse(prices, i + 1, true)
            );
        } else {
            return dp[canbuy][i] = max(
                prices[i] + recurse(prices, i + 2, true),
                recurse(prices, i + 1, false)
            );
        }
    }
};

// // naive backtracking, O(2^n) in time and O(n) in space (recursion stack), TLE
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         return recurse(prices, 0, true);
//     }

// private:
//     int recurse(vector<int>& prices, int i, bool canbuy) {
//         if (i >= prices.size()) {
//             return 0;
//         }

//         if (canbuy) {
//             return max(
//                 -prices[i] + recurse(prices, i + 1, false),
//                 recurse(prices, i + 1, true)
//             );
//         } else {
//             return max(
//                 prices[i] + recurse(prices, i + 2, true),
//                 recurse(prices, i + 1, false)
//             );
//         }
//     }
// };
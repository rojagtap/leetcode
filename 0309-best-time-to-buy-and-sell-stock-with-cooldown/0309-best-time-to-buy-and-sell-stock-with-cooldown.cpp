/*
take/don't take with cooldown

here the sub-problem is given a day (index),
what is the maximum profit that can be gained either by buy/hold or sell/hold at that day
hence we memoize the 2 choices buy/sell and the max profit earned by that choice

Note that it is a very obvious choice to also send the current profit and
pass on -price + profit for buy and price + profit for sell and just profit for hold for all function calls
however, this doesn't work as this does not repeat. i.e., the same profit for a given buy/sell choice for an index won't repeat, only the buy/sell + index will. so we want to just obtain the profit of the function independent of the previous gain
*/

// bottom-up dp, but we can skip the array
// as we only need 2 further values not the entire array
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // we just need these from the dp array
        int buyplus1 = 0, buyplus2 = 0, sellplus1 = 0;

        for (int i = prices.size() - 1; i >= 0; --i) {
            // easier to read
            // int sellprofit = max(prices[i] + buyplus2, sellplus1);
            // int buyprofit = max(-prices[i] + sellplus1, buyplus1);

            // buyplus2 = buyplus1;
            // buyplus1 = buyprofit;
            // sellplus1 = sellprofit;

            int temp = buyplus1;
            buyplus1 = max(-prices[i] + sellplus1, buyplus1);
            sellplus1 = max(prices[i] + buyplus2, sellplus1);
            buyplus2 = temp;
        }

        return buyplus1;
    }
};

// // bottom-up dp, just translate top-down to table 
// // O(n) in time and space
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         vector<vector<int>> dp(2, vector<int>(prices.size() + 2, 0));

//         for (int i = prices.size() - 1; i >= 0; --i) {
//             dp[0][i] = max(prices[i] + dp[1][i + 2], dp[0][i + 1]);
//             dp[1][i] = max(-prices[i] + dp[0][i + 1], dp[1][i + 1]);
//         }

//         return dp[1][0];
//     }
// };

// // backtracking + memoization, top-down dp
// // O(n) in time and space (2*n)
// // + O(n) recursion stack space
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         dp = vector<vector<int>>(2, vector<int>(prices.size(), INT_MIN));
//         return recurse(prices, 0, true);
//     }

// private:
//     vector<vector<int>> dp;
//     int recurse(vector<int>& prices, int i, bool canbuy) {
//         if (i >= prices.size()) {
//             return 0;
//         }
        
//         if (dp[canbuy][i] != INT_MIN) {
//             return dp[canbuy][i];
//         }

//         if (canbuy) {
//             return dp[canbuy][i] = max(
//                 -prices[i] + recurse(prices, i + 1, false),
//                 recurse(prices, i + 1, true)
//             );
//         } else {
//             return dp[canbuy][i] = max(
//                 prices[i] + recurse(prices, i + 2, true),
//                 recurse(prices, i + 1, false)
//             );
//         }
//     }
// };

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
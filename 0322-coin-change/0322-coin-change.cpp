/*
the recurrence relation here is a bit tricky
it is with respect to the amount
for example, coins = [1,2,5], amount = 11
amount = 1, count = 1
amount = 2, count = 1
amount = 3, count = 2
amount = 4, count = 2
amount = 5, count = 1
amount = 6, count = 2
amount = 7, count = 2
amount = 8, count = 3
amount = 9, count = 3
amount = 10, count = 2
amount = 11, count = 3

so basically dp[amount] = 1 + min(dp[amount - 1], dp[amount - 2], dp[amount - 5])
i.e., if amount - c is seen already then use its minvalue + 1
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int a = 1; a <= amount; ++a) {
            for (auto& coin : coins) {
                if (a - coin >= 0) {
                    dp[a] = min(dp[a], 1 + dp[a - coin]);
                }
            }
        }

        return dp.back() == amount + 1 ? -1 : dp.back();
    }
};
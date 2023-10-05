/*
for cost = [1,100,1,1,1,100,1,1,100,1]
greedy:
min(1, 100) = 1     => i = 0
min(100, 1) = 1     => i = 2
min(1, 1)   = 1     => i = 4
min(100, 1) = 1     => i = 6
min(1, 100) = 1     => i = 7
min(100, 1) = 1     => i = 8
total       = 6

but for cost = [10,15,20]
greedy wont work as it will always pick 10 and then go to 10 + 15

instead since we can either jump one step or two step,
we can do cost[i] = cost[i] + min(cost[i - 2], cost[i - 1])
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for (int i = 2; i < n; ++i) {
            cost[i] += min(cost[i - 2], cost[i - 1]);
        }
        
        return min(cost[n - 2], cost[n - 1]);
    }
};
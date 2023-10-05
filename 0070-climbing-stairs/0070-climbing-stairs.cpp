/*
for n = 5
1   2   3   4   5
1   1   1   1   1
1   1   1   2   0
1   1   2   0   1
1   2   0   1   1
1   2   0   2   0
2   0   1   1   1
2   0   1   2   0
2   0   2   0   1

nways = nways(n - 1) + nways(n - 2)
basically, nways so far + nways of the last odd/even n

and nways(1) = 1, nways(2) = 2
*/

// using recursion
class Solution {
public:
    int climbStairs(int n) {
        if (cache.find(n) != cache.end()) return cache[n];
        if (n == 1) return 1;
        if (n == 2) return 2;

        int result = climbStairs(n - 1) + climbStairs(n - 2);
        cache[n] = result;

        return result;
    }

private:
    unordered_map<int, int> cache;
};
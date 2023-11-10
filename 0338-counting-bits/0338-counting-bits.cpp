/*
take for example:
0000000
0000001
0000010
0000011
0000100
0000101
0000110
0000111
0001000
0001001
0001010
0001011
0001100
0001101
0001110
0001111

it can be observed that count of 1 for every number x depends on 1s in x / 2 (x is x / 2 and 1 bit at the right)
now if the number is even, then number of 1s is same as x / 2 (as the additional one bit is 0) and + 1 if it is odd
note that it makes even more sense when you realize, there will be only two numbers, x (one odd and one even) that equal to any x / 2
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            dp[i] = (i & 1) + dp[i >> 1];
        }

        return dp;
    }
};
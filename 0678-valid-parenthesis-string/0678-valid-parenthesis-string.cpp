/*
the brute force solution is to explore all paths and take or dont take approach for '('/')'/'_' for *
so for s = "(*)"
                (           =>  open = 1
              / | \
            (   _   )       =>  open = 2/1/0
            |   |   |
            )   )   )       =>  open = 1/0/-1
            
we can cache index (in s) and open count vs true/false of that subtree

a better way to solve this would be
iterate from left to right first and take * as (
now if at any point open is -ve, then that means even with * as ( we got to a point where the parenthesis are not balanced
we allow values of open >= 0 (> because _ is also an option which can lead to extra (s in our iteration)
next, iterate in the opposite direction with * as )
*/
class Solution {
public:
    bool checkValidString(string s) {
        int size = s.size() - 1;
        int forward = 0, backward = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '*') {
                ++forward;
            } else {
                --forward;
            }
            
            if (s[size - i] == ')' || s[size - i] == '*') {
                ++backward;
            } else {
                --backward;
            }
            
            if (forward < 0 || backward < 0) {
                return false;
            }
        }

        return true;
    }
};
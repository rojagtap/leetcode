/*
have to iterators left and right
skip left and right to the next alphanum
if l < r then check if the lower leftchar == rightchar then continue else return false
increment left, decrement right
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        
        while (1) {
            while (l < s.size() && !isalnum(s[l])) {
                ++l;
            }
            
            while (r >= 0 && !isalnum(s[r])) {
                --r;
            }
            
            if (l < r) {
                if (tolower(s[l]) != tolower(s[r])) {
                    return false;
                } else {
                    ++l;--r;
                }
            } else {
                break;
            }
        }
        
        return true;
    }
};
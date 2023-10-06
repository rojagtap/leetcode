/*
for s = "babad"
b: b
ba:
a: a, bab
ab:

take i and (i, i + 1) as centre for each i in (0, s.size) and expand to the left
*/
class Solution {
public:
    string longestPalindrome(string s) {
        string maxsub;
        for (int i = 0; i < s.size(); ++i) {
            string sub1 = substring(s, i, i);
            string sub2 = substring(s, i, i + 1);
            
            string currmax = sub1.size() >= sub2.size() ? sub1 : sub2;
            maxsub = maxsub.size() >= currmax.size() ? maxsub : currmax;
        }

        return maxsub;
    }

private:
    string substring(string& s, int l, int r) {
        if (l < 0 || r >= s.size()) return "";
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r;
        }
        ++l; --r;
        
        return s.substr(l, r - l + 1);
    }
};
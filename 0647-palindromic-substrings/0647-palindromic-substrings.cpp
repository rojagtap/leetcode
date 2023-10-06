/*
generate palindromic substrings using https://leetcode.com/problems/longest-palindromic-substring/
*/
class Solution {
public:
    int countSubstrings(string& s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            count += countFromCentre(s, i, i);
            count += countFromCentre(s, i, i + 1);
        }

        return count;
    }

private:
    int countFromCentre(string& s, int l, int r) {
        int count = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r;
            ++count;
        }

        return count;
    }
    
};
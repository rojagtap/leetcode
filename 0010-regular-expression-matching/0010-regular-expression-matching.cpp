/*
take/don'j take with the following conditions:
1. if p[j + 1] is * then
        if p[j] == s[i] or p[j] is "." then try take/don't take
3. if p[j] == s[i] or p[j] is ".", then take and move ahead

terminate if j reaches end then true if i too reaches the end else false
if i reaches end, then let j reach the end
*/
class Solution {
public:
    bool isMatch(string& s, string& p) {
        return match(s, p, 0, 0);
    }

private:
    bool match(string& s, string& p, int i, int j) {
        if (i >= s.size() && j >= p.size()) {
            return true;
        } else if (j >= p.size()) {
            return false;
        }

        bool charmatches = i < s.size() && (s[i] == p[j] || p[j] == '.');
        if (j + 1 < p.size() && p[j + 1] == '*') {
            return (charmatches && match(s, p, i + 1, j)) || match(s, p, i, j + 2);
        } else if (charmatches) {
            return match(s, p, i + 1, j + 1);
        } else {
            return false;
        }
    }
};
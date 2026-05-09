/**
i went trial and error for this one.
the ones that were especially viscious were
1. 1001 and
2. 1101
basically there are two one's at the end
**/

class Solution {
public:
    int minFlips(string& s) {
        int ones = 0, zeros = 0;

        for (auto& c : s) {
            ones += (c == '1');
            zeros += (c == '0');
        }

        int n = s.size();

        if (zeros > 0 && ones > 1) {
            if (s[0] == '1' && s[n - 1] == '1') {
                return min(zeros, ones - 2);
            }

            return min(zeros, ones - 1);
        }

        return 0;
    }
};

/**
class Solution {
public:
    int minFlips(string& s) {
        int ones = 0, zeros = 0;

        for (auto& c : s) {
            ones += (c == '1');
            zeros += (c == '0');
        }

        int n = s.size();

        // 7 ("100011")
        if (ones == 2 && s[0] == '1' && s[n - 1] == '1') {
            return 0;
        }

        if (n > 2 && ones == n - 1) {
            return 1;
        }

        if (zeros > 0 && ones > 1) {
            return min(zeros, ones - 1);
        }

        return 0;

        // 6 ("100011")
        if (ones == 2 && s[0] == '1' && s[n - 1] == '1') {
            return 0;
        }

        if (n > 2 && ones == n - 1) {
            return 1;
        }

        if (zeros > 0 && ones > 1) {
            return min(zeros, ones - 1);
        }

        return 0;

        // 5 ("011110")
        if (ones == 2 && s[0] == '1' && s[n - 1] == '1') {
            return 0;
        }

        if (n > 2 && ones == n - 1) {
            return 1;
        }

        if (zeros > 0 && ones > 1) {
            return ones - 1;
        }

        return 0;
        
        // 4 ("101")
        if (n > 2 && ones == n - 1) {
            return 1;
        }

        if (zeros > 0 && ones > 1) {
            return ones - 1;
        }

        return 0;
        
        // 3 ("101")
        if (n > 2 && ones == n - 1) {
            return 1;
        }

        if (zeros > 0 && ones > 1) {
            return ones - 1;
        }

        return 0;

        // 2 ("01")
        if (n > 1 && ones == n - 1) {
            return 1;
        }

        if (zeros > 0 && ones > 1) {
            return ones - 1;
        }

        return 0;

        // 1 ("11")
        // if (n > 1 && ones == n - 1) {
        //     return 1;
        // }

        // if (ones > 1) {
        //     return ones - 1;
        // }

        // return 0;
    }
};
**/

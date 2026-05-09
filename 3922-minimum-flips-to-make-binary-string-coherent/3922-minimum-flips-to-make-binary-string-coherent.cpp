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

        // 7
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

        // 6
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

        // 5
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
        
        // 4
        if (n > 2 && ones == n - 1) {
            return 1;
        }

        if (zeros > 0 && ones > 1) {
            return ones - 1;
        }

        return 0;
        
        // 3
        if (n > 2 && ones == n - 1) {
            return 1;
        }

        if (zeros > 0 && ones > 1) {
            return ones - 1;
        }

        return 0;

        // 2
        if (n > 1 && ones == n - 1) {
            return 1;
        }

        if (zeros > 0 && ones > 1) {
            return ones - 1;
        }

        return 0;

        // 1
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

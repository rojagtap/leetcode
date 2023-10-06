/*
for s = 11106
split = [1, 1, 10, 6]
- AAJF
- KJF

for s = 101106
split = [10, 1, 10, 6]
- JAJF

for s = 2226
split = [2, 2, 2, 6]
ways(n = 1): B
ways(n = 2): BB, V
ways(n = 3): BBB, VB, BV
ways(n = 4): BBBF, VBF, BVF, BBZ, VZ

ways(n = 1): 1
ways(n = 2): ways(n = 1) + int(str(n - 1) + str(n)) * 1
ways(n = 3): ways(n = 2) + int(str(n - 1) + str(n)) * ways(n = 1)
ways(n = 4): ways(n = 3) + int(str(n - 1) + str(n)) * ways(n = 2)

so
ways(n) = ways(n - 1) + int(str(n - 1) + str(n)) * ways(n - 2)
*/
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }

        int i = 0;
        vector<string> digits;
        while (i < s.size()) {
            string number = "";
            number += s[i];

            while (i + 1 < s.size() && s[i + 1] - 48 == 0) {
                number = number + s[i + 1];
                ++i;
            }

            if (!isvalid(number, emptystring)) {
                return 0;
            }

            digits.push_back(number);

            ++i;
        }

        int nwaysminus1 = 1, nwaysminus2 = 1, nways = 1;
        for (int i = 1; i < digits.size(); ++i) {
            nways = nwaysminus1 + isvalid(digits[i - 1], digits[i]) * nwaysminus2;
            nwaysminus2 = nwaysminus1;
            nwaysminus1 = nways;
        }

        return nways;
    }

private:
    string emptystring = "";
    int isvalid(string& s1, string& s2) {
        string append = s1 + s2;
        int integer = stoi(append);
        return integer >= 1 && integer <= 26;
    }
};
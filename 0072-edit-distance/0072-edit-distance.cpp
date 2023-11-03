/*
similar to take/don't take, just 3 choices:
- insert
- delete
- replace

if chars are equal, move ahead (like lcs)
else try one of each choices:
- if inserting, that means we inserted character of word2 in word1 before word1[i], so move j ahead as it will be matched with the insertion
- if deleting, means we deleted a character from word1 so now we want to try with the remaining word1 so we go to i + 1
- if substituting, means we are simply replacing word1[i], so now they will match and we can go ahead (like the equal case)

note that each operation will add 1 to their result
*/

// bottom-up dp, translate top-down
// O(m * n) in time and space
// where m is word1.size() and n is word2.size()
class Solution {
public:
    int minDistance(string& word1, string& word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i < word1.size(); ++i) {
            dp[i][word2.size()] = word1.size() - i;
        }

        for (int j = 0; j < word2.size(); ++j) {
            dp[word1.size()][j] = word2.size() - j;
        }
        
        for (int i = word1.size() - 1; i >= 0; --i) {
            for (int j = word2.size() - 1; j >= 0; --j) {
                dp[i][j] = (word1[i] == word2[j]) ? dp[i + 1][j + 1] : 1 + min({dp[i][j + 1], dp[i + 1][j], dp[i + 1][j + 1]});
            }
        }

        return dp[0][0];
    }
};

// // backtracking + memoization
// // O(m * n) in time and space + O(n) for recursion stack
// // where m is word1.size() and n is word2.size()
// class Solution {
// public:
//     int minDistance(string& word1, string& word2) {
//         dp = vector<vector<int>>(word1.size(), vector<int>(word2.size(), -1));
//         return recurse(word1, word2, 0, 0);
//     }

// private:
//     vector<vector<int>> dp;

//     int recurse(string& word1, string& word2, int i, int j) {
//         if (i == word1.size() && j == word2.size()) {
//             return 0;
//         }

//         if (j == word2.size()) {
//             // nothing left in word2 but word1 is still having chars
//             // so try deleting the rest
//             return word1.size() - i;
//         }

//         if (i == word1.size()) {
//             // nothing left in word1 to replace or to delete
//             // so try inserting until there are still chars in word2
//             return word2.size() - j;
//         }

//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }

//         if (word1[i] == word2[j]) {
//             // equal case
//             return dp[i][j] = recurse(word1, word2, i + 1, j + 1);
//         } else {
//             return dp[i][j] = 1 + min({
//                 recurse(word1, word2, i, j + 1),    // insert
//                 recurse(word1, word2, i + 1, j),    // delete
//                 recurse(word1, word2, i + 1, j + 1) // substitute
//             });
//         }
//     }
// };

// // backtracking
// // O(3 ^ n) in time and O(n) in space (recursion stack), TLE
// // where n is word2.size()
// class Solution {
// public:
//     int minDistance(string& word1, string& word2) {
//         return recurse(word1, word2, 0, 0);
//     }

// private:
//     int recurse(string& word1, string& word2, int i, int j) {
//         if (i == word1.size() && j == word2.size()) {
//             return 0;
//         }

//         if (j == word2.size()) {
//             // nothing left in word2 but word1 is still having chars
//             // so try deleting the rest
//             return word1.size() - i;
//         }

//         if (i == word1.size()) {
//             // nothing left in word1 to replace or to delete
//             // so try inserting until there are still chars in word2
//             return word2.size() - j;
//         }

//         if (word1[i] == word2[j]) {
//             // equal case
//             return recurse(word1, word2, i + 1, j + 1);
//         } else {
//             return 1 + min({
//                 recurse(word1, word2, i, j + 1),    // insert
//                 recurse(word1, word2, i + 1, j),    // delete
//                 recurse(word1, word2, i + 1, j + 1) // substitute
//             });
//         }
//     }
// };
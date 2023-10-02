// /*
// similar to subsets
// can be solved using classic backtracking as well as appending new character to existing subset
// */
// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         string combination;
//         recurse (digits, combination, 0);
        
//         return combinations;
//     }
    
// private:
//     vector<string> combinations;
//     unordered_map<char, vector<char>> mapping = {
//         {'2', {'a', 'b', 'c'}},
//         {'3', {'d', 'e', 'f'}},
//         {'4', {'g', 'h', 'i'}},
//         {'5', {'j', 'k', 'l'}},
//         {'6', {'m', 'n', 'o'}},
//         {'7', {'p', 'q', 'r', 's'}},
//         {'8', {'t', 'u', 'v'}},
//         {'9', {'w', 'x', 'y', 'z'}},
//     };
    
//     void recurse (string& digits, string& combination, int startindex) {
//         if (!combination.empty() && combination.size() == digits.size()) {
//             combinations.push_back(combination);
//         }
        
//         for (int i = startindex; i < digits.size(); ++i) {
//             for (auto& ch : mapping.at(digits[i])) {
//                 combination.push_back(ch);
//                 recurse (digits, combination, i + 1);
//                 combination.pop_back();
//             }
//         }
//     }
// };

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> subsets = {""};
        
        for (auto& digit : digits) {
            int subsetsize = subsets.size();
            for (auto& ch : mapping.at(digit)) {
                for (int i = 0; i < subsetsize; ++i) {
                    subsets.push_back(subsets[i] + ch);
                }
            }
        }
        
        vector<string> combinations;
        for (auto& subset : subsets) {
            if (!subset.empty() && subset.size() == digits.size()) combinations.emplace_back(subset);
        }

        return combinations;
    }
    
private:
    unordered_map<char, vector<char>> mapping = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
    };
};
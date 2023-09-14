/*
use stack
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> parantheses;
        unordered_map<char, char> pairing = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                parantheses.push(c);
            } else if (!parantheses.empty() && parantheses.top() == pairing[c]) {
                parantheses.pop();
            } else {
                return false;
            }
        }
        
        return parantheses.empty();
    }
};
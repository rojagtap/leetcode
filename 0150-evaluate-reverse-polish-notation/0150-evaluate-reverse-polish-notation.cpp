/*
if token is number, push
if token is operator, pop top 2 and operate and push the result back to the stack
*/
class Solution {
public:
    int operation(const int& a, const int& b, string op) {
        if ("+" == op) {
            return a + b;
        } else if ("-" == op) {
            return a - b;
        } else if ("*" == op) {
            return a * b;
        } else {
            return a / b;
        }
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> calc;
                
        for (auto& token : tokens) {
            if (token.size() > 1 || isdigit(token[0])) {
                calc.push(stoi(token));
            } else {
                int second = calc.top(); calc.pop();
                int first = calc.top(); calc.pop();
                calc.push(operation(first, second, token));
            }
        }
        
        return calc.top();
    }
};
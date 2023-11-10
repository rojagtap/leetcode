/*
simple right to left multiplication
*/
class Solution {
public:
    string multiply(string& num1, string& num2) {
        if (num1.size() < num2.size()) {
            return multiply(num2, num1);
        }

        int sumcarry = 0, prodcarry = 0;

        string product(num1.size() + num2.size(), '0');
        for (int j = num2.size() - 1; j >= 0; --j) {
            for (int i = num1.size() - 1; i >= 0; --i) {
                int sum = (num1[i] - '0') * (num2[j] - '0') + (product[i + j + 1] - '0');
                product[i + j + 1] = sum % 10 + '0';
                product[i + j] += sum / 10;
            }
        }

        cout << product;
        for (int i = 0; i < num1.size() + num2.size(); ++i) {
            if (product[i] != '0') {
                return product.substr(i);
            }
        }

        return "0";
    }
};
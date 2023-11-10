/*
simple addition
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int sum = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
            digits[i] = sum;
        }

        if (carry) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};
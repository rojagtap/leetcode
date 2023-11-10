/*
for a = 1, b = 2
a = 01
b = 10
or/xor gives 3

for a = 2, b = 3
a = 010
b = 011
xor for addition and for carry we can use and
*/
class Solution {
public:
    int getSum(int a, int b) {
        int sum = a ^ b, carry = a & b;
        while (carry) {
            carry = (unsigned) carry << 1;

            int temp = sum;
            sum ^= carry;
            carry &= temp;
        }

        return sum;
    }
};
/*
multiply or divide by x until n is 0 based on whether n is positive or negative

a more optimized approach is to do exponentiation by squaring
for example, x = 2, n = 8
instead of doing x *= 2 for i = 8, 7, 6, 5, ..., 0,
we can x *= x for i = 8, 4, 2, 1
and in case of odd n, we will have to multiply an additional x to the result
*/
class Solution {
public:
    double myPow(double x, int n) {
        double power = 1.0;
        long exponent = abs(n);

        while (exponent) {
            if (exponent & 1)
                power *= x;

            x *= x;
            exponent >>= 1;
        }

        return n > 0 ? power : 1 / power;
    }
};

// class Solution {
// public:
//     double myPow(double x, int n) {
//         if (x == 0 || x == 1) return x;

//         double power = 1.0;
//         if (n > 0) {
//             while (n--) {
//                 power *= x;
//             }
//         } else {
//             while (n++) {
//                 power /= x;
//             }
//         }
//         return power;
//     }
// };
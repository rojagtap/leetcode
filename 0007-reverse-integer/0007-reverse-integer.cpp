/*
simple int reversal with /10 and %10
for conditions on int size,
take this example: x = 1463847412
r          x
0 1463847412
2  146384741
21  14638474
214  1463847
2147  146384
21474  14638
214748  1463
2147483  146
21474836  14
214748364  1

INT_MAX = 2147483647 and INT_MIN = -2147483648
*/
class Solution {
public:
    int reverse(int x) {
        int r = 0;
        while (x) {
            if (r > (INT_MAX / 10) || (x > 7 && r == INT_MAX / 10) || r < (INT_MIN / 10) || (x < -8 && r == INT_MIN / 10)) {
                return 0;
            }

            r *= 10;
            r += x % 10;
            x /= 10;
        }

        return r;
    }
};
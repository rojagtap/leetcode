/*
for cycle use slow and fast pointer
*/
class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;

        while (slow != 1) {
            slow = next(slow);
            fast = next(next(fast));

            if (slow == fast && slow != 1) {
                return false;
            }
        }

        return true;
    }

private:
    int next(int n) {
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += (digit * digit);
            n /= 10;
        }

        return sum;
    }
};
/*
when we do '& 1' we are basically doing 00001010 & 00000001 which will give 0 if number is even (LSB 0) and vice versa
in this problem we can do this repetitively by discarding each right bit to the right after checking '& 1'
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ones = 0;
        while (n) {
            ones += (n & 1);
            n >>= 1;
        }

        return ones;
    }
};
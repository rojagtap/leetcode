/*
take the rightmost bit and left shift it into the result number
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int _ = 1; _ <= 32; ++_) {
            result <<= 1;
            result |= (n & 1);
            n >>= 1;
        }

        return result;
    }
};
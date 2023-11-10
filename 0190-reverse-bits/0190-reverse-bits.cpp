/*
take the rightmost bit and left shift it into the result number

another approach is divide and conquer
for example to reverse any arbitrary stream of digits 12345678, we can
first split into 1234, 5678 and swap to 5678, 1234
then split each halves 56, 78 and 12, 34 and swap to 78, 56, 34, 12
finally split again into 7, 8, 5, 6, 3, 4, 1, 2 and swap to 8, 7, 6, 5, 4, 3, 2, 1
the only catch is we should know the number of digits
which in this case we do, i.e., 32
looks messy but is faster
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n & 0b00000000000000001111111111111111) << 16 | (n & 0b11111111111111110000000000000000) >> 16;
        n = (n & 0b00000000111111110000000011111111) << 8 | (n & 0b11111111000000001111111100000000) >> 8;
        n = (n & 0b00001111000011110000111100001111) << 4 | (n & 0b11110000111100001111000011110000) >> 4;
        n = (n & 0b00110011001100110011001100110011) << 2 | (n & 0b11001100110011001100110011001100) >> 2;
        n = (n & 0b01010101010101010101010101010101) << 1 | (n & 0b10101010101010101010101010101010) >> 1;

        return n;
    }
};

// class Solution {
// public:
//     uint32_t reverseBits(uint32_t n) {
//         uint32_t result = 0;
//         for (int _ = 1; _ <= 32; ++_) {
//             result <<= 1;
//             result |= (n & 1);
//             n >>= 1;
//         }

//         return result;
//     }
// };
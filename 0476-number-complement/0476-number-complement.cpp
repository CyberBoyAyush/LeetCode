class Solution {
public:
    int findComplement(int num) {
        int numBits = (int)(log2(num)) + 1; // it finds the number of bits

        unsigned int mask = (1U << numBits) - 1; // to safe than int overflow we use unsigned int

        return num ^ mask;
    }
};
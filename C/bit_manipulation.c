#include <stdio.h>
#include <stdint.h>

void swap_bits(uint32_t *num, uint32_t pos1, uint32_t pos2) {
    uint32_t bit1 = (*num >> pos1) & 1;
    uint32_t bit2 = (*num >> pos2) & 1;
    *num = *num ^ ((bit1 << pos1) | (bit2 << pos2));
}

uint32_t reverseBits(uint32_t n) { // 000101
    uint32_t reversed;             // 000000 
    for (int i = 0; i < 32; i++) {
        reversed = reversed << 1;  // 001010 // shift 32 times to reverse
        reversed |= (n & 1);       // 000001 // set LSB
        n = n >> 1;                // 000000 // right shift LSB of n
    }
    return reversed;
}

int hammingWeight(uint32_t n) {
    int count = 0;
    for (int i = 0; i < 32; i++) {
        if ((n & 1) == 1) {
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int main()
{
    uint32_t n = 0b0100100100100100100100100100101;
    swap_bits(&n, 3, 4);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    return 0;
}

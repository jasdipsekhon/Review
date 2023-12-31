#include <stdio.h>
#include <stdint.h>

void swap_bits(uint32_t *num, uint32_t pos1, uint32_t pos2) {
    uint32_t bit1 = (*num >> pos1) & 1;
    uint32_t bit2 = (*num >> pos2) & 1;
    *num = *num ^ ((bit1 << pos1) | (bit2 << pos2));
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

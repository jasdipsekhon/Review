#include <stdio.h>
#include <stdint.h>

void getbits(uint8_t input) {
    printf("Value of input: %.2x\n", input);
}


int main() {
    uint32_t test = 0x12ABCD34;
    getbits(test >> 0);
    getbits(test >> 8);
    getbits(test >> 16); // this is 32 bit
    getbits(test >> 24);
    getbits(test >> 0 & 0xf0);

    uint32_t set_num = test;
    set_num |= (0xff << 0 | 0xff << 24);
    printf("Value: %.2x\n", set_num);
    return 0;
}
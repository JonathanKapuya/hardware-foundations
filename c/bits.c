#include <stdio.h>
#include <stdint.h>
#include <assert.h>
//clang -Wall -Wextra -g -fsanitize=address bits.c -o bits ./bits

void print_binary(uint32_t x) {

    for (int i = 31; i > -1; i--) {

        uint32_t a = 1u << i;

        if (x & a) {
            printf("%d", 1);
        } else {
            printf("%d", 0);
        }

    }
    printf("\n");

}

uint32_t set_bit(uint32_t x, int n) {

    uint32_t mask = 1u << n;

    uint32_t result = x | mask;

    return result;

}

uint32_t clear_bit(uint32_t x, int n) {

    uint32_t result = ~(1u << n) & x;

    return result;

}

uint32_t toggle_bit(uint32_t x, int n) {

    uint32_t result = (1u << n) ^ x;
    return result;

}

int main() {

    uint32_t binary = 0xA1u;
    print_binary(binary);
    printf("set bit 7: \n");
    print_binary(set_bit(binary, 7));
    printf("\n");
    printf("toggle bit 7: \n");
    print_binary(toggle_bit(binary, 7));
    printf("\n");
    printf("clear bit 7: \n");
    print_binary(clear_bit(binary, 7));
    printf("\n");
    return 0;

}
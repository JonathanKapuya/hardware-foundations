#include <stdio.h>
#include <stdint.h>
#include <assert.h>
//clang -Wall -Wextra -g -fsanitize=address bits.c -o bits && ./bits

void print_binary(uint32_t x) {

    for (int i = 31; i > -1; i--) {

        uint32_t a = 1u << i;
        // x is already in binary, compare to mask w/ the correct operator to manipulate.
        // the and operator returns 0 if x's binary is 0, and 1 if it is 1, to print.
        if (x & a) {
            printf("%d", 1);
        } else {
            printf("%d", 0);
        }

    }
    printf("\n");

}

uint32_t set_bit(uint32_t x, int n) {

    //mask has 1 at the n spot, uses the or operator (not exclusive) 
    //so that if it is 1, it will stay one. If it is a 0, it will become a 1, or be set.

    uint32_t mask = 1u << n;

    uint32_t result = x | mask;

    return result;

}

uint32_t clear_bit(uint32_t x, int n) {

    // this mask has only the nth bit as a 0, using ~ (flip). 
    //Because it is a zero the & operator cannot 
    //be true at the nth spot, will make it 0.
    uint32_t result = ~(1u << n) & x;

    return result;

}

uint32_t toggle_bit(uint32_t x, int n) {

    /* 
        uses exclusive or, nth spot will toggle 
        bc if its a 0 it becomes 1 and if its 1 it becomes 0
    */
    uint32_t result = (1u << n) ^ x;
    return result;

}

uint32_t get_field(uint32_t x, int lo, int width) {

    /*
    
    Before coding approach:
    need to >> x, lo spots. 
    then turn everything but the first (width) bits into zeros by using &, mask = 0 -> 1s for width

    */

    uint32_t new = x >> lo;
    uint32_t mask;

    if(width == 32) { /* ts means # remains same. 
        Sliding 32 makes undefined, so just make mask all 1s.
        */
        mask = ~0;
    } else {
        mask = (1u << width) - 1;
    }

    return new & mask;


}

int popcount(uint32_t x) {
    int count = 0;
    for (int i = 31; i > -1; i--) {

        uint32_t a = 1u << i;
        // x is already in binary, compare to mask w/ the correct operator to manipulate.
        // the and operator returns 0 if x's binary is 0, and 1 if it is 1, to print.
        if (x & a) {
            count++;
        }

    }
    return count;

}

uint32_t set_field(uint32_t x, int lo, int width, uint32_t v) {

    /*
    Replaces the segment with v
    So first create a mask to delete the values in [lo, lo + width - 1], 

    */
    uint32_t mask;
    if(width == 32) { 
        mask = ~0;
    } else {
        mask = (1u << width) - 1;
    }
    v = v & mask;
    mask = (mask << lo);
    mask = ~mask;
    x = x & mask;

    v = v << lo;
    x = x | v;

    return x;

}

int main() {
    //test on n = 7 bc it's a 1.
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
    printf("%u (expect 2)\n", get_field(0xA1u, 4, 3));
    printf("%u (expect 1)\n", get_field(0xA1u, 0, 4));
    printf("%u (expect 10)\n", get_field(0xA1u, 4, 4));
    printf("%u (expect 4294967295)\n", get_field(0xFFFFFFFFu, 0, 32));
    printf("Count ones in 20(expected 2): %d \n", popcount(20));
    printf("\n\n");

    printf("%x expect ea\n", set_field(10u, 5, 3, 7u));

    printf("\n\n");

    return 0;


}
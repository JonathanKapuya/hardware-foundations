#include <stdio.h>
#include <stdint.h>
#include <assert.h>

void print_binary(uint32_t x);

uint32_t set_bit(uint32_t x, int n);

uint32_t clear_bit(uint32_t x, int n);

uint32_t get_field(uint32_t x, int lo, int width);

uint32_t set_field(uint32_t x, int lo, int width, uint32_t v);

int popcount(uint32_t x);

uint32_t toggle_bit(uint32_t x, int n);


int main() {

    /*

    Could use assert to test here, just mainly a show of how to import functions from other files...

    */


}
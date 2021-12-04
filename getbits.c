/* Implementation of getbits */
#include<stdio.h>

/* 11011000111, p = 6, n = 4, return = 1000 */
/* 00011011000 */

unsigned getbits (unsigned x, int p, int n) {
    return (x >> (p-n+1)) & ~(~0 << n);
}

int main(void) {
    printf("\ngetbits(1735, 6, 4) = %x %x %x", ~0, ~0<<4, getbits(1735, 6, 4));
}

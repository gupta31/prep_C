
/* Pseudo Random Number Generator */
#include<stdio.h>

unsigned long int seed = 1;

/* rand: return pseudo random number from 0..32767 */
int rand(void) {
    seed = seed * 1103515245 + 12345;
    return (unsigned int)(seed >> 16) & 0x7fff;
}

void set_seed(unsigned int s) {
    seed = s;
}

int main(void) {
    printf ("\nRandom number is %d", rand());
    printf ("\nRandom number is %d", rand());

    set_seed(3271);

    printf ("\nRandom number is %d", rand());

    printf ("\nRandom number
 is %d", rand());
/* Rudimentary alloc, afree function */
#include<stdio.h>

#define ALLOCSIZE 10000 /*size of preallocated space */

static char allocbuf[ALLOCSIZE];   /*storage array */
static char *allocp = allocbuf;

char *alloc(int size) {
    if(allocbuf + ALLOCSIZE - allocp >= size) {
        allocp += size;
        return(allocp-size);
    } else {
        printf("\nArray overflow");
        return NULL;
    }
}
void afree(char *p) {
    if((p >= allocbuf) && (p < allocbuf + ALLOCSIZE))
        allocp = p;
}

int main(void) {
    printf("\nallocbuf = %x, allocp = %x", allocbuf, allocp);
    char *cp = alloc(1000);
    strcpy(cp, "My group is C/C++");
    printf("\nallocbuf = %x, allocp = %x", allocbuf, allocp);
    afree(cp);
    printf("\nallocbuf = %x, allocp = %x", allocbuf, allocp);
    cp = alloc(5000);
    printf("\nallocbuf = %x, allocp = %x", allocbuf, allocp);
    afree(cp);
    printf("\nallococbuf = %x, allocp = %x", allocbuf, allocp);
}

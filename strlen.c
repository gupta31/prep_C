#include<stdio.h>

int strlen(char *s); // Function declaration */

int main(void) {
    char *str = "This is a C/C++ Specialized class.";
    printf("\nLength of the array is %d", strlen(str));
    printf("\nLength of the array is %d", strlen(str+5));
    return 0;
}

int strlen(char *s) {
    int l = 0;
    for(; *s != '\0'; s++) {
        l++;
    }
    return l;
}


#include <stdio.h>

char *replace(char *dest, char *src) {
    size_t j = 0;

    for (size_t i = 0; src[i]; i++) {
        if (src[i] == ' ') {
            dest[j++] = 'X';
            dest[j++] = 'X';
            dest[j++] = 'X';
        } else
            dest[j++] = src[i];
    }

    dest[j] = '\0';

    return dest;
}

int main(void) {
    char arr[] = "This is my string.";
    char buffer[256];

    replace(buffer, arr);

    printf("%s\n",buffer);
}

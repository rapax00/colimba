#include <stdio.h>

/* Exercise 1-9. Write a program to copy its input to its output, replacing each
string of one or more blanks by a single blank. */

int main(){
    int c, i;

    i = 0; /* i cuenta si detecto espacio, 0 para no, 1 para si */

    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
            i = 0;
        } else {
            if (i == 0) {
                putchar(c);
            }
            i = 1;
        }
    }

    return 0;
}

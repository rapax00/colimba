/* Exercise 1-9. Write a program to copy its input to its output, replacing each
string of one or more blanks by a single blank. */

#include <stdio.h>

#define OUT 0
#define IN 1

int main() {
    int c, i, old;

    i = IN;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && i == IN) {
            putchar(c);
            old = c;
        } else if (c == ' ') {
            i = OUT;
        } else if (c != ' ' && i == OUT) {
            putchar(' ');
            putchar(c);
            i = IN;
        }
        printf(".");
    }

    return 0;
}

#include <stdio.h>

/* Exercise 1-12. Write a program that prints its input one word per line. */

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

int main() {
    int c, state = OUT;

    while ((c = getchar()) != EOF) {
        if (IN == state) {
            if (' ' == c || '\n' == c || '\t' == c) {
                putchar('\n');
                state = OUT;
            } else {
                putchar(c);
            }
        } else {
            if (' ' == c || '\n' == c || '\t' == c) {
                ;
            } else {
                putchar(c);
                state = IN;
            }
        }
    }

    return 0;
}

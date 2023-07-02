#include <stdio.h>

/* Exercise 1-14. Write a program to print a histogram of the frequencies of
diferent characters in its input. */

#define AMOUNT_CHAR 5

int main()
{
    int c, i;
    int chars[AMOUNT_CHAR];
    int frequenci[AMOUNT_CHAR];

    for (i = 0; i < AMOUNT_CHAR; ++i) {
        while (c = getchar() != EOF) {
            chars[i] = c;
        }
    }

    i = 0;

    if (chars[i] == c) {
            frequenci[i];
    } else {
            ++i;
    }

    printf("\n");
    for (i = 0; i < AMOUNT_CHAR; ++i){
        while (frequenci[i] > 0) {
            printf("|");
            --frequenci[i];
        }
        printf("\n");
    }
}

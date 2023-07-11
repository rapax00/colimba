/* Exercise 1-14. Write a program to print a histogram of the frequencies of
diferent characters in its input. */

#include <stdio.h>

#define MAXCHAR 255 /* amount of chars in ASCII */

int main() {
    int c, frequenci[MAXCHAR], i;

    for (i = 0; i < MAXCHAR; ++i) {
        frequenci[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        ++frequenci[c];
    }

    for (i = 0; i < MAXCHAR; ++i) {
        printf("%c it read: ", i);
        while (0 < frequenci[i]) {
            printf("|");
            --frequenci[i];
        }
        printf("\n");
    }

    return 0;
}

/* Observaion: I assume it print funny char for chars after 128 in ASCII because it dont available in the console */

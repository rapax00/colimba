#include <stdio.h>

/* Exercise 1-13. Write a program to print a histogram of the lengths of words in
its input. It is easy to draw the histogram with the bars horizontal; a vertical
orientation is more challenging. */

int main() {
    int c, i;
    int count = 0;
    int wordLength[9];

    for (i = 0; i < 9; ++i) {
        wordLength[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c != ' '){
            ++count;
        } else if ((c == ' ') || (c == '\n')) {
            if ((count < 10) && (count > 0)) {
                ++wordLength[count-1]; /* suma 1 si la palabra tienen entre 1 y 9 caracteres */
                count = 0;
            } else if (count > 10 ) {
                ++wordLength[9]; /* suma 1 si la palabra tiene 10 o mas caracteres */
                count = 0;
            }
        }
    }

    printf("\nHistograma:\n");
    for (i = 0; i < 10; ++i) {
        printf("Palabras con %d: ", i+1);
        while (wordLength[i] > 0) {
            printf("|");
            --wordLength[i];
        }
        printf("\n");
    }

    return 0;
}

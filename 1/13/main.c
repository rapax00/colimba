/* Exercise 1-13. Write a program to print a histogram of the lengths of words in
its input. It is easy to draw the histogram with the bars horizontal; a vertical
orientation is more challenging. */

#include <stdio.h>

#define AMOUNTWORDS 10 /* cantidad de largos de palabras a contar */

int main() {
    int c, i, count = 0, wordLength[AMOUNTWORDS];

    for (i = 0; i < AMOUNTWORDS; ++i) {
        wordLength[i] = 0;
    }

    while (1) {
        c = getchar();

        if (EOF != c) {
            if (c == ' ' || c == '\n') {
                if ((count < AMOUNTWORDS) && (count > 0)) {
                    ++wordLength[count-1]; /* suma 1 si la palabra tienen entre 1 y 9 caracteres */
                    count = 0;
                } else if (count >= AMOUNTWORDS ) {
                    ++wordLength[AMOUNTWORDS-1]; /* suma 1 si la palabra tiene 10 o mas caracteres segun corresponda */
                    count = 0;
                }
            } else {
                ++count;
            }
        } else if (0 != count){
            count < AMOUNTWORDS ? ++wordLength[count-1] : ++wordLength[AMOUNTWORDS-1];
        } else {
            break;
        }
    }

    printf("\nHistograma:\n");
    for (i = 0; i < AMOUNTWORDS; ++i) {
        printf("Palabras con %d: ", i+1);
        while (wordLength[i] > 0) {
            printf("|");
            --wordLength[i];
        }
        printf("\n");
    }

    return 0;
}

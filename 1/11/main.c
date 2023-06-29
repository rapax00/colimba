#include <stdio.h>

/* Exercise 1-11. How would you test the word count program? What kinds of
input are most likely to uncover bugs if there are any? */

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

int main() {
    int c, newLine, newWord, newChar, state;

    state = OUT;
    newLine = newWord = newChar = 0;

    while ((c = getchar()) != EOF) {
        ++newChar   ;

        if (c == '\n') {
            ++newLine;
        }

        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++newWord;
        }
    }

    printf("Chars: %d,\tWords: %d,\tLines: %d", newChar, newWord, newLine);

    return 0;
}

/* Exercise 2-5. Write the function any( s1, s2), which returns the first location
in the string s1 where any character from the string s2 occurs, or -1 if s1
contains no characters from s2. (The standard library function strpbrk does
the same job but returns a pointer to the location.) */

#include <stdio.h>

#define LIMIT 100

int any(char s1[], char s2[]) {
    int i, j;

    /*i, j = 0;
    while (s1[i] != '\0') {
        while (s2[j] != '\0') {
            if (s1[i] == s2[j]) {
                return i;
            }
            ++j;
        }
        j = 0;
        ++i;
    }*/

    for (i = 0;s1[i] != '\0'; ++i) {
        for (j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                return i+1;
            }
        }
    }

    return -1;
}

int main() {
    char word1[LIMIT];
    char word2[LIMIT];
    int c, i = 0;

    printf("First word: ");
    while ((c = getchar()) != '\n') {
        word1[i++] = c;
    }
    word1[i] = '\0';

    printf("Second word: ");
    i = 0;
    while ((c = getchar()) != '\n') {
        word2[i++] = c;
    }
    word2[i] = '\0';

    printf("%s %s Location is: %d",word1, word2, any(word1, word2));

    return 0;
}

/* OPTIMIZATION PENDING */

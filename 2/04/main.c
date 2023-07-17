/* Exercise 2-4. Write an alternate version of squeeze (s1 ,s2) that deletes
each character in s1 that matches any character in the string s2. */

#include <stdio.h>

#define MAXASCII 256
#define MAX 1000

void squeeze(char s[], int c);
void squeeze2(char s1[], char s2[]);

/* Test */
int main() {
    char word1[MAX], word2[MAX];
    int c, i;

    printf("Write word1:\n");               /* recive word 1 */
    i = 0;
    while ((c = getchar()) != '\n') {
        word1[i++] = c;
    }
    word1[i] = '\0';

    printf("Write word2:\n");               /* recive word 2 */
    i = 0;
    while ((c = getchar()) != '\n') {
        word2[i++] = c;
    }
    word2[i] = '\0';

    squeeze2(word1, word2);

    printf("Final word is: %s", word1);

    return 0;
}

/* squeeze: delete all c from s */
void squeeze(char s[], int c) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

/* squeeze2: delete all ocurrs of s2 in s1 */
void squeeze2(char s1[], char s2[]) {
    int charsS2[MAXASCII];

    int i;
    for (i = 0; i < MAXASCII; i++) {        /* fill with full 0 */
        charsS2[i] = 0;
    }

    for (i = 0; '\0' != s2[i]; i++) {       /* count when apear one char in s2 */
        charsS2[(int)s2[i]] = 1;
    }

    int j;
    for (j = 0; '\0' != s1[j]; j++) {       /* go to each char of s1 */
        if (charsS2[(int)s1[j]]) {          /* if this "char" is 1 in s2 to delete in s1 with squeeze */
            squeeze(s1, s1[j]);
        }
    }
}

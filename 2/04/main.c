/* Exercise 2-4. Write an alternate version of squeeze (s1 ,s2) that deletes
each character in s1 that matches any character in the string s2. */

/* squeeze: delete all c from s
void squeeze(char s[], int c) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c)
        s[j++] = s[i];
        s[j] = '\0';
    }
}
*/

#include <stdio.h>

void squeeze2(char s[], int c) {
    int i = 0, j = 0;

    while (s[i] != '\0') {
        if (s[i] != c) {
            s[j++] = s[i];
        }
        i++;
    }

    s[j] = '\0';
}

/* Test */
/*
int main() {
    char word1[100];
    int c, i = 0;

    while ((c = getchar()) != '\n') {
        word1[i++] = c;
    }
    word1[i] = '\0';

    printf("Put character to delete: ");
    c = getchar();

    squeeze2(word1, c);

    printf("Final word is: %s", word1);
}
*/

/* OPTIMIZATION PENDING */

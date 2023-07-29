/* Exercise 4-1. Write the function strr index ( s , t), which returns the position
of the rightmost occurrence of t in s, or -1 if there is none. */

#include <stdio.h>

#define MAX 1000

int strrindex2(char s[], char t[]);
int getline(char s[], int lim);

int main(void) {
    char ss[MAX], tt[MAX];

    getline(ss, MAX);
    getline(tt, MAX);

    printf("The word 1 is:\n%s\nThe find word is:\n%s\nAnd the position of word 2 in word 1 is:\n%d", ss, tt, strrindex2(ss, tt));

    return 1;
}

int strrindex2(char s[], char t[]) {
    int i, j, k, value = -1, lenghtT;

    for (lenghtT = 0; '\0' != t[lenghtT]; lenghtT++) {
        ;
    }
    printf("LenghtT: %d\n", lenghtT);

    for (i = 0; '\0' != s[i]; i++) {
        for (j = i, k = 0; '\0' != t[k] && s[j] == t[k]; j++, k++) {
            printf("s[%d] == %c, t[%d] == %c\n", j, s[j], k, t[k]);
        }
        printf("k: %d\n", k);
        printf("t[lenghT] %d, t[k]: %d\n", t[lenghtT -1], t[k]);
        if (t[lenghtT - 1] == t[k] || '\0' == t[k]) {
            value = i;
        }
    }

    return value;
}

/* getline: get line into s, return length */
int getline(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar( )) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';

    return i ;
}

/* Exercise 4-13. Write a recursive version of the function reverse(s), which
reverses the string s in place. */

#include <stdio.h>
#include <string.h>

void reverse(char s[], int begin, int length);

void main(void) {
    char str[] = "hola";

    reverse(str, 0, strlen(str) - 1);

    printf("%s\n", str);


    return 0;
}

void reverse(char s[], int begin, int length) {
    int c, i = begin, j = length;

    if (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverse(s, i + 1, j - 1);
    }
}

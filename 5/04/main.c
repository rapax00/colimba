/* Exercise 5-4. Write the function strend(s,t), which returns 1 if the string
t occurs at the end of the string s, and zero otherwise. */

#include <stdio.h>
#include <string.h>

int strend(char *, char *);

int main(void) {
    char a[] = "hola carola";
    char b[] = "carola";

    printf("Strings:\na: %s\nb: %s\n", a, b);
    printf("---\n\"a\" occurs at the end of \"a\"? (1 for YES, 0 for NO)\n%d", strend(a, b));

    return 0;
}

int strend(char *s, char *t) {
    int i, j;

    for (i = strlen(s) - 1, j = strlen(t) - 1; 0 <= j; i--, j--) {
        if (*(s + i) == *(t + j)){
            ;
        } else {
            return 0;
        }
    }

    return 1;
}

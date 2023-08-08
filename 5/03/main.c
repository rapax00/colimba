/* Exercise 5-3. Write a pointer version of the function strcat that we showed
in Chapter 2: strcat (s, t ) copies the string t to the end of s. */

#include <stdio.h>

void strcat(char *, char *);

int main(void) {
    char a[] = "hola", b[] = " carola";

    printf("Strigns before strcat:\na: \"%5s\"\nb: \"%5s\"\n", a, b);
    strcat(&a, &b);
    printf("---\nStrigns after strcat:\na: \"%5s\"\nb: \"%5s\"\n", a, b);

    return 0;
}

void strcat(char *s, char *t) {
    int i, j;

    for (i = 0; '\0' != *(s + i); i++) {    /* count length of s in i */
        ;
    }
    for (i, j = 0; '\0' != *(t + j); i++, j++) {    /* copy the char of t after the last one position in s */
        *(s + i) = *(t + j);
    }
    *(s + i) = '\0';    /* end of string in s, t is not modificated */
}

/* Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa;
that is, convert an integer into a string by calling a recursive routine. */

#include <stdio.h>

#define MAX 100
#define NUMBER -12

int itoa(int n, char s[]);


int main (void) {
    char arr[MAX];

    itoa(NUMBER, arr);

    printf("itoa: %s\n", arr);

    return 0;
}

/* itoa: convert int to string */
int itoa(int n, char s[]) {
    int i = 0;

    if (n / 10) {
        i = itoa(n / 10, s);
    }

    if (n < 0 && 0 == i) {
        s[i++] = ('-') ;
        n = -n;
    } else if (n < 0) {
        n = -n;
    }

    s[i++] = n % 10 + '0';
    s[i] = '\0';

    return i;
}

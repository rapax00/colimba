#include <stdio.h>

/* Exercise 1-6. Verify that the expression getchar ( ) != EOF is 0 or 1. */

int main() {
    int c;

    c = getchar() != EOF;

    printf("La expresion es: %d\n", c);

    return 0;
}

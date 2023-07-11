/* Exercise 2-10. Rewrite the function lower, which converts upper case letters
to lower case, with a conditional expression instead of if-else. */

/*
/* lower: convert c to lower case; ASCII only */
/*
int lower (int c) {
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
*/

#include <stdio.h>

int toLower(int c) {
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A': c;
}

/* Test */
/*
int main() {
    printf("%c ", toLower('G'));
}
*/

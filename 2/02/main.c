/* Exercise 2-2. Write a loop equivalent to the for loop above without using &&
or || */

/*
for ( i = 0 ; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) {
    s[i] = c;
}
*/

#include <stdio.h>

int main() {
    int i, c, lim = 100;
    char s[lim];

    i = 0;
    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            if (i < lim-1) {
                s[i++] = c;
            }
        }
        printf("%d", i);
    }

    return 0;
}

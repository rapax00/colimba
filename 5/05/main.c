/* Exercise 5-5. Write versions of the library functions strncpy, strncat, and
strncmp, which operate on at most the first n characters of their argument
strings. For example, strncpy(s,t,n) copies at most n characters of t to s.
Full descriptions are in Appendix B. */

#include <stdio.h>

#define MAX 50
#define MAGIC_NUMBER 1

int main(void) {
    char a[] = "casiron";
    char b[] = "lo";
    char *c;

    /* strncpy */
    printf("STRNCPY\nBefore\na: %s\nb: %s\n", a, b);
    c = strncpy(a, b, MAGIC_NUMBER);
    printf("After\na: %s\nb: %s\nc: %s\n---\n", a, b, c);

    /* strncat */
    char d[MAX] = "caseron";    /* it's necessary set size of array because should be add more chars in at */
    char e[] = "eza";

    printf("STRNCAT\nBefore\nd: %s\ne: %s\n", d, e);
    c = strncat(d, e, MAGIC_NUMBER);
    printf("After\nd: %s\ne: %s\nc: %s\n---\n", d, e, c);

    /* strncmp */
    char f[] = "caseron";
    char g[] = "casa";

    printf("STRNCMP\nd: %s\ne: %s\nresult: %d", f, g, strncmp(f, g, MAGIC_NUMBER));

    return 0;
}

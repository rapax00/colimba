/* Exercise 5-13. Write the program tail, which prints the last n lines of its
input. By default, n is 10, let us say, but it can be changed by an optional
argument, so that
    tail -/i
prints the last n lines. The program should behave rationally no matter how
unreasonable the input or the value of n. Write the program so it makes the
best use of available storage; lines should be stored as in the sorting program of
Section 5.6, not in a two-dimensional array of fixed size
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int n = 10, c;

    argv++;
    argc--;

    if ((*++argv)[0] == '-') {
            argc--;
        if (*++argv[0] == 'n') {
            argc--;
            n = 0;
            ++argv;
            while (isdigit(c = (*argv[0]))) {
                n = n * 10 + c - '0';
                argv[0]++;
            }
            argc--;
        } else {
            printf("error: illegal command\n");
        }
    }

    /*printf("n: %d, argc %d, argv %s\n", n, argc, *argv);*/

    while (argc--) {
        argv++;
    }

    argv = argv - (n - 1);

    while (0 < n--) {
        printf("%s\n", *argv++);
    }

    return 0;
}

#include <stdio.h>

/* Exercise 1-2. Experiment to find out what happens when printf's argument
string contains \c, where c is some character not listed above. */

int main() {
    printf("Con barra: \c\n");
    printf("Sin barra: c\n");

    return 0;
}

#include <stdio.h>

/* Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to
use a function for conversion */

float conversion(int fhar);

/* Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table. */
int main() {
    int cels, fhar;
    int low, up, step;

    low = 0;
    up = 300;
    step = 20;

    cels = 0;

    printf("Tabla de temperaturas Cels -> Fhar\nCels  Fhar\n");

    while (cels <= up) {
        fhar = (9.0/5.0) * cels + 32;
        printf("%3d %6d\n", cels, fhar);
        cels += step;
    }

    return 0;
}
/* End Ex. 1-4 */

float conversion(int fhar) {
    float cels;

    cels = (5.0/9.0) * (fhar - 32.0);

    return cels;
}

#include <stdio.h>

/* Exercise 1-3. Modify the temperature conversion program to print a heading
above the table.*/

int main() {
    float cels, fhar;
    int low, up, step;

    low = 0;
    up = 300;
    step = 20;

    fhar = low;

    printf("Tabla de temperaturas Fhar -> Cels\nFhar  Cels\n");

    while (fhar <= up) {
        cels = (5.0/9.0) * (fhar - 32.0);
        printf("%3.0f %6.2f\n", fhar, cels);
        fhar += step;
    }
    
    return 0;
}

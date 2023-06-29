#include <stdio.h>

/*Exercise 1-5. Modify the temperature conversion program to print the table in
reverse order, that is, from 300 degrees to 0. */

int main () {
    int c;

    printf("Tabla de temperaturas\nCels  Fhar\n");

    for (c = 300; c >= 0; c = c - 20) {
        printf("%3d %6.2f\n", c, (5.0/9.0) * (c-32));
    }
    
    return 0;
}

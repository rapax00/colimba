/* Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments
of type t. (Block structure will help.) */

#include <stdio.h>

#define swap(t, x, y) t temp = x; x = y; y = temp;

int main(void) {
    char a = 't', b = 'y';

    printf("Before swap, a: %d, b: %d\n", a, b);
    swap(int, a, b);
    printf("After swap, a: %d, b: %d\n", a, b);

    return 0;
}


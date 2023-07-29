/* Exercise 3-1. Our binary search makes two tests inside the loop, when one
would suffice (at the price of more tests outside). Write a version with only one
test inside the loop and measure the difference in run-time. */

#include <stdio.h>

#define N 10
/*#define NUM_SEARCH 169*/

/* 3: 261, 5: 389, 7: 567 */

int binsearch(int x, int v[], int n);

/* Test */
int main() {
    int v[N], i;

    v[0] = rand() % 100;
    printf("%d", v[0]);
    for (i = 1; i < N; ++i) {
        v[i] = (rand() % 100) + v[i - 1]; /* generate a random number one more big to before */
        printf(" %d", v[i]);
    }
    printf("\n");

    for (i = 0; i < N; ++i) {
        int pos = binsearch(v[i], v, N);
        if (-1 != pos) {
            printf("\nThe number %d is at position %d\n", v[i], pos);
        } else {
            printf("\nThe number %d is not in the array", v[i]);
        }
    }

    return 0;
}

int binsearch(int x, int v[], int n) {
    int low, high;
    low = 0;
    high = n;

    while (low < high - 1) {
        int mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return x == v[low] ? low : -1;
}

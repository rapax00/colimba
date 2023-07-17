/* Exercise 3-1. Our binary search makes two tests inside the loop, when one
would suffice (at the price of more tests outside). Write a version with only one
test inside the loop and measure the difference in run-time. */

#include <stdio.h>

#define N 10
#define NUM_SEARCH 261

int binsearch(int x, int v[], int n);

/* Test */
int main() {
    int v[N], i;

    for (i = 0; i < N; ++i) {
        v[i] = 0 < i ? v[i] = (rand() % 100) + v[i-1] : rand() % 100; /* generate a random number one more big to before */
        printf("%d ", v[i]);
    }

    int pos = binsearch(NUM_SEARCH, v, N);
    if (-1 != pos) {
        printf("\nThe number is in the position %d\n", pos);
    } else {
        printf("\nThe number isn't in the array");
    }

    return 0;
}

int binsearch(int x, int v[], int n) {
    int low, i, high, mid;
    low = i = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x <= v[mid]) {
            high = mid - 1;

        } else {
            low = mid + 1;

        }
        ++i;
    }

    return x == v[mid] ? mid : -1;
}

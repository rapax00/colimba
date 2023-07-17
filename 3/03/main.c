/* Exercise 3-3. Write a function expand(s1 ,s2) that expands shorthand nota-
tions like a-z in the string s1 into the equivalent complete list abc...xyz in
s2. Allow for letters of either case and digits, and be prepared to handle cases
like a-b-c and a-zO-9 and -a-z. Arrange that a leading or trailing - is
taken literally. */

#include <stdio.h>

#define MAX 1000
#define YES 1
#define NO 0

void expand(char s1[], char s2[]) {
    int first, second, detectedMinus, sign, lenghtS2, i, k;

    second = 0;
    detectedMinus = NO;
    i = 0;

    int j = 0;
    while (s1[j] != '\0') {
        while (!second) {                                       /* establish first and second, when second have a value different of 0 (!second is false and exit to while)means is ready to expand notation */
            if ('-' != s1[j] && NO == detectedMinus) {          /* if still non-detected one minus, asign first */
                first = s1[j];
                detectedMinus = YES;
            } else if ('-' != s1[j] && YES == detectedMinus) {  /* if detected one minus, the next char different of minus is the second */
                second = s1[j];
                detectedMinus = NO;
            }
            j++;
        }

        sign = first < second ? 1 : -1;                         /* estabilish if first is minor that second means that should to go in "ASCII order", sign is used to multiplicate i in the for below to after sum a first */
        lenghtS2 = abs(first - second) + 1;

        for (i, k = 0; k < lenghtS2; i++, k++) {                /* build s2. i retaind the position that should be fill. k store the value that should be add to first to form the sequence*/
            s2[i] = first + (sign * k);
        }

        second = 0;                                             /* asign 0 to second for continue reading s1 to find next notation sequence */
    }

    s2[i] = '\0';                                               /* asign end of te string to s2 when s1 finds '\0' */
}

/* Test */
int main() {
    char w1[MAX], w2[MAX];
    int c, i = 0;

    while (EOF != (c = getchar()) &&  '\n' != c && i < MAX)  {
        w1[i++] = c;
    }
    w1[i] = '\0';

    expand(w1, w2);

    int j;
    printf("\n");
    for (j = 0; w2[j] != '\0'; j++) {
        printf("%c ", w2[j]);
    }

    return 0;
}

/* TODO: make robust this algorithm to recibe a-f-k */

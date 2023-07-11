/* Exercise 1-17. Write a program to print all input lines that are longer than 80
characters. */

#include <stdio.h>

int main(){
    int c, max = 80, count = 0;
    char line[max+1];

    while((c = getchar()) != EOF) {
        if ('\n' != c){
            if (count < max){
                line[count] = c;
            } else if (count == max) {
                line[count] = '\0';
                printf("%s", line);
                putchar(c);
            } else {
                putchar(c);
            }
            ++count;
        } else {
            count = 0;
        }
    }

    return 0;
}

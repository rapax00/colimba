/* Exercise 5-10. Write the program expr, which evaluates a reverse Polish
expression from the command line, where each operator or operand is a separate
argument. For example,
    expr 2 3 4 + *
evaluates 2 x (3+4). */

#include <stdio.h>
#include <ctype.h>
#include "stack.h"

int main(int argc, char *argv[]) {
    char c;

    argv++;
    argc--;

    while (isdigit(c = **argv++)) {
        push(c - '0');
    argc--;
    }

    do {
        printf("argv %s\n", *argv);
        switch (c) {
        case '+':
            push(pop() + pop());
            break;
        case '.':
            push(pop() * pop());
            break;
        case '\0':
            printf("result: %5.8g\n", pop());
            break;
        }
    } while (1 <= argc-- && (c = **argv++));

    return 0;
}

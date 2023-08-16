/* Exercise 5-10. Write the program expr, which evaluates a reverse Polish
expression from the command line, where each operator or operand is a separate
argument. For example,
    expr 2 3 4 + *
evaluates 2 x (3+4). */

#include <stdio.h>
#include <stdlib.h> /* for atof */
#include <math.h>   /* for functions */
#include "functions.h"

int main(int argc, char *argv[]) {
    int op, op2;
    char val[MAXVAL];
    int sizeStack = 0;

    ++argv; /* skip ./main */
    --argc;

    while (--argc >= 0) {
        op = getop(val, *++argv);
        switch (op) {
        case NUMBER:
            sizeStack = push(atof(val));
            break;
        case '+':
            sizeStack = push(pop() + pop());
            break;
        case '.':
            sizeStack = push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            sizeStack = push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (0.0 != op2) {
                sizeStack = push(pop() / op2);
            } else {
                printf("error: zero division\n");
            }
            break;
        case '%':
            op2 = pop();
            if (0 != (int)op2) {
                sizeStack =  push((int)pop() % (int)op2);
            } else {
                printf("error: zero modulus\n");
            }
            break;
        case SIN:
            sizeStack = push(sin(pop()));
            break;
        case EXP:
            sizeStack = push(exp(pop()));
            break;
        case POW:
            double y = pop();
            double x = pop();
            if (0 == x && y <= 0) {
                printf("error: zero exp %.8g\n", y);
            } else if (x < 0) {
                printf("note: %.8g convert to int. %.8g \n", y, x);
                sizeStack = push(pow(x, (int)y));   /* NOTE: I don't know why its not result in a negative number */
            } else {
                sizeStack = push(pow(x, y));
            }
            break;
        case '\0':
            if (1 == sizeStack) {
                printf("result: %.8g\n", pop());
            }
            break;
        case ERR:
        default:
            printf("ERROR invalid input: %s\n", val);
            break;
        }
    }

    return 0;
}

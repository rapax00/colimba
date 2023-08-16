#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define MAXVAL 1000

enum {NUMBER = 1, SIN, EXP, POW, ERR};

double pop(void);
int push(double f);
int getop(char s[], char arg[]);

#endif // STACK_H_INCLUDED

#ifndef CALC_INCLUDED
#define CALC_INCLUDED

#define NUMBER '0'              /* signal that a number was found */

enum {ERR = '1', TOP, SWP, DUP, CLR, SIN, EXP, POW};

void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);

#endif // CALC_INCLUDED

/* Exercise 5-9. Rewrite the routines day_of _year and month_day with
pointers instead of indexing. */

#include <stdio.h>
#include "functions.h"

#define DAY 9
#define MONTH 12
#define YEAR 2018

#define YEARDAY 500

int main(void) {
    int yd;

    if ((yd = day_of_year(YEAR, MONTH, DAY)) != -1) {
        printf("%d/%d/%d is %dth day of the year\n", DAY, MONTH, YEAR, yd);
    }


    int pmonth, pday, md;



    if ((md = month_day(YEAR, YEARDAY, &pmonth, &pday)) != -1) {
        printf("%dth day of the year %d is the %d/%d/%d\n", YEARDAY, YEAR, pday, pmonth, YEAR);
    }

    return 0;
}

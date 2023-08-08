/* Exercise 5-8. There is no error checking in day_of_year or month_day
Remedy this defect. */

#include <stdio.h>
#include "functions.h"

#define DAY 12
#define MONTH 13
#define YEAR 2023

#define YEARDAY 400

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

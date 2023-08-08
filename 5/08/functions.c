#include <stdio.h>
#include "functions.h"

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & dat */
int day_of_year(int year, int month, int day) {
    int i, leap;

    leap = (year % 4 == 0) && (year/100 != 0) || (year % 400 == 0);

    /* error detector */
    if (month <= 0 || 12 < month) {
        printf("error: invalid month\n");
        return -1;
    }
    if (day <= 0 || daytab[leap][month] < day) {
        printf("error: invalid day\n");
        return -1;
    }


    for (i = 1; i < month; i++) {
        day += daytab[leap][i];
    }

    return day;
}

/* month_day: set month, day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = (year % 4 == 0) && (year/100 != 0) || (year % 400 == 0);

    /* error detector */
    if (0 == leap && 365 < yearday) {
        printf("error: your year day exceeds the limits of the year for %d days", yearday - 365);
        return -1;
    }
    if (1 == leap && 366 < yearday) {
        printf("error: your year day exceeds the limits of the year for %d days", yearday - 366);
        return -1;
    }

    for (i = 1; daytab[leap][i] < yearday; i++) {
        yearday -= daytab[leap][i];
    }

    *pmonth = i;
    *pday = yearday;
    return 0;
}

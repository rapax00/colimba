/* 2-3 Write the function htoi(s), which converts a string of hexa-
decimal digits (including an optional Ox or Ox) into its equivalent integer value.
The allowable digits are 0 through 9, a through f, and A through F*/

#include <stdio.h>
#include <math.h>

int htoi(char hex[]) {
    int i = 0, decimal = 0;

    if (hex[i] == '0' && (hex[i+1] == 'x' || hex[i+1] == 'X')) {
        i = 2;
    }

    while (hex[i] != '\0') {
        decimal *= 16;
        if ('0' <= hex[i] && hex[i] <= '9') {
            decimal += hex[i] - '0';
        } else if ('A' <= hex[i] && 'F' >= hex[i]) {
            decimal += hex[i] - 'A' + 10;
        } else if ('a' <= hex[i] && 'f' >= hex[i]) {
            decimal += hex[i] - 'a' + 10;
        }
        ++i;
    }

    return decimal;
}

int main() {
    int decimal, c, i;
    char hex[10];

    i = 0;
    while ((c = getchar()) != EOF && c != '\n' && i < 10) {
        hex[i++] = c;
    }
    hex[i] = '\0';

    decimal = htoi(hex);

    printf("The hex recived: %s, convertion to decimal: %u", hex, decimal);

    return 0;
}

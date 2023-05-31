#include "main_h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * Return: 0(success)
 */

int main() {
    // Testing the functions
    unsigned int num = 42;
    printUnsigned(num);

    unsigned int octalNum = 42;
    printOctal(octalNum);

    unsigned int hexNum = 42;
    printLowercaseHex(hexNum);

    unsigned int uppercaseHexNum = 42;
    printUppercaseHex(uppercaseHexNum);

    char *str = "Hello\nWorld";
    printStringWithHex(str);

    char c = 'A';
    printChar(c);

    char *str2 = "Hello, World!";
    printString(str2);

    int decimalNum = 42;
    printDecimal(decimalNum);

    void *ptr = &main;
    printPointer(ptr);

    long int longNum = 1234567890L;
    printLongDecimal(longNum);

    short int shortNum = 12345;
    printShortDecimal(shortNum);

    char *reversedStr = "Hello";
    printReversedString(reversedStr);

    char *rot13Str = "Hello";
    printRot13String(rot13Str);

    return 0;
}

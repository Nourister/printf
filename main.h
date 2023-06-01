#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdarg.h>

/**
 * struct print_function - Struct for storing conversion specifier and corresponding print function
 * @specifier: The conversion specifier
 * @print_function: Pointer to the print function for the specifier
 */
typedef struct print_function
{
    char *specifier;
    void (*print_function)(va_list my_args);
} print_function_t;

int main ();

/*int _putchar(char c);*/

int _printf(const char *format, ...);

/* Function prototypes for printing different conversions */
void printUnsigned(va_list my_args);
void printOctal(va_list my_args);
void printHex(va_list my_args);
void printHexUpper(va_list my_args);
void printStringWithHex(va_list my_args);
void printChar(va_list my_args);
void printString(va_list my_args);
void printDecimal(va_list my_args);
void printPointer(va_list my_args);
void printLong(va_list my_args);
void printShort(va_list my_args);
void printReversedString(va_list my_args);
void printRot13String(va_list my_args);

#endif /* MAIN_H */


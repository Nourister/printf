#ifndef _MAIN_H
#define _MAIN_H

#include "stdlib.h"
#include "stdio.h"
#include "stdarg.h"

int _printf(const char *format, ...);

void printChar(va_list my_args);

void printString(va_list my_args);

void printDecimal(va_list my_args);

#endif /* MAIN_H */

#include "main.h"

void printChar(va_list my_args)
{
    char c = (char)va_arg(my_args, int);
    putchar(c);
}

void printString(va_list my_args)
{
    char *str = va_arg(my_args, char *);
    while (*str)
    {
        putchar(*str);
        str++;
    }
}

void printDecimal(va_list my_args)
{
    int num = va_arg(my_args, int);
    printf("%d", num);
}

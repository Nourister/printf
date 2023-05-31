#include "main.h"


/* Sample print functions for different conversions */

void printUnsigned(va_list my_args)
{
    unsigned int num = va_arg(my_args, unsigned int);
    printf("%u", num);
}

void printOctal(va_list my_args)
{
    unsigned int num = va_arg(my_args, unsigned int);
    printf("%o", num);
}

void printHex(va_list my_args)
{
    unsigned int num = va_arg(my_args, unsigned int);
    printf("%x", num);
}

void printHexUpper(va_list my_args)
{
    unsigned int num = va_arg(my_args, unsigned int);
    printf("%X", num);
}

void printStringWithHex(va_list my_args)
{
    char *str = va_arg(my_args, char *);
    while (*str)
    {
        if (*str < 32 || *str >= 127)
        {
            putchar('\\');
            putchar('x');
            printf("%02X", *str);
        }
        else
        {
            putchar(*str);
        }
        str++;
    }
}

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

void printPointer(va_list my_args)
{
    void *ptr = va_arg(my_args, void *);
    printf("%p", ptr);
}

void printLong(va_list my_args)
{
    long num = va_arg(my_args, long);
    printf("%ld", num);
}

void printShort(va_list my_args)
{
    int num = va_arg(my_args, int);
    printf("%hd", num);
}

void printReversedString(va_list my_args)
{
    char *str = va_arg(my_args, char *);
    int len = 0;
    int i;
    while (str[len])
        len++;
    for (i = len - 1; i >= 0; i--)
    {
        putchar(str[i]);
    }
}

void printRot13String(va_list my_args)
{
    char *str = va_arg(my_args, char *);
    while (*str)
    {
        char c = *str;
        if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
            c += 13;
        else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
            c -= 13;
        putchar(c);
        str++;
    }
}

#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function that supports conversion specifiers: c, s, %, d, i
 * @format: The format string
 * @...: Variable number of arguments
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
    va_list my_args;
    int counter = 0;
    int n;
    char *str;
    int num;

    va_start(my_args, format);

    for (n = 0; format && format[n]; n++)
    {
        if (format[n] == '%')
        {
            n++;
            switch (format[n])
            {
                case 'c':
                    putchar(va_arg(my_args, int));
                    counter++;
                    break;
                case 's':
                    str = va_arg(my_args, char *);
                    while (*str)
                    {
                        putchar(*str);
                        str++;
                        counter++;
                    }
                    break;
                case '%':
                    putchar('%');
                    counter++;
                    break;
                case 'd':
                case 'i':
                    num = va_arg(my_args, int);
                    printf("%d", num);
                    counter++;
                    break;
                default:
                    putchar('%');
                    putchar(format[n]);
                    counter += 2;
                    break;
            }
        }
        else
        {
            putchar(format[n]);
            counter++;
        }
    }

    va_end(my_args);

    return (counter);
}

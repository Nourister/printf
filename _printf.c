#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function that supports different conversion specifiers
 * @format: The format string
 * @...: Variable number of arguments
 *
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
 
    va_start(args, format);

    while (*format != '\0')
    {
        if (*format != '%')
        {
            putchar(*format);
            count++;
        }
        else
        {
            format++;
            switch (*format)
            {
                case 'c':
                {
                    int arg = va_arg(args, int);
                    putchar(arg);
                    count++;
                    break;
                }
                case 's':
                {
                    char *arg = va_arg(args, char *);
                    while (*arg != '\0')
                    {
                        putchar(*arg);
                        count++;
                        arg++;
                    }
                    break;
                }
                case '%':
                {
                    putchar('%');
                    count++;
                    break;
                }
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        }

        format++;
    }

    va_end(args);

    return count;
}

#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>


/* Array of conversion specifiers and corresponding print functions */
print_function_t print_functions[] = {
    {"u", printUnsigned},
    {"o", printOctal},
    {"x", printHex},
    {"X", printHexUpper},
    {"S", printStringWithHex},
    {"c", printChar},
    {"s", printString},
    {"d", printDecimal},
    {"i", printDecimal},
    {"p", printPointer},
    {"l", printLong},
    {"h", printShort},
    {"r", printReversedString},
    {"R", printRot13String},
    {NULL, NULL}
};

/**
 * _printf - Custom printf function that supports different conversion specifiers
 * @format: The format string
 * @...: Variable number of arguments
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list my_args;
    int counter = 0;
    int n, l;

    va_start(my_args, format);

    for (n = 0; format && format[n]; n++)
    {
        if (format[n] == '%')
        {
            n++;
            if (format[n] == '%')
            {
                putchar('%');
		counter++;
                continue;
            }

            for (l = 0; print_functions[l].specifier != NULL; l++)
            {
                if (format[n] == print_functions[l].specifier[0])
                {
                    print_functions[l].print_function(my_args);
                    counter++;
                    break;
                }
            }

            if (print_functions[l].specifier == NULL)
            {
                putchar('%');
                putchar(format[n]);
                counter += 2;
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

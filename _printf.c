#include "main.h"
int _printf(const char *format, ...)
{
    int counter = 0; /* tells the computer how many chars we print */
    int n = 0; /* counter variable for the format string */
    va_list my_args; /* declares my_args as a va_list */

    va_start(my_args, format); /* initializes the list with format arg */

    while (format[n])
    {
        if (format[n] != '%')
        {
            _putchar(format[n]);
            counter++;
        }
        else
        {
            n++; /* after this '%', move to the next char */
            if (format[n] == 'c')
            {
                char c = va_arg(my_args, int); /* gets next arg in the list as char */
                _putchar(c);
                counter++;
            }
            else if (format[n] == 's')
            {
                char *s = va_arg(my_args, char *); /* gets the next arg in the list as string */
                while (*s)
                {
                    _putchar(*s);
                    s++;
                    counter++;
                }
            }
            else if (format[n] == '%')
            {
                _putchar('%');
                counter++;
            }
        }
        n++; /* moves to the next char in the format string */
    }

    va_end(my_args); /* cleans the arg list */
    return counter; /* returns the number of printed characters */
}

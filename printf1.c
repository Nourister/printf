#include "main.h"
/**
 * _printf - print function
 * @format: format used
 * @...:indicates any number of arguments to be passed
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
	int counter = 0; /* tells the computer how many char we print */
	int n = 0; /* counter variable for the fmt str */
	va_list my_args; /* declares my_args as a var_list */

	va_start(my_args, format); /* initializes the list with fmt arg */

	while (format[n])
	{
		if (format[n] != '%')
		{
			_putchar(format[n]);
			counter++;
		}
		else
		{
			n++; /* after this '%' move to the next char */
			if (format[n] == 'c')
			{
				char c = va_arg(my_args, int);

				_putchar(c);
				counter++;
			}
			else if (format[n] == 's')
			{
				char *s = va_arg(my_args, char *);

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
		n++; /* moves to the next char in the fmt str */
	}

	va_end(my_args); /* cleans the arg list */
	return (counter); /* returns number of printed characters */
}

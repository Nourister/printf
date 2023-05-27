#include "main.h"
#include <stdarg.h>
#include <stdio.h>



/**
 * handle_printf - print function
 * @format: format used
 * @...:indicates any number of arguments to be passed
 * Return: printed characters
 *
 */


int handle_printf(const char *format, ...)
{
	int counter = 0; /* tells the computer how many char we print */
	int n = 0; /* counter variable for the fmt str */
	va_list my_args; /* declares my_args as a var_list */

	va_start(my_args, format); /* initializes the list with fmt arg */

	while (format[n])
	{
		if (format[n] == 'd')
		{
		int d = va_arg(my_args, int);

			_putchar(d);
			counter++;
		}
		else if (format[n] == 'i')
		{
			int i = va_arg(my_args, int);

			_putchar(i);
			counter++;
		}
		n++; /* moves to the next char in the fmt str */
	}

	va_end(my_args); /* cleans the arg list */
	return (counter); /* returns number of printed characters */
}

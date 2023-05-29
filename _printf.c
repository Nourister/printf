#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int handle_format_specifier(char specifier, va_list my_args, int *counter);

/**
 * _printf - print function
 * @format: format used
 * @...:indicates any number of arguments to be passed
 * Return: printed character
 */

int _printf(const char *format, ...)
{
	int counter = 0;
	int n = 0;

	va_list my_args;

	va_start(my_args, format);

	while (format[n])
	{
		if (format[n] != '%')
		{
			_putchar(format[n]);
			counter++;
		}
		else
		{
			n++;
			counter += handle_format_specifier(format[n], my_args, &counter);
		}
		n++;
	}

	va_end(my_args);
	return (counter);
}

/**
 * handle_format_specifier - Handles the conversion specifier.
 * @specifier: The conversion specifier character.
 * @my_args: The va_list of arguments
 * @counter: The current counter value.
 * Return: The updated counter value.
 */
int handle_format_specifier(char specifier, va_list my_args, int *counter)
{
	switch (specifier)
	{
		case 'c':
			return (_putchar(va_arg(my_args, int)));
		case 's':
			return (print_string(va_arg(my_args, char*)));
		case 'd':
		case 'i':
			return (print_decimal(va_arg(my_args, int)));
		case 'u':
			return (print_unsigned(my_args));
		case 'o':
			return (print_octal(va_arg(my_args, unsigned int)));
		case 'x':
		case 'X':
			return (print_hexadecimal(va_arg(my_args, unsigned int), specifier));
		case 'p':
			return (print_address(va_arg(my_args, void *)));
		case '%':
			_putchar('%');
			return (1);
		case 'n':
			{
				int *ptr = va_arg(my_args, int *);
				*ptr = *counter;
			}
			return (0);
		case '\0':
			return (-1);
		default:
			_putchar('%');
			_putchar(specifier);
			return (2);
	}
}

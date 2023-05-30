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
			if (length_modifier == 'l')
				return (print_long_decimal(va_arg(my_args, long)));
			else if (length_modifier == 'h')
				return (print_short_decimal(va_arg(my_args, int)));
			else
				return (print_decimal(va_arg(my_args, int)));
		case 'u':
			if (length_modifier == 'l')
				return (print_long_unsigned(va_arg(my_args, unsigned long)));
			else if (length_modifier == 'h')
				return (print_short_unsigned(va_arg(my_args, unsigned int)));
			else
				return (print_unsigned(va_arg(my_args, unsigned int)));
		case 'o':
			if (length_modifier == 'l')
				return (print_long_octal(va_arg(my_args, unsigned long)));
			else if (length_modifier == 'h')
				return (print_short_octal(va_arg(my_args, unsigned int)));
			else
				return (print_octal(va_arg(my_args, unsigned int)));
		case 'x':
		case 'X':
			if (length_modifier == 'l')
				return (print_long_hexadecimal(va_arg(my_args, unsigned long), specifier));
			else if (length_modifier == 'h')
				return (print_short_hexadecimal(va_arg(my_args, unsigned int), specifier));
			else
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
		case 'S':
			return (print_custom_string(va_arg(my_args, char*)));
		case '\0':
			return (-1);
		default:
			_putchar('%');
			_putchar(specifier);
			return (2);
	}
}

/**
 * flush_buffer - Writes the buffer contents to the output and resets the buffer.
 * @buffer: The buffer containing the characters to be written.
 * @buf_index: The current index in the buffer.
 * @counter: The current counter value.
 */
void flush_buffer(char *buffer, int *buf_index, int *counter)
{
    int i;

    for (i = 0; i < *buf_index; i++)
    {
        _putchar(buffer[i]);
    }

    *counter += *buf_index;
    *buf_index = 0;
    memset(buffer, 0, sizeof(buffer));
}

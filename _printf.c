#include "main.h"
#include <stdarg.h>

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
			else if (format[n] == 'd' || format[n] == 'i')
			{
				int num = va_arg(my_args, int);
				counter += print_number(num);
			}
			else if (format[n] == 'u')
			{
				unsigned int num = va_arg(my_args, unsigned int);
				counter += print_unsigned(num);
			}
			else if (format[n] == 'o')
			{
				unsigned int num = va_arg(my_args, unsigned int);
				counter += print_octal(num);
			}
			else if (format[n] == 'X' || format[n] == 'x')
			{
				unsigned int num = va_arg(my_args, unsigned int);
				counter += print_hexadecimal(num, format[n]);
			}
			else if (format[n] == 'p')
			{
				void *ptr = va_arg(my_args, void *);
				counter += print_address(ptr);
			}
			else if (format[n] == 'n')
			{
				int *ptr = va_arg(my_args, int *);
				*ptr = counter;
			}
		}
		n++;
	}

	va_end(my_args);
	return counter;
}


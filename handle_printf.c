#include "main.h"
#include <stdio.h>

int print_number(int num); /* function declaration */
/**
 * _printf - prints a function
 * @formar: format to be printed
 * ...: arguments to be used
 * Description: Handle the following conversion specifiers
 * Return: printed character
 */

int _printf(const char *format, ...)
{
	int counter = 0, n = 0, num = 0;
	va_list my_args;

	va_start(my_args, format);

	while (format[n])
	{
		if (format[n] != '%')
		{
			_putchar(format[n++]);
			counter++;
		}
		else if (format[++n] == 'd' || format[n] == 'i')
		{
			num = va_arg(my_args, int);
			if (num < 0)
			{
				_putchar('-');
				counter++;
				num *= -1;
			}
			counter += print_number(num);
			n++;
		}
		else
		{
			_putchar(format[n++]);
			counter++;
		}
	}

	va_end(my_args);

	return (counter);
}

/**
 * print_number - prints numbers
 * @num:  integer digit to print
 * Return: digits
 */
int print_number(int num)
{
	int digits = 0;

	if (num == 0)
	{
		_putchar('0');
		digits = 1;
	}
	else
	{
		if (num / 10)
			digits = print_number(num / 10);
		_putchar('0' + (num % 10));
		digits++;
	}
	return (digits);
}


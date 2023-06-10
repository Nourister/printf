#include "main.h"

/**
 * print_op - function to check which specifier to print
 * @format: string being passed
 * @print_arr: array of struct ops
 * @my_list: list of arguments to print
 * Return: numb of char to be printed
 */
int print_op(const char *format, fmt_t *print_arr, va_list my_list)
{
	char n;
	int counter = 0, i = 0, l = 0;

	n = format[i];
	while (n != '\0')
	{
		if (n == '%')
		{
			l = 0;
			i++;
			n = format[i];
			while (print_arr[l].type != NULL &&
			       n != *(print_arr[l].type))
				l++;
			if (print_arr[l].type != NULL)
				counter = counter + print_arr[l].f(my_list);
			else
			{
				if (n == '\0')
					return (-1);
				if (n != '%')
					counter += _putchar('%');
				counter += _putchar(n);
			}
		}
		else
			counter += _putchar(n);
		i++;
		n = format[i];
	}
	return (counter);
}

/**
 * _printf - prints output according to format
 * @format: string being passed
 * Return: char to be printed
 */
int _printf(const char *format, ...)
{
	va_list my_list;
	int counter = 0;

	fmt_t ops[] = {
		{"c", print_char},
		{"s", _str},
		{"d", print_int},
		{"b", print_bin},
		{"i", print_int},
		{"u", print_ui},
		{"o", print_oct},
		{"x", _hex_l},
		{"X", _hex_u},
		{"R", print_rot13},
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);
	va_start(my_list, format);
	counter = print_op(format, ops, my_list);
	va_end(my_list);
	return (counter);
}

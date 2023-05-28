#include "main.h"

/**
 * print_char - print a character
 * @arg: argument containing the character to print
 * Return: number of characters printed
 */
int print_char(va_list my_args)
{
	char c = va_arg(my_args, int); /* gets the next arg in the list as char */
	_putchar(c);
	return (1);
}

/**
 * print_string - print a string
 * @arg: argument containing the string to print
 * Return: number of characters printed
 */
int print_string(va_list my_args)
{
	char *s = va_arg(my_args, char *); /* gets the next arg in the list as string */
	int counter = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		_putchar(*s);
		s++;
		counter++;
	}

	return (counter);
}

/**
 * print_number - print an integer
 * @n: integer to print
 * Return: number of characters printed
 */
int print_number(int n)
{
	unsigned int num;
	int counter = 0;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
		counter++;
	}
	else
		num = n;

	if (num / 10)
		counter += print_number(num / 10);

	_putchar((num % 10) + '0');
	counter++;

	return (counter);
}

/**
 * print_int - print an integer
 * @arg: argument containing the integer to print
 * Return: number of characters printed
 */
int print_int(va_list my_args)
{
	int num = va_arg(my_args, int);
	int counter = 0;

	counter += print_number(num);

	return (counter);
}

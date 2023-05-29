#include "main.h"

/**
 * print_char - print a character
 * @my_args: argument containing the character to print
 * Description: prints string and returns number of
 * printed characters
 * Return: number of characters printed
 */
int print_char(va_list my_args)
{
	char c = va_arg(my_args, int);

	_putchar(c);
	return (1);
}

/**
 * print_string - Prints a string.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(char *str)
{
	int i = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
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
 * print_decimal - print a decimal number
 * @num: number to print
 * Return: number of characters printed
 */
int print_decimal(int num)
{
	unsigned int n;
	int counter = 0;

	if (num < 0)
	{
		_putchar('-');
		n = -num;
		counter++;
	}
	else
		n = num;

	if (n / 10)
		counter += print_decimal(n / 10);

	_putchar((n % 10) + '0');
	counter++;

	return (counter);
}

/**
 * print_int - print an integer
 * @my_args: argument containing the integer to print
 * Description: prints an integer and returns number
 * of printed characters
 * Return: number of characters printed
 */
int print_int(va_list my_args)
{
	int num = va_arg(my_args, int);
	int counter = 0;

	counter += print_number(num);

	return (counter);
}

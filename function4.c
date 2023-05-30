#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_long_decimal - Prints a long decimal number.
 * @num: The long decimal number to print.
 *
 * Return: The number of characters printed.
 */
unsigned int print_long_decimal(long num)
{
	char buffer[20];
	int length = sprintf(buffer, "%ld", num);
	fputs(buffer, stdout);
	return length;
}

/**
 * print_short_decimal - Prints a short decimal number.
 * @num: The short decimal number to print.
 *
 * Return: The number of characters printed.
 */
unsigned int print_short_decimal(int num)
{
	return print_long_decimal(num);
}

/**
 * print_long_unsigned - Prints a long unsigned number.
 * @num: The long unsigned number to print.
 *
 * Return: The number of characters printed.
 */
unsigned int print_long_unsigned(unsigned long num)
{
	char buffer[20];
	int length = sprintf(buffer, "%lu", num);
	fputs(buffer, stdout);
	return length;
}

/**
 * print_short_unsigned - Prints a short unsigned number.
 * @num: The short unsigned number to print.
 *
 * Return: The number of characters printed.
 */
unsigned int print_short_unsigned(unsigned int num)
{
	return print_long_unsigned(num);
}

/**
 * print_long_octal - Prints a long octal number.
 * @num: The long octal number to print.
 *
 * Return: The number of characters printed.
 */
unsigned int print_long_octal(unsigned long num)
{
	char buffer[20];
	int length = sprintf(buffer, "%lo", num);
	fputs(buffer, stdout);
	return length;
}

/**
 * print_short_octal - Prints a short octal number.
 * @num: The short octal number to print.
 *
 * Return: The number of characters printed.
 */
unsigned int print_short_octal(unsigned int num)
{
	return print_long_octal(num);
}

/**
 * print_long_hexadecimal - Prints a long hexadecimal number.
 * @num: The long hexadecimal number to print.
 * @specifier: The specifier character ('X' or 'x').
 *
 * Return: The number of characters printed.
 */
unsigned int print_long_hexadecimal(unsigned long num, char specifier)
{
	char buffer[20];
	int length = (specifier == 'X') ? sprintf(buffer, "%lX", num) : sprintf(buffer, "%lx", num);
	fputs(buffer, stdout);
	return length;
}

/**
 * print_short_hexadecimal - Prints a short hexadecimal number.
 * @num: The short hexadecimal number to print.
 * @specifier: The specifier character ('X' or 'x').
 *
 * Return: The number of characters printed.
 */
unsigned int print_short_hexadecimal(unsigned int num, char specifier)
{
	return print_long_hexadecimal(num, specifier);
}


#include <stdio.h>
#include "main.h"

/**
 * print_custom_string - Handles printing of custom
 * string with non-printable characters.
 * @str: The string to be printed.
 * Return: The number of characters printed.
 */
unsigned int print_custom_string(char *str)
{
	unsigned int counter = 0;

	for (; *str; str++)
	{
		if (*str < 32 || *str >= 127)
		{
			putchar('\\');
			putchar('x');
			counter += 2;
			counter += _putchar_hex(*str / 16);
			counter += _putchar_hex(*str % 16);
		}
		else
		{
			putchar(*str);
			counter++;
		}
	}

	return (counter);
}

/**
 * _putchar_hex - Prints the hexadecimal representation of an unsigned char.
 * @c: The unsigned char to be printed.
 * Return: The number of characters printed.
 */

unsigned int _putchar_hex(unsigned char c)
{
	unsigned int counter = 0;
	char hex_digit = (c < 10) ? ('0' + c) : ('A' + c - 10);

	putchar(hex_digit);
	counter++;
	return (counter);
}


#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer
 * @n: The unsigned integer to print
 *
 * Return: The number of characters printed
 */
int print_unsigned(unsigned int n)
{
	unsigned int num = n;
	int counter = 0;

	if (num / 10)
		counter += print_unsigned(num / 10);

	_putchar((num % 10) + '0');
	counter++;

	return counter;
}

/**
 * print_octal - Prints an unsigned integer in octal format
 * @n: The unsigned integer to print
 *
 * Return: The number of characters printed
 */
int print_octal(unsigned int n)
{
	unsigned int num = n;
	int counter = 0;
	char octal_digits[100]; /* Assuming a maximum of 100 octal digits */

	do {
		octal_digits[counter] = (num % 8) + '0';
		num /= 8;
		counter++;
	} while (num != 0);

	while (counter > 0) {
		_putchar(octal_digits[counter - 1]);
		counter--;
	}

	return counter;
}

/**
 * print_hexadecimal - Prints an unsigned integer in hexadecimal format
 * @n: The unsigned integer to print
 * @uppercase: Indicates whether to print in uppercase (1) or lowercase (0)
 *
 * Return: The number of characters printed
 */
int print_hexadecimal(unsigned int n, int uppercase)
{
	unsigned int num = n;
	int counter = 0;
	char hex_digits[100]; /* Assuming a maximum of 100 hexadecimal digits */
	int i;

	do {
		int remainder = num % 16;
		if (remainder < 10)
			hex_digits[counter] = remainder + '0';
		else
			hex_digits[counter] = (uppercase ? 'a' : 'A') + (remainder - 10);
		if (remainder < 10)
			hex_digits[counter] = remainder + '0';
		else
			hex_digits[counter] = (uppercase ? 'a' : 'A') + (remainder - 10);
		num /= 16;
		counter++;
	} while (num != 0);

	for (i = counter - 1; i >= 0; i--) {
		_putchar(hex_digits[i]);
		counter++; /*Increment the counter for each character printed*/
	}

	return counter;
}

/**
 * print_address - Prints a memory address
 * @p: The pointer to the memory address to print
 *
 * Return: The number of characters printed
 */
int print_address(void *p)
{
	unsigned long int address = (unsigned long int)p;
	int counter = 0;
	char hex_digits[16]; /* Assuming a maximum of 16 hexadecimal digits */
	int i;

	_putchar('0');
	_putchar('x');
	counter += 2;

	if (address == 0)
	{
		_putchar('0');
		counter++;
	}
	else
	{
		for (i = 0; address != 0; i++)
		{
			int remainder = address % 16;
			if (remainder < 10)
				hex_digits[i] = remainder + '0';
			else
				hex_digits[i] = 'a' + (remainder - 10);
			address /= 16;
		}

		for (i -= 1; i >= 0; i--)
		{
			_putchar(hex_digits[i]);
			counter++;
		}
	}

	return counter;
}

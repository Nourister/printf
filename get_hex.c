#include "main.h"

/**
 * print_hex_str - converts the number from base 10 to hex
 * @n: number to be converted
 * @hex: base of 16 being passed
 * @alpha: Char 'A' to 'F' or 'a' to 'f'
 * Return: number of chars printed
 */
int print_hex_str(unsigned int hex, unsigned int n, char alpha)
{
	unsigned int k = n % hex;
	unsigned int i = n / hex;
	char l;

	if (k > 10)
		l = (k - 10) + alpha;
	else
		l = k + '0';
	if (i == 0)
	{
		return (_putchar(l));
	}
	if (i < hex)
	{
		if (i > 10)
			return (_putchar(i - 10 + alpha) + _putchar(l));
		return (_putchar(i + '0') + _putchar(l));
	}
	return (print_hex_str(i, hex, alpha) + _putchar(l));
}

/**
 * _hex_l - printing lower case hex numbers
 * @hex: argument received
 * Return: number of char printed
 */
int _hex_l(va_list hex)
{
	return (print_hex_str(va_arg(hex, unsigned int), 16, 'a'));
}

/**
 * _hex_u - printing upper case hex numbers
 * @hex: argument received
 * Return: number of char printed
 */
int _hex_u(va_list hex)
{
	return (print_hex_str(va_arg(hex, unsigned int), 16, 'A'));
}

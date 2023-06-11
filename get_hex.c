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
	unsigned int a = n % hex;
	unsigned int b = n / hex;
	char c;

	if (a > 10)
		c = (a - 10) + alpha;
	else
		c = a + '0';
	if (b == 0)
	{
		return (_putchar(c));
	}
	if (b < hex)
	{
		if (b > 10)
			return (_putchar(b - 10 + alpha) + _putchar(c));
		return (_putchar(b + '0') + _putchar(c));
	}
	return (print_hex_str(b, hex, alpha) + _putchar(c));
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

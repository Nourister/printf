#include "main.h"

/**
 * print_ui - unsigned int printed to stdout
 * @uni: unsigned list being passed
 * Return: character count
 */
int print_ui(va_list uni)
{
	unsigned int a;
	int expo = 1;
	int len = 0;

	a = va_arg(uni, unsigned int);

	while (a / expo > 9)
		expo *= 10;
	while (expo != 0)
	{
		len = len + _putchar(a / expo + '0');
		a = a % expo;
		expo = expo / 10;
	}
	return (len);
}

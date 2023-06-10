#include "main.h"

/**
 * print_int - function to print integers
 * @index: list printed
 * Return: Return count
 */
int print_int(va_list index)
{
	int l, expo = 1, len = 0;
	unsigned int i;

	l = va_arg(index, int);

	if (l < 0)
	{
		len = len + _putchar('-');
		i = l * -1;
	}
	else
		i = l;
	while (i / expo > 9)
		expo *= 10;

	while (expo != 0)
	{
		len = len + _putchar(i / expo + '0');
		i = i % expo;
		expo = expo / 10;
	}
	return (len);
}

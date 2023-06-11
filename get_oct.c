#include "main.h"

/**
 * print_oct - function to print octal numbers
 * @octa: list being passed
 * Return: updated counter
 */
int print_oct(va_list octa)
{
	int counter = 0, n;
	int *arr;
	unsigned int l = va_arg(octa, unsigned int);
	unsigned int tmp = l;

	while (l / 8 != 0)
	{
		l /= 8;
		counter++;
	}
	counter++;
	arr = malloc(counter * sizeof(int));
	for (n = 0; n < counter; n++)
	{
		arr[n] = tmp % 8;
		tmp /= 8;
	}
	for (n = counter - 1; n >= 0; n--)
	{
		_putchar(arr[n] + '0');
	}
	free(arr);
	return (counter);
}

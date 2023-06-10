#include "main.h"

/**
 * print_bin - function to print binary
 * @bin: list being passed
 * Return: updated count return
 */
int print_bin(va_list bin)
{
	int counter = 0, n;
	int *arr;
	unsigned int l = va_arg(bin, unsigned int);
	unsigned int tmp = l;

	while (l / 2 != 0)
	{
		l /= 2;
		counter++;
	}
	counter++;
	arr = malloc(counter * sizeof(int));
	if (arr == NULL)
	{
		free(arr);
		return (0);
	}
	for (n = 0; n < counter; n++)
	{
		arr[n] = tmp % 2;
		tmp /= 2;
	}
	for (n = counter - 1; n >= 0; n--)
	{
		_putchar(arr[n] + '0');
	}
	free(arr);
	return (counter);
}

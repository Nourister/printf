#include "main.h"

/**
 * print_strlen - prints string length
 * @str: string to be passed
 * Return: length in int
 */

int print_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

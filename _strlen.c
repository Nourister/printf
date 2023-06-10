#include "main.h"

/**
 * print_strlen - gets string length
 * @str: string
 * Return: length (int)
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

#include "main.h"

/**
 * _rot13 - prints rot13 version
 * @rot: list being passed
 * Return: count of chars
 */
int print_rot13(va_list rot)
{
	int n, counter;
	char *str;

	n = counter = 0;
	str = va_arg(rot, char *);

	if (str == NULL)
		return (-1);
	while (str[n] != '\0')
	{
		if ((str[n] >= 'a' && str[n] <= 'z') ||
		    (str[n] >= 'A' && str[n] <= 'Z'))
		{
			if ((str[n] >= 'n' && str[n] <= 'z') ||
			    (str[n] >= 'N' && str[n] <= 'Z'))
				counter = counter + _putchar(str[n] - 13);
			else
				counter = counter + _putchar(str[n] + 13);
		}
		else
			counter = counter + _putchar(str[n]);
		n++;
	}
	return (counter);
}

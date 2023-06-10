#include "main.h"

/**
 * print_char - function to return char
 * @character: list given
 * Return: number of char printed
 */
int print_char(va_list character)
{
	return (_putchar(va_arg(character, int)));
}

#include "main.h"

/**
 * print_char - function to print and return char
 * @character: given list
 * Return: number of char printed
 */
int print_char(va_list character)
{
	return (_putchar(va_arg(character, int)));
}

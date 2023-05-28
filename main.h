/* MAIN_H FILES */

#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct specifier - struct for conversion specifiers
 * and their corresponding functions
 * @specifier: the conversion specifier
 * character 's' 'c' 'd' 'i' and symbol '%'
 * @function: pointer to the corresponding printing function
 */

typedef struct specifier
{
	char specifier;
	int (*function)(va_list);
} specifier_t;

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 * Return: 1 on success, -1 on error
 */

int _putchar(char c);

/**
 * _printf - custom printf function
 * @format: format string
 *
 * Description: Produces output according to a format string
 *              with the following conversion specifiers: c, s, %, d, i
 *
 * Return: Number of characters printed (excluding null byte)
 */

int _printf(const char *format, ...);

/**
 * print_char - print a character
 * @arg: argument containing the character to print
 * Return: number of characters printed
 */

int print_char(va_list my_args);

/**
 * print_string - print a string
 * @arg: argument containing the string to print
 * Return: number of characters printed
 */

int print_string(va_list my_args);

/**
 * print_int - print an integer
 * @arg: argument containing the integer to print
 * Return: number of characters printed
 */

int print_int(va_list my_args);


int print_number(int n);

#endif /* MAIN_H */

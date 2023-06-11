#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct fmt - function to check for formats
 * @type: The format to print
 * @f: The print function to use as apointer
 */
typedef struct fmt
{
	char *type;
	int (*f)();
} fmt_t;

int _printf(const char *format, ...);
int print_op(const char *format, fmt_t *print_arr, va_list my_list);
int print_char(va_list character);
int _str(va_list string);
int print_int(va_list index);
int print_ui(va_list uni);
int print_oct(va_list octa);
int print_rot13(va_list rot);
int print_hex_str(unsigned int hexa, unsigned int n, char alpha);
int _hex_l(va_list hex);
int _hex_u(va_list hex);
int print_strlen(char *str);
int print_bin(va_list bin);
int _putchar(char c);
#endif

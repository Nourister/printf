/* MAIN_H FILES */

#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


typedef struct specifier
{
	char specifier;
	int (*function)(va_list);
} specifier_t;


int _putchar(char c);

int _printf(const char *format, ...);

int print_char(va_list my_args);

int print_string(char *str);

int print_int(va_list my_args);

int print_number(int n);

unsigned int print_unsigned(va_list my_args)

int print_octal(unsigned int n);

int print_hexadecimal(unsigned int n, char format);

int print_address(void *p);

int main(void);

int print_decimal(int num);

int handle_format_specifier(char specifier, va_list my_args, int *counter);

#endif /* MAIN_H */

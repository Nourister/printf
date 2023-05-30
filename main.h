/* MAIN_H FILES */

#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

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

int handle_format_specifier(char specifier, va_list my_args, int *counter);

unsigned int print_unsigned(va_list my_args);

unsigned int print_unsigned_va_list(va_list my_args);

unsigned int print_octal(va_list my_args);

int print_address(void *p);

int main(void);

int handle_format_specifier(char specifier, va_list my_args, int *counter);

void flush_buffer(char *buffer, int *buf_index, int *counter);

unsigned int print_custom_string(char *str);

unsigned int _putchar_hex(unsigned char c);

unsigned int print_hexadecimal(va_list my_args, char specifier);
unsigned int print_decimal(int num);

#endif /* MAIN_H */

/* MAIN_H FILES */

#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024


/* Functions */

int _putchar(char c);

int _printf(const char *format, ...);

int handle_printf(const char *format, ...);

#endif /* MAIN_H */

#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - print function
 * @format: format used
 * @...:indicates any number of arguments to be passed
 * Return: printed character
 */
int _printf(const char *format, ...)
{
	va_list my_args;
	int counter = 0;

	va_start(my_args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
                break;

            switch (*format)
            {
                case 'c':
                {
                    char c = (char)va_arg(my_args, int);
                    putchar(c);
                    counter++;
                    break;
                }
                case 's':
                {
                    char *str = va_arg(my_args, char *);
                    while (*str)
                    {
                        putchar(*str);
                        str++;
                        counter++;
                    }
                    break;
                }
                case '%':
                {
                    putchar('%');
                    counter++;
                    break;
                }
                case 'd':
                case 'i':
                {
                    int num = va_arg(my_args, int);
                    printf("%d", num);
                    counter += snprintf(NULL, 0, "%d", num);
                    break;
                }
                case 'u':
                {
                    unsigned int num = va_arg(my_args, unsigned int);
                    printf("%u", num);
                    counter += snprintf(NULL, 0, "%u", num);
                    break;
                }
                case 'o':
                {
                    unsigned int num = va_arg(my_args, unsigned int);
                    printf("%o", num);
                    counter += snprintf(NULL, 0, "%o", num);
                    break;
                }
                case 'x':
                {
                    unsigned int num = va_arg(my_args, unsigned int);
                    printf("%x", num);
                    counter += snprintf(NULL, 0, "%x", num);
                    break;
                }
                case 'X':
                {
                    unsigned int num = va_arg(my_args, unsigned int);
                    printf("%X", num);
                    counter += snprintf(NULL, 0, "%X", num);
                    break;
                }
                case 'b':
                {
                    unsigned int num = va_arg(my_args, unsigned int);
                    printf("%b", num);
                    counter += snprintf(NULL, 0, "%b", num);
                    break;
                }
                case 'S':
                {
                    char *str = va_arg(my_args, char *);
                    while (*str)
                    {
                        if (*str < 32 || *str >= 127)
                        {
                            putchar('\\');
                            putchar('x');
                            printf("%02X", *str);
                            counter += 4;
                        }
                        else
                        {
                            putchar(*str);
                            counter++;
                        }
                        str++;
                    }
                    break;
                }
                case 'p':
                {
                    void *ptr = va_arg(my_args, void *);
                    printf("%p", ptr);
                    counter += snprintf(NULL, 0, "%p", ptr);
                    break;
                }
                case 'r':
                {
                    char *str = va_arg(my_args, char *);
                    int len = 0;
		    int i = 0;
                    while (str[len])
                        len++;
                    for (i = len - 1; i >= 0; i--)
                    {
                        putchar(str[i]);
                        counter++;
                    }
                    break;
                }
                case 'R':
                {
                    char *str = va_arg(my_args, char *);
                    while (*str)
                    {
                        char c = *str;
                        if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
                            c += 13;
                        else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
                            c -= 13;
                        putchar(c);
                        counter++;
                        str++;
                    }
                    break;
                }
                default:
                    putchar('%');
                    putchar(*format);
                    counter += 2;
                    break;
            }
        }
        else
        {
            putchar(*format);
	    counter++;
        }
        format++;
    }
    
    va_end(my_args);
    
    return (counter);
}

/*int main()
{
	_printf("Hello, %s! Today is %d-%d-%d\n", "John", 27, 5, 2023);
	_printf("Binary: %b\n", 42);
	_printf("String: %S\n", "Hello\nWorld");
	_printf("Pointer: %p\n", &main);
    _printf("Reversed: %r\n", "Hello");
    _printf("ROT13: %R\n", "Hello");
    
    return 0;
}*/


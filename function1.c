#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer
 * @my_args: The va_list of arguments
 *
 * Return: The number of characters printed
 */
unsigned int print_unsigned(unsigned int num)
{
	unsigned int num = va_arg(my_args, unsigned int);
	unsigned int counter = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		unsigned int digit = num % 10;

		_putchar(digit + '0');
		num = num / 10;
		counter++;
	}

	return (counter);
}

/**
 * print_unsigned_va_list - Wrapper function to print
 * an unsigned integer using va_list
 * @my_args: The va_list of arguments
 *
 * Return: The number of characters printed
 */
unsigned int print_unsigned_va_list(va_list my_args)
{
	unsigned int n = va_arg(my_args, unsigned int);
	return (print_unsignedint(num));
}

/**
 * print_octal - Prints an unsigned integer in octal format
 * @n: The unsigned integer to print
 *
 * Return: The number of characters printed
 */
int print_octal(unsigned int n)
{
	unsigned int num = n;
	int counter = 0;
	char octal_digits[100]; /* Assuming a maximum of 100 octal digits */

	do {
		octal_digits[counter] = (num % 8) + '0';
		num /= 8;
		counter++;
	} while (num != 0);

	while (counter > 0)
	{
		_putchar(octal_digits[counter - 1]);
		counter--;
	}
	return (counter);
}

/**
 * print_hexadecimal - prints unsigned integer in hexadecimal form
 * @n: unsigned integer to print
 * @format: format specifier ('x' or 'X')
 * Return: number of characters printed
 */
int print_hexadecimal(unsigned int n, char format)
{
	unsigned int rem;
	char hex[100];

	int i = 0, counter = 0;

	if (n == 0)
	{
		_putchar('0');
		counter++;
	}
	else
	{
		while (n != 0)
		{
			rem = n % 16;
			hex[i] = (rem < 10) ? (rem + '0') : (rem + (
			format == 'x' ? 'a' : 'A') - 10);
			n /= 16;
			i++;
		}

		for (i = i - 1; i >= 0; i--)
		{
			_putchar(hex[i]);
			counter++;
		}
	}

	return (counter);
}

/**
 * flush_buffer - Writes the buffer contents to the output and resets the buffer.
 * @buffer: The buffer containing the characters to be written.
 * @buf_index: The current index in the buffer.
 * @counter: The current counter value.
 */
void flush_buffer(char *buffer, int *buf_index, int *counter)
{
    int i;

    for (i = 0; i < *buf_index; i++)
    {
        _putchar(buffer[i]);
    }

    *counter += *buf_index;
    *buf_index = 0;
    memset(buffer, 0, sizeof(buffer));
}

/**
 * print_address - Prints a memory address
 * @p: The pointer to the memory address to print
 *
 * Return: The number of characters printed
 */
int print_address(void *p)
{
	unsigned long int address = (unsigned long int)p;
	int counter = 0;
	char hex_digits[16]; /* Assuming a maximum of 16 hexadecimal digits */
	int i;

	_putchar('0');
	_putchar('x');
	counter += 2;

	if (address == 0)
	{
		_putchar('0');
		counter++;
	}
	else
	{
		for (i = 0; address != 0; i++)
		{
			int remainder = address % 16;

			if (remainder < 10)
				hex_digits[i] = remainder + '0';
			else
				hex_digits[i] = 'a' + (remainder - 10);
			address /= 16;
		}

		for (i -= 1; i >= 0; i--)
		{
			_putchar(hex_digits[i]);
			counter++;
		}
	}
	return (counter);
}

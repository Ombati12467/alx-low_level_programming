#include "main.h"
#include <unistd.h>

/**
 * print_binary_recursive - Prints binary representation using recursion.
 * @n: The number to print in binary.
 */
void print_binary_recursive(unsigned long int n)
{
	if (n == 0)
		return;

	print_binary_recursive(n >> 1);
	_putchar((n & 1) + '0');
}

/**
 * print_binary - Prints the binary representation of an unsigned long integer.
 * @n: The number to print in binary.
 */
void print_binary(unsigned long int n)
{
	if (n == 0)
	{
		_putchar('0');
		return;
	}

	print_binary_recursive(n);
}

int _putchar(char c)
{
	return (write(1, &c, 1));
}

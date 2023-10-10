#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The unsigned long integer to be printed in binary.
 *  Recursively shift right and print each bit
 *  Print the least significant bit as '0' or '1'
 */
void print_binary(unsigned long int n)
{
	if (n > 1)
	{
		print_binary(n >> 1);
	}
	_putchar((n & 1) + '0');
}

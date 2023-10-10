#include "main.h"

/**
 * get_bit - Gets the value of a bit at a given index.
 * @n: The unsigned long integer containing the bit.
 * @index: The index of the bit to retrieve (starting from 0).
 * Return: The value of the bit at  specified index or -1 if error occurs.
 * Right-shift n by index positions to bring the bit of interest to the LSB
 * Check if the index is out of bounds
 * Use bitwise AND to extract the LSB (the bit at the specified index)
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	n >>= index;

	return (n & 1);
}

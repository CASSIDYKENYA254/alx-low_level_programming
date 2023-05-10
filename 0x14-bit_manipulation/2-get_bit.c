#include "main.h"

/**
 * get_bit - Get value of a bit at given index
 * @index: the index
 * @n: the range
 * Return: If an error occurs - -1.
 * otherwise - The value of bit at index.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	if ((n & (1 << index)) == 0)
		return (0);

	return (1);
}

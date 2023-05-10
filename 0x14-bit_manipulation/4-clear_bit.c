#include "main.h"

/**
 * clear_bit - sets the value of a bit at a given index to 0.
 * @index: the index to set the value at  - insices start at 0.
 * @n: a pointer to the bit.
 * Return: if an error occurs - -1.
 * otherwise - 1.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (1);
	}

	*n &= ~(1UL << index);

	return (1);
}

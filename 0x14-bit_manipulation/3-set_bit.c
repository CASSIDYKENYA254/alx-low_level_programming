#include <stdio.h>
#include "main.h"

/**
 * set_bit - set a bit at a given index
 * @index: the index
 * @n: the range
 * Description: a bit is set at a given index
 * Return: status 0
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n ^= (1 << index);

	return (1);
}

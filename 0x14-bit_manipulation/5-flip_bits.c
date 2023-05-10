#include "main.h"
/**
 * flip_bits - counts  number of bits needed to be
 * flipped to get from a number to another.
 * @n: a number 1
 * @m: a number 2
 * Return: Number of bits to flip from n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int difference = n ^ m;
	unsigned int counter = 0;

	while (difference)
	{
		counter += difference & 1;
		difference >>= 1;
	}
	return (counter);
}

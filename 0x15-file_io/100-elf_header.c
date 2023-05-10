#include <stdio.h>
#include <systa.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void check_elf(unsigned char *e_ident);
void close_elf(int elf);
void print_magic(unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);

/**
 * check_elf - Checks if a file is in an ELF 
 * @e_ident: A pointer to an array containing the ELF magic numbers
 * Description: If the file is not an elf - exit code 98
 */
void check_elf(unsigned char *e_ident)
	int index;

	for (index = 0; index < 4; index++)
{
	if (e_ident[index] != 127 &&
			e_ident[index] != 'E' &&
			e_ident[index] != 'L' &&
			e_ident[index] != 'F')
	{
		dprint


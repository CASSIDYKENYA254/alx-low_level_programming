#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

/**
 * read_textfile - reading the contents from files
 * @letters:to be read and printed
 * @filename: file with letters
 * Return: Number of letters read, 0 (Fail)
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int lettersoffile;
	ssize_t a, b;
	char *printletters;

	if (!filename)
		return (0);
	lettersoffile = open(filename, O_RDONLY);
	if (lettersoffile == -1)
		return (0);
	printletters = malloc(sizeof(char) * (letters));
	if (!printletters)
		return (0);
	a = read(lettersoffile, printletters, letters);
	if (a == -1)
		return (0);
	b = write(STDOUT_FILENO, printletters, a);
	free(printletters);
	close(lettersoffile);
	return (b);
}

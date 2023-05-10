#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
/**
 * error_file - checks if file can be copied
 * @file_to: destination
 * @file_from: source
 * @argv: argument vectors
 * Return: None
 */
void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}
/**
 * main - checks code
 * @argv: vector for argument
 * @argc: numbers of arg
 * Return: O(Success)
 */
int main(int argc, char *argv[])
{
	int file_to;
	int file_from;
	int closingError;
	ssize_t a, b;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}
	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(file_from, file_to, argv);

	a = 1024;
	while (a == 1024)
	{
		a = read(file_from, buf, 1024);
		if (a == -1)
			error_file(-1, 0, argv);
		b = write(file_to, buf, a);
		if (b == -1)
			error_file(0, -1, argv);
	}
	closingError = close(file_from);
	if (closingError == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}

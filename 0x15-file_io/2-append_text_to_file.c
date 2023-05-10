#include "main.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
/**
 * append_text_to_file - appends toxt to file
 * @filename: name of file to be read
 * @text_content: NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int newfile, oldfile, fillen;
	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		oldfile = open(filename, O_WRONLY | O_APPEND);
		if (oldfile == -1)
			return (-1);
		fillen = 0;
		while (*(text_content + fillen) != '\0')
			fillen++;
		newfile = write(oldfile, text_content, fillen);
		if (newfile == -1)
		{
			close(oldfile);
			write(STDOUT_FILENO, "fails", 5);
			return (-1);
		}
	}
	close(oldfile);
	return (-1);
}

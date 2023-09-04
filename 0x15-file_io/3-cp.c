#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024

/**
 * print_usage_error - Print usage error message and exit with code 97.
 * @progname: The name of the program.
 */
void print_usage_error(const char *progname)
{
	dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", progname);
	exit(97);
}

/**
 * print_read_error - Print read error message and exit with code 98.
 * @filename: The name of the file that couldn't be read.
 */
void print_read_error(const char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	exit(98);
}

/**
 * print_write_error - Print write error message and exit with code 99.
 * @filename: The name of the file that couldn't be written to.
 */
void print_write_error(const char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", filename);
	exit(99);
}

/**
 * print_close_error - Print close error message and exit with code 100.
 * @fd: The file descriptor that couldn't be closed.
 */
void print_close_error(int fd)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
}

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: 0 on success, or an exit code on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, bytes_read, bytes_written;
	char buffer[BUFSIZE];

	if (argc != 3)
		print_usage_error(argv[0]);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_read_error(argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		print_write_error(argv[2]);
	}

	while ((bytes_read = read(fd_from, buffer, BUFSIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			close(fd_from);
			close(fd_to);
			print_write_error(argv[2]);
		}
	}

	if (bytes_read == -1)
	{
		close(fd_from);
		close(fd_to);
		print_read_error(argv[1]);
	}

	if (close(fd_from) == -1 || close(fd_to) == -1)
		print_close_error((fd_from == -1) ? fd_to : fd_from);

	return (0);
}

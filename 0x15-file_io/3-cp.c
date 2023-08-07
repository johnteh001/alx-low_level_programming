#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

void print_error_and_exit(int code, const char *message, const char *file)
{
	dprintf(STDERR_FILENO, message, file);
	exit(code);
}
/**
 * main - Copies the content of a file to another file.
 *
 * @argc: The number of arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;
	ssize_t bytes_read, bytes_written;
	char file_from_str[12], file_to_str[12];
	char buffer[BUF_SIZE];

	if (argc != 3)
		print_error_and_exit(97, "Usage: cp file_from file_to\n", "");
	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		print_error_and_exit(98, "Error: Can't read from file %s\n", argv[1]);
	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
		print_error_and_exit(99, "Error: Can't write to %s\n", argv[2]);
	while ((bytes_read = read(file_from, buffer, BUF_SIZE)) > 0)
	{
		bytes_written = write(file_to, buffer, bytes_read);
		if (bytes_written != bytes_read || bytes_written == -1)
			print_error_and_exit(99, "Error: Can't write to %s\n", argv[2]);
	}
	if (bytes_read == -1)
		print_error_and_exit(98, "Error: Can't read from file %s\n", argv[1]);
	sprintf(file_from_str, "%d", file_from);
	if (close(file_from) == -1)
		print_error_and_exit(100, "Error: Can't close fd %s\n", file_from_str);
	sprintf(file_to_str, "%d", file_to);
	if (close(file_to) == -1)
		print_error_and_exit(100, "Error: Can't close fd %s\n", file_to_str);
	return (0);
}

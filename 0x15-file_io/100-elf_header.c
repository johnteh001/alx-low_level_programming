#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_error_and_exit - Prints an error message to stderr
 * and exits the program with the specified code.
 * @code: The exit code to be used when terminating the program.
 * @message: The format string for the error message. It
 * may contain format specifiers (e.g., %s, %d) to be
 * replaced by the provided arguments.
 * @file: The name of the file associated with the error.
 * It is used to provide more context in the error message.
 */
void print_error_and_exit(int code, const char *message, const char *file)
{
	dprintf(STDERR_FILENO, message, file);
	exit(code);
}
/**
 * main - Display the information contained in the ELF header of an ELF file.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line arguments. The first argumen
 * should be the name of the ELF file to examine.
 * Return: 0 on success, 98 on failure (not an ELF file or
 * error reading), or other error codes as needed.
 */
int main(int argc, char *argv[])
{
	int fd, bytes_read;
	Elf64_Ehdr elf_header;
	char *elf_class[] = {"None", "ELF32", "ELF64"};
	char *elf_data[] = {"None", "2's complement, little endian", "2's complement, big endian"};char *elf_osabi[] = {"UNIX - System V", "HP-UX", "NetBSD", "GNU", "Solaris", "AIX", "IRIX","FreeBSD", "Tru64", "Novell Modesto", "OpenBSD", "OpenVMS", "NonStop Kernel","AROS", "Fenix OS", "CloudABI", "OpenVOS"};
	char *elf_type[] = {"None", "REL (Relocatable file)", "EXEC (Executable file)","DYN (Shared object file)", "CORE (Core file)"};
	if (argc != 2)
		print_error_and_exit(98, "Usage: %s elf_filename\n", "");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error_and_exit(98, "Error: Can't read from file %s\n", argv[1]);
	bytes_read = read(fd, &elf_header, sizeof(Elf64_Ehdr));
	if (bytes_read != sizeof(Elf64_Ehdr))
		print_error_and_exit(98, "Error: Can't read from file %s\n", argv[1]);
	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 || elf_header.e_ident[EI_MAG1] != ELFMAG1 ||elf_header.e_ident[EI_MAG2] != ELFMAG2 || elf_header.e_ident[EI_MAG3] != ELFMAG3)print_error_and_exit(98, "Error: Not an ELF file: %s\n", argv[1]);
	printf("ELF Header:\n");
	printf("  Magic:   %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",elf_header.e_ident[EI_MAG0], elf_header.e_ident[EI_MAG1], elf_header.e_ident[EI_MAG2], elf_header.e_ident[EI_MAG3],elf_header.e_ident[EI_CLASS], elf_header.e_ident[EI_DATA], elf_header.e_ident[EI_VERSION], elf_header.e_ident[EI_OSABI],elf_header.e_ident[EI_ABIVERSION], elf_header.e_ident[EI_PAD], elf_header.e_ident[EI_PAD], elf_header.e_ident[EI_PAD],elf_header.e_ident[EI_PAD], elf_header.e_ident[EI_PAD], elf_header.e_ident[EI_PAD], elf_header.e_ident[EI_PAD]);
	printf("  Class:                             %s\n", elf_class[elf_header.e_ident[EI_CLASS]]);
	printf("  Data:                              %s\n", elf_data[elf_header.e_ident[EI_DATA]]);
	printf("  Version:                           %d (current)\n", elf_header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n", elf_osabi[elf_header.e_ident[EI_OSABI]]);
	printf("  ABI Version:                       %d\n", elf_header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n", elf_type[elf_header.e_type]);
	printf("  Entry point address:               0x%lx\n", (unsigned long)elf_header.e_entry);
	close(fd);
	return (0);
}

#include "0-hreadelf.h"
#include <stdio.h> /* fprintf fopen */
#include <string.h>

static void print_format(output_t *ptr);

int readfile(header_t *header, char *filename);
int getoutput(output_t *output, header_t *header);

/**
 * main - displays the information contained in the ELF file header.
 * @argc: argument counter, must be 1
 * @argv: filename
 * Return: 0=Success, Otherwise=Error
 */
int main(int argc, char *argv[])
{
	header_t header;
	output_t output;
	unsigned char magic[4] = {0x7f, 0x45, 0x4c, 0x46};


	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (1);
	}

	if (readfile(&header, argv[1]))
		return (1);



	if (memcmp(header.h64.e_ident, magic, 4))
	{
		fprintf(stderr, "readelf: Error: Not an ELF file - ");
		fprintf(stderr, "it has the wrong magic bytes at the start\n");
		return (1);
	}

	getoutput(&output, &header);

	print_format(&output);

	return (0);
}
/**
 * readfile - read file and fill the header
 * @header: union of header
 * @filename: string with path
 * Return: 0 OK, Otherwise Failure
 */
int readfile(header_t *header, char *filename)
{
	FILE *file;

	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "readelf: Error: '%s': No such file\n", filename);
		return (1);
	}
	fread(header, sizeof(*header), 1, file);
	fclose(file);
	return (0);
}

/**
 * getoutput - get output format
 * @output: destiny
 * @header: input union
 * Return: 0 Success, Otherwise failure
 */
int getoutput(output_t *output, header_t *header)
{
	if (header->h64.e_ident[EI_CLASS] == ELFCLASS64)
	{
		output->e_ident = header->h64.e_ident;
		output->e_type = header->h64.e_type;
		output->e_machine = header->h64.e_machine;
		output->e_version = header->h64.e_version;
		output->e_entry = header->h64.e_entry;
		output->e_phoff = header->h64.e_phoff;
		output->e_shoff = header->h64.e_shoff;
		output->e_flags = header->h64.e_flags;
		output->e_ehsize = header->h64.e_ehsize;
		output->e_phentsize = header->h64.e_phentsize;
		output->e_phnum = header->h64.e_phnum;
		output->e_shentsize = header->h64.e_shentsize;
		output->e_shnum = header->h64.e_shnum;
		output->e_shstrndx = header->h64.e_shstrndx;
	}
	else if (header->h64.e_ident[EI_CLASS] == ELFCLASS32)
	{
		output->e_ident = header->h32.e_ident;
		output->e_type = header->h32.e_type;
		output->e_machine = header->h32.e_machine;
		output->e_version = header->h32.e_version;
		output->e_entry = header->h32.e_entry;
		output->e_phoff = header->h32.e_phoff;
		output->e_shoff = header->h32.e_shoff;
		output->e_flags = header->h32.e_flags;
		output->e_ehsize = header->h32.e_ehsize;
		output->e_phentsize = header->h32.e_phentsize;
		output->e_phnum = header->h32.e_phnum;
		output->e_shentsize = header->h32.e_shentsize;
		output->e_shnum = header->h32.e_shnum;
		output->e_shstrndx = header->h32.e_shstrndx;
	}
	else
	{
		memset(output, 0, sizeof(*output));
		return (1);
	}
	return (0);
}

/**
 * print_format - print format
 * @ptr: poiner to element
 */
static void print_format(output_t *ptr)
{
	char *tmp;
	int i, byte;
	char *class[] = {"nil", "ELF32", "ELF64"};
	char *data[] = {
		"nil",
		"2's complement, little endian",
		"2's complement, big endian"
	};
	char *type[] = {
		"nil",
		"Relocatable file",
		"EXEC (Executable file)",
		"DYN (Shared object file)"
	};

	char *machine[] = {
		"nil",
		"Advanced Micro Devices X86-64",
		"Intel 80386",
		"Sparc",
		"ARM",
	};
	char *osiabis[] = {
		"UNIX - System V",
		"UNIX - Linux",
		"UNIX - NetBSD",
		"UNIX - Solaris"
	};

	puts("ELF Header:");

	printf("  %-9s", "Magic: ");
	for (i = 0; i < 16; i++)
		printf("%02x ", ptr->e_ident[i]);
	puts("");

	tmp = class[ptr->e_ident[EI_CLASS]];
	printf("  %-35s%s\n", "Class:", tmp);

	tmp = data[ptr->e_ident[EI_DATA]];
	printf("  %-35s%s\n", "Data:", tmp);

	byte = ptr->e_ident[EI_VERSION];
	if (byte == EV_CURRENT)
		tmp = "1 (current)";
	else
		tmp = "Invalid version";
	printf("  %-35s%s\n", "Version:", tmp);

	byte = ptr->e_ident[EI_OSABI];
	if (byte == ELFOSABI_NETBSD)
		tmp = osiabis[1];
	else if (byte == ELFOSABI_LINUX)
		tmp = osiabis[2];
	else if (byte == ELFOSABI_SOLARIS)
		tmp = osiabis[3];
	else
		tmp = osiabis[0];
	printf("  %-35s%s\n", "OS/ABI:", tmp);
	printf("  %-35s%d\n", "ABI Version:", ptr->e_ident[EI_ABIVERSION]);

	tmp = type[ptr->e_type];
	printf("  %-35s%s\n", "Type:", tmp);

	byte = ptr->e_machine;
	if (byte == EM_X86_64)
		tmp = machine[1];
	else if (byte == EM_386)
		tmp = machine[2];
	else if (byte == EM_ARM)
		tmp = machine[4];
	else
		tmp = machine[3];
	printf("  %-35s%s\n", "Machine:", tmp);
	printf("  %-35s0x%x\n", "Version:", ptr->e_version);
	printf("  %-35s0x%lx\n", "Entry point address:", ptr->e_entry);
	printf("  %-35s%d ", "Start of program headers:", (int)ptr->e_phoff);
	printf("(bytes into file)\n");
	printf("  %-35s%d ", "Start of section headers:", (int)ptr->e_shoff);
	printf("(bytes into file)\n");
	printf("  %-35s0x%x\n", "Flags:", (int)ptr->e_flags);
	printf("  %-35s%d (bytes)\n", "Size of this header:", (int)ptr->e_ehsize);
	printf("  %-35s", "Size of program headers:");
	printf("%d (bytes)\n", (int)ptr->e_phentsize);
	printf("  %-35s%d\n", "Number of program headers:", (int)ptr->e_phnum);
	printf("  %-35s", "Size of section headers:");
	printf("%d (bytes)\n", (int)ptr->e_shentsize);
	printf("  %-35s%d\n", "Number of section headers:", ptr->e_shnum);
	printf("  %-35s", "Section header string table index:");
	printf("%d\n", ptr->e_shstrndx);

}

#include <stdio.h> /* fprintf fopen */
#include <string.h>
#include <elf.h>

static void print_format(Elf64_Ehdr *ptr);

/**
 * main - displays the information contained in the ELF file header.
 * @argc: argument counter, must be 1
 * @argv: filename
 * Return: 0=Success, Otherwise=Error
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr header;
	FILE *file;
	unsigned char magic[4] = {0x7f, 0x45, 0x4c, 0x46};


	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (1);
	}
	memset(&header, 0, sizeof(header));
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "readelf: Error: '%s': No such file\n", argv[1]);
		return (1);
	}
	fread(&header, sizeof(header), 1, file);
	fclose(file);

	if (memcmp(header.e_ident, magic, 4))
	{
		fprintf(stderr, "readelf: Error: Not an ELF file - ");
		fprintf(stderr, "it has the wrong magic bytes at the start\n");
		return (1);
	}

	print_format(&header);

	return (0);
}


/**
 * print_format - print format
 * @ptr: poiner to element
 */
static void print_format(Elf64_Ehdr *ptr)
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
		tmp = "UNIX - NetBSD";
	else if (byte == ELFOSABI_LINUX)
		tmp = "UNIX - Linux";
	else
		tmp = "UNIX - System V";
	printf("  %-35s%s\n", "OS/ABI:", tmp);
	printf("  %-35s%d\n", "ABI Version:", ptr->e_ident[EI_ABIVERSION]);

	tmp = type[ptr->e_type];
	printf("  %-35s%s\n", "Type:", tmp);

	byte = ptr->e_machine;
	if (byte == EM_X86_64)
		tmp = machine[1];
	else if (byte == EM_386)
		tmp = machine[2];
	else
		tmp = machine[3];
	printf("  %-35s%s\n", "Machine:", tmp);
	printf("  %-35s0x%x\n", "Version:", ptr->e_version);
	printf("  %-35s%p\n", "Entry point address:", (void *)ptr->e_entry);
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

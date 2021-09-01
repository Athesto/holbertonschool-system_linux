#ifndef _0_HREADELF_H_
#define _0_HREADELF_H_
#include <elf.h>
/**
 * union header_u - union of elf headers
 * @h64: elf header 64bits
 * @h32: elf header 32bits
 */
typedef union header_u
{
	Elf64_Ehdr h64;
	Elf32_Ehdr h32;
} header_t;

/**
 * struct output_s - output string
 * @e_ident: file interpreter, array
 * @e_type: object file type
 * @e_machine: machine output
 * @e_version: current version
 * @e_entry: input address
 * @e_phoff: offset1
 * @e_shoff: offset2
 * @e_flags: flags
 * @e_ehsize: header size
 * @e_phentsize: size of one entry
 * @e_phnum: Number of entries
 * @e_shentsize: section header's size
 * @e_shnum: Number of entries2
 * @e_shstrndx: another thing
 */
typedef struct output_s
{
	unsigned char *e_ident;
	uint16_t      e_type;
	uint16_t      e_machine;
	uint32_t      e_version;
	unsigned long      e_entry;
	uint32_t      e_phoff;
	uint32_t      e_shoff;
	uint32_t      e_flags;
	uint16_t      e_ehsize;
	uint16_t      e_phentsize;
	uint16_t      e_phnum;
	uint16_t      e_shentsize;
	uint16_t      e_shnum;
	uint16_t      e_shstrndx;
} output_t;

#endif /* _0_HREADELF_H_ */

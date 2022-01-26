#ifndef __COMMON_MEMBLOCK_H
#define __COMMON_MEMBLOCK_H

#include <common.h>

void memblock_init(void);

int memblock_add(phys_addr_t base, phys_addr_t size);
int memblock_remove(phys_addr_t base, phys_addr_t size);

void *memblock_alloc(phys_addr_t size,  phys_addr_t align);
int memblock_free(phys_addr_t base, phys_addr_t size);

void memblock_print_all_region(void);
int memblock_test(void);

#endif /* __COMMON_MEMBLOCK_H */
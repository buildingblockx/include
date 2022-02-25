#ifndef __MEMORY_MODEL_H
#define __MEMORY_MODEL_H

#include <types.h>

/*
 * Convert a virtual address to/from a physical address
 *
 * flat memory model
 */
#define PHYS_VIRT_OFFSET 0x0

static inline phys_addr_t virt_to_phys(void *vaddr)
{
	return (phys_addr_t)((unsigned long)vaddr - PHYS_VIRT_OFFSET);
}

static inline void *phys_to_virt(phys_addr_t paddr)
{
	return (void *)(paddr + PHYS_VIRT_OFFSET);
}

#endif

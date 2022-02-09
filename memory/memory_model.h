#ifndef __MEMORY_MODEL_H
#define __MEMORY_MODEL_H

/*
 * Convert a virtual address to/from a physical address
 */

#include <types.h>

/*
 * flat memory model
 */
#define PHYS_VIRT_OFFSET 0x0

static inline phys_addr_t virt_to_phys(virt_addr_t vaddr)
{
	return (phys_addr_t)((unsigned long)vaddr - PHYS_VIRT_OFFSET);
}

static inline virt_addr_t phys_to_virt(phys_addr_t paddr)
{
	return (virt_addr_t)(paddr + PHYS_VIRT_OFFSET);
}

#endif


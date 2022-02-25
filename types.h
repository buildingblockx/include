#ifndef __TYPES_H
#define __TYPES_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef unsigned int	gfp_t;
typedef unsigned long	phys_addr_t;

struct list_head {
	struct list_head *next, *prev;
};

#endif /* __TYPES_H */

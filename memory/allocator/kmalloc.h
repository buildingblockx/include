#ifndef __COMMON_KMALLOC_H
#define __COMMON_KMALLOC_H

#include <common.h>

void kmalloc_init(void);

void *kmalloc(size_t size, gfp_t flags);
void kfree(void *object);

int kmalloc_test(void);

#endif /* __COMMON_KMALLOC_H */

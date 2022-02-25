#ifndef __COMMON_PAGE_H
#define __COMMON_PAGE_H

#include <memory/mm_types.h>

unsigned long page_allocator_init(void);

void *alloc_pages(gfp_t gfp_mask, unsigned int order);
struct page *__alloc_pages(gfp_t gfp_mask, unsigned int order);

#define alloc_page(gfp_mask) alloc_pages(gfp_mask, 0)
#define __alloc_page(gfp_mask) __alloc_pages(gfp_mask, 0)

void free_pages(void *vaddr, unsigned int order);
void __free_pages(struct page *page, unsigned int order);

#define free_page(addr) free_pages((addr), 0)
#define __free_page(page) __free_pages((page), 0)

int page_allocator_test(void);

#endif /* __COMMON_PAGE_H */

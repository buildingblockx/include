#ifndef __COMMON_COMPOUND_PAGE_H
#define __COMMON_COMPOUND_PAGE_H

#include <memory/mm_types.h>

void *alloc_compound_pages(gfp_t gfp_mask, unsigned int order);
struct page *__alloc_compound_pages(gfp_t gfp_mask, unsigned int order);

void free_compound_pages(void *vaddr);
void __free_compound_pages(struct page *page);

struct page *virt_to_head_page(void *vaddr);

#endif /* __COMMON_COMPOUND_PAGE_H */

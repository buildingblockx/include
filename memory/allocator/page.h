#ifndef __COMMON_PAGE_H
#define __COMMON_PAGE_H

#include <common.h>
#include <memory/allocator/slabcache.h>

struct page {
	unsigned long flags;

	union {
		struct { /* page allocator */
			struct list_head list;
			/*
			* Indicates order in the buddy system.
			*/
			unsigned long private;
		};

		struct { /* slab allocator */
			struct list_head slab_list;
			struct slab_cache *slab_cache;

			void *freelist;		/* first free object */

			unsigned inuse:16;	/* The number of objects in use */
			unsigned objects:15;	/* The total number of objects */
			unsigned frozen:1;	/* frozen means that this page is
						in slab_cache->freelist */
		};

		struct { /* compound page */
			/*
			 * each one page save head page pointer and
			 * bit zero indicates whether compound page
			 */
			unsigned long head;
			unsigned char order;	/* first page save order only */
		};
	};
};

unsigned long page_allocator_init(void);

virt_addr_t alloc_pages(gfp_t gfp_mask, unsigned int order);
struct page *__alloc_pages(gfp_t gfp_mask, unsigned int order);

#define alloc_page(gfp_mask) alloc_pages(gfp_mask, 0)
#define __alloc_page(gfp_mask) __alloc_pages(gfp_mask, 0)

void free_pages(virt_addr_t vaddr, unsigned int order);
void __free_pages(struct page *page, unsigned int order);

#define free_page(addr) free_pages((addr), 0)
#define __free_page(page) __free_pages((page), 0)

int page_allocator_test(void);

#endif /* __COMMON_PAGE_H */


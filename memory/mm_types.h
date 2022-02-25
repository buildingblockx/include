#ifndef __MM_TYPES_H
#define __MM_TYPES_H

#include <types.h>

#define PAGE_SHIFT	12
#define PAGE_SIZE	((1UL) << PAGE_SHIFT)
#define PAGE_MASK	(~(PAGE_SIZE-1))

#define MAX_ORDER	11

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

/*
 * Word size structure that can be atomically updated or read and that
 * contains both the order and the number of objects that a slab of the
 * given order would contain.
 */
typedef struct order_objects {
	unsigned int order:16;
	unsigned int objects:16;
} order_objects_t;

/*
 * Slab cache management.
 */
struct slab_cache {
	const char *name;	/* Name (only for display!) */
	unsigned int align;	/* Alignment */
	unsigned int size;	/* The size of an object including metadata */
	unsigned int object_size;/* The size of an object without metadata */
	unsigned int offset;	/* Free pointer offset */
	unsigned long flags;	/* slab cache flags, as below: */
	order_objects_t oo;

	void **freelist;	/* Pointer to next available object */
	struct page *page;	/* The slab from which we are allocating */

	struct list_head partial;
	unsigned long nr_partial;

	struct list_head full;
};

/*
 * Align the objects in this cache to a hardware cacheline.
 * This can be beneficial if you're counting cycles as closely as davem.
 */
#define SLAB_HWCACHE_ALIGN	0

#endif /* __MM_TYPES_H */

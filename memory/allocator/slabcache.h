#ifndef __COMMON_SLABCACHE_H
#define __COMMON_SLABCACHE_H

#include <memory/allocator/page.h>

/*
 * Word size structure that can be atomically updated or read and that
 * contains both the order and the number of objects that a slab of the
 * given order would contain.
 */
typedef struct order_objects {
	unsigned int order:16;
	unsigned int objects:16;
} order_objects_t;

#define OO_SHIFT	16
#define OO_MASK		((1 << OO_SHIFT) - 1)

/*
 * Slab cache management.
 */
struct slab_cache {
	const char *name;	/* Name (only for display!) */
	unsigned int align;	/* Alignment */
	unsigned int size;	/* The size of an object including metadata */
	unsigned int object_size;/* The size of an object without metadata */
	unsigned int offset;	/* Free pointer offset */
	unsigned long flags;
	order_objects_t oo;

	void **freelist;	/* Pointer to next available object */
	struct page *page;	/* The slab from which we are allocating */

	struct list_head partial;
	unsigned long nr_partial;

	struct list_head full;
};

#define SLAB_CACHE_MIN_PARTIAL	3

void slab_cache_allocator_init(void);

struct slab_cache *slab_cache_create(const char *name, unsigned int object_size,
				unsigned int align, unsigned long flags);
void slab_cache_destroy(struct slab_cache *s);

void *slab_cache_alloc(struct slab_cache *s, gfp_t gfp_mask);
void slab_cache_free(struct slab_cache *s, void *object);

static inline void *slab_cache_zalloc(struct slab_cache *s, gfp_t gfp_mask)
{
        return slab_cache_alloc(s, gfp_mask | __GFP_ZERO);
}

int slab_cache_allocator_test(void);

#endif /* __COMMON_SLABCACHE_H */

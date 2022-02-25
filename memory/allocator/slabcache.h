#ifndef __COMMON_SLABCACHE_H
#define __COMMON_SLABCACHE_H

#include <memory/mm_types.h>

void slab_cache_allocator_init(void);

struct slab_cache *slab_cache_create(const char *name, unsigned int object_size,
				unsigned int align, unsigned long flags);
void slab_cache_destroy(struct slab_cache *s);

void *slab_cache_alloc(struct slab_cache *s, gfp_t gfp_mask);
void *slab_cache_zalloc(struct slab_cache *s, gfp_t gfp_mask);
void slab_cache_free(struct slab_cache *s, void *object);

int slab_cache_allocator_test(void);

#endif /* __COMMON_SLABCACHE_H */

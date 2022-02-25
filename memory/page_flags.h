#ifndef __PAGE_FLAGS_H
#define __PAGE_FLAGS_H

#include <memory/mm_types.h>

enum pageflags {
	PAGE_locked,
	PAGE_buddy,
	PAGE_slab,
	PAGE_compound,

	MAX_NR_PAGEFLAGS
};

#define PAGE_TYPE_OPS(name)					\
/*								\
 * If @page is in ##name allocator?				\
 * Yes, return true; otherwise false;				\
 */								\
static inline int page_##name(struct page *page)		\
{								\
	return ((page->flags & PAGE_##name) == PAGE_##name);	\
}								\
/*								\
 * Indicates that this page is in the ##name allocator		\
 */								\
static inline void set_page_##name(struct page *page)		\
{								\
	page->flags |= PAGE_##name;				\
}								\
/*								\
 * Indicates that this page is not in the ##name allocator	\
 */								\
static inline void clear_page_##name(struct page *page)		\
{								\
	page->flags &= ~PAGE_##name;				\
}

PAGE_TYPE_OPS(locked)
PAGE_TYPE_OPS(buddy)
PAGE_TYPE_OPS(slab)
PAGE_TYPE_OPS(compound)

#endif /* __PAGE_FLAGS_H */

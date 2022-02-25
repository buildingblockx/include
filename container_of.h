#ifndef __CONTAINER_OF_H
#define __CONTAINER_OF_H

#include <stddef.h>

/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct this is embedded in.
 * @member:	the name of the member within the struct.
 */
#define container_of(ptr, type, member) ({		\
	void *__mptr = (void *)(ptr);			\
	((type *)(__mptr - offsetof(type, member))); })

#endif /* __CONTAINER_OF_H */

#ifndef __ALIGN_H
#define __ALIGN_H

#define ALIGN_MASK(x, mask)	(((x) + (mask)) & ~(mask))
#define __ALIGN(x, a)		ALIGN_MASK(x, (typeof(x))(a) - 1)

/* @a is a power of 2 value */
#define ALIGN(x, a)		__ALIGN((x), (a))
#define ALIGN_DOWN(x, a)	__ALIGN((x) - ((a) - 1), (a))

#endif /* __ALIGN_H */

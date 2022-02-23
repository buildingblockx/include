#ifndef __BITOPS_FLS_H
#define __BITOPS_FLS_H

/**
 * fls - find last (most-significant) bit set
 * @x: the word to search
 *
 * This is defined the same way as ffs.
 * Note fls(0) = 0, fls(1) = 1, fls(0x80000000) = 32.
 */
static __always_inline unsigned long fls(unsigned long x)
{
	return x ? sizeof(x) * 8 - __builtin_clzl(x) : 0;
}

#endif /* __BITOPS_FLS_H */

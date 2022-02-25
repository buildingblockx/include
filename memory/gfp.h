#ifndef __GFP_H
#define __GFP_H

#define GFP_KERNEL 0	/* Allocate normal kernel ram. May sleep */
#define GFP_NOWAIT 0	/* Allocation will not sleep */

#define __GFP_ZERO 1

#endif /* __GFP_H */

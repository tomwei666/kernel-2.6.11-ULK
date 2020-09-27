
#ifndef _LINUX_RBTREE_H 
#define _LINUX_RBTREE_H
#include "rbtree.h"


struct mm_struct {
	struct vm_area_struct * mmap;       /* list of VMAs */
	struct rb_root mm_rb; 
};
struct vm_area_struct {
	struct mm_struct * vm_mm;   /* The address space we belong to. */
	unsigned long vm_start;     /* Our start address within vm_mm. */
	unsigned long vm_end;       /* The first byte after our end address
								                     within vm_mm. */
	struct vm_area_struct *vm_next;
};


#endif

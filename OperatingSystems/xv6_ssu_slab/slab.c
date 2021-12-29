#include "types.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "spinlock.h"
#include "slab.h"

struct {
	struct spinlock lock;
	struct slab slab[NSLAB];
} stable;

void slabinit(){
	/* fill in the blank */
	struct slab *s;
	acquire(&stable.lock);
	initlock(&stable.lock, "slab_lock");

	int slab_size = 8;
	for(s = stable.slab; s<&stable.slab[NSLAB];s++){
		s->size = slab_size;
		s->num_pages = 1;
		s->num_free_objects = (MAX_OBJECTS_PER_PAGE/s->size);
		s->num_used_objects = 0;
		s->num_objects_per_page = (MAX_OBJECTS_PER_PAGE/s->size);
		s->bitmap = kalloc();
		s->page[(s->num_pages-1)]=kalloc();
		slab_size = slab_size << 1;
	}
	release(&stable.lock);
}

char *kmalloc(int size){
	/* fill in the blank */

	char *addr = 0;
	struct slab *s;

	int sidx = 0;
	int pidx = 0;
	int offset;

	int val = size >> 3;
	int sn;	// slot number
	
	// boundary check
	if(size > 2048)
		return 0x00;

	// find the smallest power of two greater than size
	while (val > 0){
		val >>= 1;
		sidx++;
	}

	s = &stable.slab[sidx];
	acquire(&stable.lock);

	// find free slot
	for(int i=0;i<BYTES_PER_PAGE;i++){
		char mask = 0x1;
		char bitvec = s->bitmap[i];
		for (int j=0;j<BITS_PER_CHAR; j++){
			if(!(bitvec & mas)){
				s->bitmap[i] |= maks;
				goto found;
			}
			mask <<= 1;
		}
	}
	release(&stable.lock);
	return 0x00;

found:




	return 0;
}

void kmfree(char *addr, int size){
	/* fill in the blank */
}

void slabdump(){
	cprintf("__slabdump__\n");

	struct slab *s;

	cprintf("size\tnum_pages\tused_objects\tfree_objects\n");

	for(s = stable.slab; s < &stable.slab[NSLAB]; s++){
		cprintf("%d\t%d\t\t%d\t\t%d\n", 
			s->size, s->num_pages, s->num_used_objects, s->num_free_objects);
	}
}

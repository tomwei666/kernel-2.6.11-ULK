#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <asm-i386/uaccess.h>

static char buf[] ="Access from kernel\n";
static char buf1[32];

#define switch_to_1(prev,next,last) do {                  \                          
    unsigned long esi,edi;                      \                                  
	asm volatile("pushfl\n\t"                   \                                  
			"pushl %%ebp\n\t"                  \                                  
			"movl %%esp,%0\n\t"    /* save ESP */      \                          
			"movl %5,%%esp\n\t"    /* restore ESP */   \                          
			"movl $1f,%1\n\t"      /* save EIP */      \                          
			"pushl %6\n\t"     /* restore EIP */   \                              
			"jmp __switch_to\n"                \
			"1:\t"                     \                                       
			"popl %%ebp\n\t"                   \                               
			"popfl"                        \                                   
			:"=m" (prev->thread.esp),"=m" (prev->thread.eip),  \               
			"=a" (last),"=S" (esi),"=D" (edi)         \                       
			:"m" (next->thread.esp),"m" (next->thread.eip),    \               
			"2" (prev), "d" (next));              \                           
} while (0)

#define switch_to_2(prev,next,last) do {                  \                          
    unsigned long esi,edi;                      \                                  
	asm volatile("movl %%esp,%0\n\t"                   \                                  
			"movl %%esp,%1\n\t"    /* save ESP */      \                          
			:"=m" (prev->esp),"=m" (prev->eip),  \               
			"=a" (last)         \                       
			:"m" (next->esp),"m" (next->eip),    \               
			"2" (prev), "d" (next));              \                           
} while (0)

#define switch_to_3(prev,next,last) do {                  \                          
    unsigned long esi,edi;                      \                                  
	asm volatile("movl %%eax,%1\n\t"                   \                                  
			:"=m" (prev),"=m" (next),  \               
			"=a" (last)         \                       
			:"m" (next->esp),"m" (next->eip),    \               
			"2" (prev), "d" (next));              \                           
} while (0)
#define switch_to_4(prev,next,last) do {                  \                          
    unsigned long esi,edi;                      \                                  
	asm volatile("movl %%eax,%1\n\t"                   \                                  
				"movl %%eax,%2\n\t"    /* save ESP */      \                          
			:"=m" (prev),"=m" (next),  \               
			"=a" (last)         \                       
			:"m" (next->esp),"m" (next->eip),    \               
			"2" (prev), "d" (next));              \                           
} while (0)




typedef struct {
	unsigned long esp;
	unsigned long eip;
} test_asm;


 
int __init test_init(void)
{
	test_asm prev_1={1,2};
	test_asm next_1={3,4};
	test_asm last_1={5,6};
	test_asm *prev_1_p=&prev_1;
	test_asm *next_1_p=&next_1;
	test_asm *last_1_p=&last_1;


	test_asm prev_2={7,8};
	test_asm next_2={9,10};
	test_asm last_2={11,12};
	test_asm *prev_2_p=&prev_2;
	test_asm *next_2_p=&next_2;
	test_asm *last_2_p=&last_2;

	test_asm prev_3={13,14};
	test_asm next_3={15,16};
	test_asm last_3={17,18};
	test_asm *prev_3_p=&prev_3;
	test_asm *next_3_p=&next_3;
	test_asm *last_3_p=&last_3;
	
	printk(KERN_ERR "switch-2-------begin\n");
	printk(KERN_ERR "tom prev=%x %x %x\n",prev_1_p,prev_1_p->esp,prev_1_p->eip);
	printk(KERN_ERR "tom next=%x %x %x\n",next_1_p,next_1_p->esp,next_1_p->eip);
	printk(KERN_ERR "tom last=%x %x %x\n",last_1_p,last_1_p->esp,last_1_p->eip);
	switch_to_2(prev_1_p,next_1_p,last_1_p);
	printk(KERN_ERR "tom prev=%x %x %x\n",prev_1_p,prev_1_p->esp,prev_1_p->eip);
	printk(KERN_ERR "tom next=%x %x %x\n",next_1_p,next_1_p->esp,next_1_p->eip);
	printk(KERN_ERR "tom last=%x %x %x\n",last_1_p,last_1_p->esp,last_1_p->eip);
	printk(KERN_ERR "switch-2-------end\n");

	printk(KERN_ERR "switch-3-------begin\n");
	printk(KERN_ERR "tom prev=%x %x %x\n",prev_2_p,prev_2_p->esp,prev_2_p->eip);
	printk(KERN_ERR "tom next=%x %x %x\n",next_2_p,next_2_p->esp,next_2_p->eip);
	printk(KERN_ERR "tom last=%x %x %x\n",last_2_p,last_2_p->esp,last_2_p->eip);
	switch_to_3(prev_2_p,next_2_p,last_2_p);
	printk(KERN_ERR "tom prev=%x %x %x\n",prev_2_p,prev_2_p->esp,prev_2_p->eip);
	printk(KERN_ERR "tom next=%x %x %x\n",next_2_p,next_2_p->esp,next_2_p->eip);
	printk(KERN_ERR "tom last=%x %x %x\n",last_2_p,last_2_p->esp,last_2_p->eip);
	printk(KERN_ERR "switch-3-------end\n");


	printk(KERN_ERR "switch-4-------begin\n");
	printk(KERN_ERR "tom prev=%x %x %x\n",prev_3_p,prev_3_p->esp,prev_3_p->eip);
	printk(KERN_ERR "tom next=%x %x %x\n",next_3_p,next_3_p->esp,next_3_p->eip);
	printk(KERN_ERR "tom last=%x %x %x\n",last_3_p,last_3_p->esp,last_3_p->eip);
	switch_to_3(prev_3_p,next_3_p,last_3_p);
	printk(KERN_ERR "tom prev=%x %x %x\n",prev_3_p,prev_3_p->esp,prev_3_p->eip);
	printk(KERN_ERR "tom next=%x %x %x\n",next_3_p,next_3_p->esp,next_3_p->eip);
	printk(KERN_ERR "tom last=%x %x %x\n",last_3_p,last_3_p->esp,last_3_p->eip);
	printk(KERN_ERR "switch-4-------end\n");



	return 0;
}
void __exit test_exit(void)
{
	printk("test exit\n");
}
 
module_init(test_init);
module_exit(test_exit);
 
MODULE_LICENSE("GPL");






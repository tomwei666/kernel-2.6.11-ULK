#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <asm-i386/uaccess.h>

typedef struct {
	unsigned long esp;
	unsigned long eip;
} test_asm;

test_asm * __switch_to_2(test_asm *prev, test_asm *next, test_asm *last) {
	printk(KERN_ERR "tom __switch_to_2\n");
	return prev;
}
#define switch_to_4(prev,next,last) do {					\
	unsigned long esi,edi;						\
	asm volatile("pushl %%ebp\n\t"					\
			 "movl %%esp,%0\n\t"			\
			 "movl $1f,%1\n\t"				\
			 "pushl %1\n\t"			        \
			 "jmp __switch_to_2\n"				\
			 "1:\t"						\
			 "popl %%ebp\n\t"					\
			 "popfl"						\
			 :"=m" (prev->esp),"=m" (prev->eip),	\
			  "=a" (last),"=S" (esi),"=D" (edi)			\
			 :"m" (next->esp),"m" (next->eip),	\
			  "2" (prev), "d" (next));				\
} while (0)

int __init test_init(void)
{
	test_asm n_1 ={0xAAAAAAAA,0xBBBBBBBB};
	test_asm n_2 ={0xCCCCCCCC,0xDDDDDDDD};
	test_asm n_3 ={0x77777777,0x88888888};
	test_asm * n_1_p=&n_1;	
	test_asm * n_2_p=&n_2;	
	test_asm * n_3_p=&n_3;	
	switch_to_4(n_1_p,n_2_p,n_3_p);

	
	return 0;
}
void __exit test_exit(void)
{
	printk("test exit\n");
}
 
module_init(test_init);
module_exit(test_exit);
 
MODULE_LICENSE("GPL");

#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <asm-i386/uaccess.h>

static char buf[] ="Access from kernel\n";
static char buf1[32];

/*addr=0xc1fb2060 limit=0x2074 type=0x89 n[63:0]*/
/*addr=0xc1fb2060 limit= type=0x89*/
/*  movw %w3,0(%2)   ==>  n[15:00]=limit         */
/*  movw %ax,2(%2)   ==>  n[31:16]=addr[15:00]=0x2060   */
/*  rorl $16,%%eax   ==>  交换eax的高低16位，之前eax=0xc1fb2060,交换后eax=0x2060 c1fb */
/*  movb %%al,4(%2)  ==>  n[39:32]=0xfb */
/*  movb %4,5(%2)    ==>  n[47:40]=type=0x89 */
/*  movb $0,6(%2)    ==>  n[55:48]=0*/
/*  movb %%ah,7(%2)  ==>  n[63:56]=0xc1*/
/*  rorl $16,%%eax   ==>  交换eax的高低16位，之前eax=0x2060 c1fb,交换后eax=0xc1fb2060*/

	/*"movb %%ah,7(%2)\n\t" \*/
/*  movb $0,6(%2)   ==>  n[55:48]=0*/
/*limit=0xc1fb2060*/
/*limit=0xc1fb2060*/
#define _set_tssldt_desc_1(n,addr,limit,type) \
__asm__ __volatile__ ("movw %w3,0(%2)\n\t" \
	"movw %%ax,2(%2)\n\t" \
	"rorl $16,%%eax\n\t" \
	"movb %%al,4(%2)\n\t" \
	: "=m"(*(n)) : "a" (addr), "r"(n), "ir"(limit), "i"(type))

/*#define _set_tssldt_desc_2(n,addr,limit,type) \*/
/*__asm__ __volatile__ ("movw %w3,0(%2)\n\t" \*/
	/*"movw %%ax,2(%2)\n\t" \*/
	/*"rorl $16,%%eax\n\t" \*/
	/*"movb %%al,4(%2)\n\t" \*/
	/*"movb %4,5(%2)\n\t" \*/
	/*"movb $0,6(%2)\n\t" \*/
	/*"movb %%ah,7(%2)\n\t" \*/
	/*"rorl $16,%%eax" \*/
	/*: "=m"(*(n)) : "a" (addr), "r"(n), "ir"(limit), "i"(type))*/

typedef struct {
	unsigned long esp;
	unsigned long eip;
} test_asm;

/*如果没有转换成int类型，则在汇编中4(%2),偏移不到n_1.eip， */
/*如果转换成int类型，则在汇编中4(%2),偏移到n_1.eip*/
int __init test_init(void)
{
	test_asm n_1 ={0,0};
	test_asm * n_p=&n_1;	
	int *n_p_1=(int *) n_p;
	/*int *n_p_1=(int *) &n_1.esp;*/

	unsigned addr_2  = 0x12345678;
	unsigned limit_3 = 0x4567aaaa;
	unsigned type    = 0x987654;

	_set_tssldt_desc_1(n_p_1,addr_2,limit_3,type);
	
	printk(KERN_ERR "n_1[0]=%x n_1[1]=%x\n",n_1.esp,n_1.eip);
	printk(KERN_ERR " new n_1[0]_addr=%x n_1[1]_addr=%x\n",&n_1.esp,&n_1.eip);
	
	
	return 0;
}
void __exit test_exit(void)
{
	printk("test exit\n");
}
 
module_init(test_init);
module_exit(test_exit);
 
MODULE_LICENSE("GPL");

#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <asm-i386/uaccess.h>
#include <asm-i386/thread_info.h>

/* how to get kernel thread stack bottom */                                        
static inline unsigned long get_stack_bottom_1(void)                                 
{                                                                                  
	    unsigned long stack_bottom;                                                    
		printk(KERN_ERR "dump_kernel_stack L=%d\n",__LINE__);                           
		stack_bottom = esp_info() & (~(THREAD_SIZE - 1));                              
		printk(KERN_ERR "stack_bottom = %x\n",stack_bottom);                            
		stack_bottom = stack_bottom + (THREAD_SIZE - 1);                                                                                                                                         
		printk(KERN_ERR "stack_bottom = %x\n",stack_bottom);                            
		stack_bottom = stack_bottom + (THREAD_SIZE - 1);                               
		/* 地址是4个字节对齐 */                                                        
		stack_bottom &= 0xFFFFFFFC;                                                    
		return stack_bottom;                                                           
}  

 
int __init test_init(void)
{
	/*unsigned long stack_top_1,stack_bottom,stack_top_2;*/
	/*stack_bottom = get_stack_bottom_1();*/
	/*stack_top_1 = esp_info();*/
	/*stack_top_2 = current_stack_pointer;*/
	dump_kernel_stack();
   /* unsigned long esp;*/
    /*unsigned long stack_bottom;*/
	/*unsigned long *esp_p;*/
	/*esp=current_stack_pointer;*/
	/*esp=esp_info();*/
	/*[>stack_bottom = get_stack_bottom();<]*/
	/*esp_p = esp;*/
	/*stack_bottom = (esp & (~(THREAD_SIZE - 1))) + (THREAD_SIZE - 1);*/

	/*printk(KERN_ERR "tom get esp from current_stack_pointer esp=%x bottom=%x\n",esp,stack_bottom);*/
	/*for(;esp<stack_bottom;esp+=4)*/
	/*{*/
		/*esp_p = esp;*/
		/*printk(KERN_ERR "tom %x:%x\n",esp,*esp_p);*/
	/*}*/
	
		 
	/*printk(KERN_ERR "tom get esp from current_stack_pointer esp=%x bottom=%x\n",esp,stack_bottom);*/
	

	/*dump_kernel_stack();*/
	/*printk(KERN_ERR "tom get esp from esp_info esp=%x\n",esp);*/
	/*esp=current_stack_pointer;*/
	/*printk(KERN_ERR "tom get esp from current_stack_pointer esp=%x\n",esp);*/
	/*esp=esp_info();*/
	/*printk(KERN_ERR "tom get esp from esp_info esp=%x\n",esp);*/
	return 0;
}
void __exit test_exit(void)
{
	printk("test exit\n");
}
 
module_init(test_init);
module_exit(test_exit);
 
MODULE_LICENSE("GPL");






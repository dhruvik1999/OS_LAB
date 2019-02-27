#include <linux/module.h>
#include <linux/kernel.h>
int init_module(void)
{
 printk(KERN_INFO "Hello world 1.\n");
 return 0;
}
void cleanup_module(void)
{
 printk(KERN_INFO "Goodbye world 1.\n");
}

module_init(hello_start); 
module_exit(hello_end); 
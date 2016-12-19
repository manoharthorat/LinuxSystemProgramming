#include<linux/module.h>
#include<linux/kernel.h>

int init__module(void)
{
	printk(KERN_INFO"First Program of Device Driver");
	return 0;
}
	
void cleanup_module(void)
{
	printk(KERN_INFO"Module Removed ");
}

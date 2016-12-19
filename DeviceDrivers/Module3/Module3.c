#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

static int data __initdata =21;

static int __init hello3_init (void)
{
	printk(KERN_INFO"Module is inserted with data %d \n",data);
	return 0;
}

static void __exit hello3_exit(void)
{
	printk(KERN_INFO"Module Removed ");
}

module_init(hello3_init);
module_exit(hello3_exit);

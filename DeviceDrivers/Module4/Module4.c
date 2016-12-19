#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

#define DRIVER_AUTHOR "Manohar Thorat"
#define DRIVER_DESC "Demo Driver"

static int __init hello4_init(void)
{
	printk(KERN_INFO"Module Loading ......");
	return 0;

}

static void __exit hello4_exit(void)
{
	printk(KERN_INFO"Module Removed .......");

}

module_init(hello4_init);
module_exit(hello4_exit);

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);


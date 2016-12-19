#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

static int __init hello2_init(void)
{
	printk(KERN_INFO"Inserting Module ");
	return 0;
}

static void __exit hello2_exit(void)
{
	printk(KERN_INFO"Removing Module ");
}
module_init(hello2_init);
module_exit(hello2_exit);


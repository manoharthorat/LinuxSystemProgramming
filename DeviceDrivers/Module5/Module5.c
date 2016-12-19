#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/moduleparam.h>
#include<linux/stat.h>

int myint =21 ;
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

MODULE_PARM_DESC(myint,"Integer Varable");

static int __init hello5_init(void) 
{
	printk(KERN_INFO"Variable Value %d",myint);
	return 0;

}
static void __exit hello5_exit(void)
{
	printk(KERN_INFO"Removing Module ");
}

module_init(hello5_init);
module_exit(hello5_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Manohar Thorat");
MODULE_DESCRIPTION("Basic Device Driver");
MODULE_VERSION("0.1");



#include<linux/module.h>
#include<linux/version.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Manohar Thorat");
MODULE_DESCRIPTION("This is a device number program");
static dev_t first;
	
static int  __init ofd_init(void)
{
	printk(KERN_INFO"Device Number Program\n");
	if(alloc_chrdev_region(&first,0,3,"Manohar") < 0 )
	{
		return -1;
	}
	printk(KERN_INFO"<Major , Minor> : <%d , %d>\n",MAJOR(first),MINOR(first));
	return 0;
}	

static void __exit ofd_exit(void)
{
	unregister_chrdev_region(first,3);
	printk(KERN_INFO"Bye Unregister device");
}
module_init(ofd_init);
module_exit(ofd_exit);


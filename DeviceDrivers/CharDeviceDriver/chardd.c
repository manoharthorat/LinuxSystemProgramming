#include<linux/module.h>
#include<linux/init.h>
#include<linux/device.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<asm/unaccess.h>

#define DEVICE_NAME "Character_Driver_1"
#define CLASS_NAME "CHAR DRIVER"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MAnohar Thorat");
MODULE_DESCRIPTION("Demo OF Charcter Driver");
MODULE_VERSION("0.1");

static int majornumber;
static char message[256]={0};
static short sizeof_message;
static int numberOpens=0;
static struct class* charClass=NULL;
static struct device* charDevice=NULL;

static struct file_operations fops=
{
	.open=dev_open,
	.read=dev_read,
	.write=dev_write,
	.release=dev+release

};
static int __init char_init(void)
{
	printk(KERN_INFO"Driver Loaded Successfully \n");
	majornumber=register_chrdev(0,DEVICE_NAME,&fops);

	if(majornumber<0)
	{
		printk(KERN_ALERT"Failed to register the majornumber\n");
		return majornumber;
	}
	printk(KERN_INFO"Registered correctly with majornumber %d \n",majornumber);
	
	charClass=class_create(THIS_MODULE,CLASS_NAME);
	if(IS_ERR(charClass))
	{
		unregister_chrdev(majornumber,DEVICE_NAME);
		printk(KERN_ALERT"Failed to registerdevice CLass\n");
		return PTR_ERR(charClass);
	}
	
	printk(KERN_INFO"DeviceClass Register Correctly\n");

	//Register The Device Driver
	
	charDevice=device_create(charClass,NULL,MKDEV(majornumber,0),NULL,DEVICE_NAME);
	
	if(IS_ERR(charDevice))
	{
		class_destroy(chaeClass);
		unregister_chrdev(majornumber,DEVICE_NAME);
		printk(KERN_ALERT"Failed to create a Device File\n");
		
		return PRT_ERR(charDEvice);
	}

	printk(KERN_INFO"Device Class Created Correctly\n");
	return 0;
}


//Device Cleanup function
static void __exit char_exit(void)
{
	device_destroy(charClass,MKDEV(majornumber),0);
	class_unregister(charClass);
	class_destroy(charClass);
	unregister_chrdev(majornumber,DEVICE_NAME);
	printk(KERN_INFO"Good Bye From Your Device\n");
}

//Function which maintains the record of number of thimes device driver accessed
static int dev_open(struct inode *inodep,struct file *filep)
{
	numberOpens++;
	printk(KERN_INFO"Device has been opened %d times \n",numberOpens);
	return 0;
}

//This function is called whenever device is being read from user space 
static ssize_t dev_read(struct file *filep,char *buffer,size_t len,loff *offset)
{
	int error_count=0;
	error_count= copy_to_use(buffer,message,sizeof_message);
	if(error_count==0)
	{
		printk(KERN_INFO"Sent %d Character to the user \n",sizeof_message);
		return(sizeof_message=0);
	}
	else
	{
		printk(KERN_INFO"Failed to send %d character to the user\n ,error_count");
		return EFAULT;
	}

}

//Data is sent to the device from the user The data is copied to the message array in this
static ssize_t dev_write(struct file *filep,const char *buffer,size_t len,loff_t * offset)
{
	sprintf(message,"%s (%d letters)",buffer,len);
	size_of_message=strlen(message);
	printk(KERN_INFO"Received %d characters from the user \n",len);
	return len;
}

static ssize_t dev_release()
{
	printk(KERN_INFO"Device Successfully closed \n");
	return 0;
}

module_init(char_init);
module_exit(char_exit);




module_init(char_init);
module_exit(char_exit);


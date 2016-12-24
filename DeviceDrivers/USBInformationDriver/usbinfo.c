#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/usb.h>

static struct usb_device * device;

static int pen_probe(struct usb_interface * interface,const struct usb_device_id *id)
{
	struct usb_host_interface * iface_desc;
	struct usb_endpoint_descriptor * endpoint;
	int i;
	
	iface_desc=interface->cur_altsetting;
	printk(KERN_INFO"pen interface %d now probed: (%04X:%04X)\n"iface_desc->desc.nInterfaceNumber, id->idVendor,id->idProduct);
	printk(KERN_INFO"ID->bNumEndpoints: %02X\n",iface_desc->desc.bNumEndpoints);
	printk(KERN_INFO"ID->bInterfaceClass:%02X\n",iface_desc->desc.nInterfaceClass);
	
	for(i=0;i< iface_desc->desc.bNumEndpoints;i++)
	{
		
	}	
	
}


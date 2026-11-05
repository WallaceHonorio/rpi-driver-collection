/*******************************************************************************//*
*  \file       char-driver.c
*
*  \details    Simple character driver 
*				- Statically allocating the Major and Minor number
*				- Dynamically allocating the Major and Minor number
*
*  \author     WallaceHonorio
*
* *******************************************************************************/

#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/device.h>

MODULE_LICENSE("Dual MIT/GPL");
MODULE_DESCRIPTION("A sample driver");
MODULE_VERSION("1:1.1");
MODULE_AUTHOR("Wallace Honorio <github:WallaceHonorio>");

#define ALLOCATE 1 // 0 - Static allocation, 1 - Dynamic allocation
#define CREATE 0 // 0 - Manually, 1 - Automatically

// Creating the dev with our custom major and minor number
#if ALLOCATE == 0
dev_t dev = MKDEV(235, 0);
#elif ALLOCATE == 1
dev_t dev;
static struct class *dev_class;
#endif


/**
 *  Module Init function
 */
static int __init char_module_init(void)
{
	/*Allocating Major number*/
#if ALLOCATE == 0
	register_chrdev_region(dev, 1, "char_driver");
#elif ALLOCATE == 1
	#if CREATE == 0
	if((alloc_chrdev_region(&dev, 0,1, "char_driver")) < 0)
	{
		printk(KERN_INFO "Cannot allocate major number\n");
		return -1;
	}
    pr_info("Major = %d Minor = %d \n",MAJOR(dev), MINOR(dev));
 
    /*Creating struct class*/
    dev_class = class_create(THIS_MODULE,"etx_class");
    if(IS_ERR(dev_class))
	{
        pr_err("Cannot create the struct class for device\n");
        goto r_class;
    }
 
    /*Creating device*/
    if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"etx_device")))
	{
        pr_err("Cannot create the Device\n");
        goto r_device;
    }
 
r_device:
    class_destroy(dev_class);
r_class:
    unregister_chrdev_region(dev,1);
    return -1;
	#endif
#endif

	pr_info("Kernel Module Inserted Successfully...\n");
	// printk(KERN_INFO "Kernel module inserted successfully...\n");
	return 0;
}

/**
 *  Module Exit function
 */
static void __exit char_module_exit(void)
{
	device_destroy(dev_class,dev);
    class_destroy(dev_class);
	unregister_chrdev_region(dev, 1);
	printk(KERN_INFO "Kernel module removed successfully...\n");
}

module_init(char_module_init);
module_exit(char_module_exit);

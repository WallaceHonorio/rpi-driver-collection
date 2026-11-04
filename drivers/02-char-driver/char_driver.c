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
#include <linux/fs.h>

MODULE_LICENSE("Dual MIT/GPL");
MODULE_DESCRIPTION("A sample driver");
MODULE_VERSION("1:1.0");
MODULE_AUTHOR("Wallace Honorio <github:WallaceHonorio>");

#define ALLOCATE 0 // 0 - Static allocation, 1 - Dynamic allocation

// Creating the dev with our custom major and minor number
#if ALLOCATE == 0
dev_t dev = MKDEV(235, 0);
#elif ALLOCATE == 1
dev_t dev;
#endif


/**
 *  Module Init function
 */
static int __init char_module_init(void)
{
	#if ALLOCATE == 0
	register_chrdev_region(dev, 1, "char_driver");
	#elif ALLOCATE == 1
	if((alloc_chrdev_region(&dev, 0,1, "char_driver")) < 0)
	{
		printk(KERN_INFO "Cannot allocate major number\n");
		return -1;
	}
	#endif
	printk(KERN_INFO "Major: %d\n", MAJOR(dev));
	printk(KERN_INFO "Minor: %d\n", MINOR(dev));
	printk(KERN_INFO "Kernel module inserted successfully...\n");
	return 0;
}

/**
 *  Module Exit function
 */
static void __exit char_module_exit(void)
{
	unregister_chrdev_region(dev, 1);
	printk(KERN_INFO "Kernel module removed successfully...\n");
}

module_init(char_module_init);
module_exit(char_module_exit);

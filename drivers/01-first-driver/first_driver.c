/***************************************************************************//**
*  \file       first_driver.c
*
*  \details    Simple hello world driver
*
*  \author     WallaceHonorio
*
* *******************************************************************************/

#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("Dual MIT/GPL");
MODULE_DESCRIPTION("A sample driver");
MODULE_VERSION("1:1.0");
MODULE_AUTHOR("Wallace Honorio <github:WallaceHonorio>");

/**
 *  Module Init function
 */
static int __init hello_world_init(void)
{
	/**
	 * printk
	 * There are several macros used for printk. 
	 * 
	 * KERN_EMERG: Used for emergency messages, usually those that precede a crash.
	 * KERN_ALERT: A situation requiring immediate action.
	 * KERN_CRIT: Critical conditions are often related to serious hardware or software failures.
	 * KERN_ERR: Used to report error conditions; device drivers often use KERN_ERR to report hardware difficulties.
	 * KERN_WARNING: Warnings about problematic situations that do not, in themselves, create serious problems with the system.
	 * KERN_NOTICE: Situations that are normal, but still worthy of note. A number of security-related conditions are reported at this level.
	 * KERN_INFO: Informational messages. Many drivers print information about the hardware they find at startup time at this level.
	 * KERN_DEBUG: Used for debugging messages.
	 */
	
	 printk(KERN_ALERT "Hello, beautiful world\n");
	 printk(KERN_NOTICE "This is the simple module\n");
	 printk(KERN_INFO "Kernel module inserted successfully...\n");
	 return 0;
}
/**
 *  Module Exit function
 */
static void __exit hello_world_exit(void)
{
	printk(KERN_ALERT "Goodbye, cruel world\n");
	printk(KERN_INFO "Kernel module removed successfully...\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);

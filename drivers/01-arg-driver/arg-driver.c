/*******************************************************************************//*
*  \file       arg-driver.c
*
*  \details    Simple argument driver
*
*  \author     WallaceHonorio
*
* *******************************************************************************/

#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

MODULE_LICENSE("Dual MIT/GPL");
MODULE_DESCRIPTION("A sample driver");
MODULE_VERSION("1:1.0");
MODULE_AUTHOR("Wallace Honorio <github:WallaceHonorio>");

int value_extern, cb_value_extern = 0;
int arr_value_extern [4] = {0, 0, 0, 0};
char *name_extern;

module_param (value_extern, int, S_IRUSR | S_IWUSR);
module_param (name_extern, charp, S_IRUSR | S_IWUSR);
module_param_cb (cb_value_extern, &my_param_ops, &cb_value_extern, S_IRUGO | S_IWUSR);
module_param_array (arr_value_extern, int, NULL, S_IRUSR | S_IWUSR);

/** 
 * Structure that defines the operations for a kernel parameter.
 */
const struct kernel_param_ops my_param_ops = 
{
    .set = &notify_param, // Use our setter
    .get = &param_get_int, // Standard getter
};

/** 
 * Module_param_cb()
 */
int notify_param_cb (const char *val, const struct kernel_param *kp)
{
	int res = param_set_int (val, kp); // Use helper for write variable
	if (res == 0)
	{
		printk(KERN_INFO "Notify callback function called\n");
		printk(KERN_INFO "New value of cb_value_extern: %d\n", cb_value_extern);
	}
	return res;
}

/**
 *  Module Init function
 */
static int __init hello_world_init(void)
{
	int i;
	printk(KERN_INFO "Value of value_extern: %d\n", value_extern);
	printk(KERN_INFO "Value of cb_value_extern: %d\n", cb_value_extern);
	printk(KERN_INFO "Name: %s\n", name_extern);
	for (i = 0; i < 4; i++)
	{
		printk(KERN_INFO "Array value %d: %d\n", i, arr_value_extern[i]);
	}
	printk(KERN_INFO "Kernel module inserted successfully...\n");
	return 0;
}

/**
 *  Module Exit function
 */
static void __exit hello_world_exit(void)
{
	printk(KERN_INFO "Kernel module removed successfully...\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);

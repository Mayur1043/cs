#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/init.h>

static int __init my_mod_init(void) 
{
	pr_info("Hello World!\n");
	return 0;
}

static void __exit my_mod_exit(void)
{
	pr_info("Goodbye Blue Sky!\n");
	return;
}

module_init(my_mod_init);
module_exit(my_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("<PRN 0018>");
MODULE_DESCRIPTION("Hey you module!");
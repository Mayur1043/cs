/* Illustrate module parameters with callbacks */

#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

static int operation=0;
static int myint1=20;
static int myint2=30;


module_param(myint1, int, S_IRUGO);
module_param(myint2, int, S_IRUGO);

int notify_on_set(const char *val, const struct kernel_param *kp)
{

	int ans = param_set_int(val, kp);
	if(ans==0)
	{
		pr_info("Callback function %s called\n", __func__);
		if(operation==1)
		{
			pr_info("addition %d\n",(myint1+myint2));
		}
		else if(operation==2)
		{
			pr_info("sub %d\n",(myint1-myint2));
		}
		else if(operation==3)
		{
			pr_info("mul %d\n",(myint1*myint2));
		}
		else if(operation==4)
		{
			pr_info("divi %d\n",(myint1/myint2));
		}
		return 0;
	}
	return -1;
}

const struct kernel_param_ops myops = 
{
	.set = &notify_on_set,		// my function - overrides default
	.get = &param_get_int, 	// kernel's function - default
};

      // perms: all can read, only USR (root) can write/edit
module_param_cb(operation,&myops, &operation, S_IRUGO | S_IWUSR);

// create MODULE DESC strings for modinfo
MODULE_PARM_DESC(operation, "This is a calculator");

static int __init my_mod_init(void)
{
	pr_info("Hello from mod22!\n");
	return 0;
}

static void __exit my_mod_exit(void)
{
	pr_info("Goodbye from mod22!\n");

	return;
}

module_init(my_mod_init);
module_exit(my_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bipin and mayur");
MODULE_DESCRIPTION("Module with param callback support!");

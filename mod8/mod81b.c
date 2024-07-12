/* Kernel thread basics */

#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/kthread.h>

#define TIME_INTVL	(1000)	// milliseconds

// define thread structs
static struct task_struct *thread1, *thread2;
static char thread1_name[] = "Thread-1";
static char thread2_name[] = "Thread-2";

int thread_func1(void *pv)
{
	int i = 0;
	char *thread_name = (char *)pv;
	while(!kthread_should_stop())
	{
		pr_info("In thread %s, i=%d\n", __func__, i++);
		msleep(TIME_INTVL);
	}
	pr_info("Hello From Thread %s!\n",thread_name);
	//pr_info("dmesg=%s\n",dmesg);
	return 0;
}

/*int thread_func2(void *pv)
{
	int i = 0;
	while(!kthread_should_stop())
	{
		pr_info("In thread %s, i=%d\n", __func__, i++);
		msleep(TIME_INTVL*2);
	}
	return 0;
}*/

/*int detect_thread(void)
{
	struct task_struct *current = current_task();
	if(current == thread1)
	{
		pr_info("Thread1 is executing\n");
	}
	else if(current == thread2)
	{
		pr_info("Thread 2 is executing\n")
	}
	else
	{
		pr_info("No thread\n");
	}
}*/

static int __init my_mod_init(void)
{
	pr_info("Hello world from %s!\n", KBUILD_MODNAME);

	thread1 = kthread_run(thread_func1, (void*)&thread1_name, thread1_name);
	if (thread1)
		pr_info("Thread %s created!\n", thread1_name);
	else
	{
		pr_err("Cannot create thread %s\n", thread1_name);
		goto r_thread1;
	}

	thread2 = kthread_run(thread_func1, (void*)&thread2_name, thread2_name);
	if (thread2)
		pr_info("Thread %s created!\n", thread2_name);
	else
	{
		pr_err("Cannot create thread %s\n", thread2_name);
		goto r_thread2;
	}
	return 0;

r_thread2:
	kthread_stop(thread1);
r_thread1:
	return -1;
}

static void __exit my_mod_exit(void)
{
	kthread_stop(thread1);
	kthread_stop(thread2);
	pr_info("Goodbye world from %s!\n", KBUILD_MODNAME);

	return;
}

module_init(my_mod_init);
module_exit(my_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EDD <edd@cdac.gov.in>");
MODULE_DESCRIPTION("Module to demo kernel threads!");

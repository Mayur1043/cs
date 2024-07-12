// kernel_module.c

#include <linux/module.h>
#include <linux/sysfs.h>
#include <linux/timer.h>
#include <linux/ftrace.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A kernel module that creates a sub-directory under /sysfs");

static struct kobject *my_kobj;
static struct timer_list gf_timer;
static char foo_state[] = "OFF";
static DEFINE_MUTEX(foo_mutex);

static char prn_number[] = "1234567890"; // Replace with your PRN number

static ssize_t id_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    return -EINVAL; // This file is write-only
}

static ssize_t id_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
    if (strncmp(buf, prn_number, strlen(prn_number)) == 0) {
        return strlen(prn_number);
    } else {
        return -EPERM; // Permission denied
    }
}

static struct kobj_attribute id_attr = __ATTR(id, 0664, id_show, id_store);

static ssize_t gf_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    unsigned long gf_value = jiffies - gf_timer.expires;
    return sprintf(buf, "GF timer value: %lu\n", gf_value);
}

static struct kobj_attribute gf_attr = __ATTR_RO(gf);

static ssize_t foo_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    mutex_lock(&foo_mutex);
    ssize_t ret = sprintf(buf, "FOO state: %s\n", foo_state);
    mutex_unlock(&foo_mutex);
    return ret;
}

static ssize_t foo_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
    if (!capable(CAP_SYS_ADMIN)) {
        return -EPERM; // Only root can write to this file
    }

    mutex_lock(&foo_mutex);
    if (strncmp(buf, "ON", 2) == 0) {
        strcpy(foo_state, "ON");
    } else if (strncmp(buf, "OFF", 3) == 0) {
        strcpy(foo_state, "OFF");
    } else {
        mutex_unlock(&foo_mutex);
        return -EINVAL; // Invalid input
    }
    mutex_unlock(&foo_mutex);
    return count;
}

static struct kobj_attribute foo_attr = __ATTR(foo, 0644, foo_show, foo_store);

static void gf_timer_func(unsigned long data)
{
    // Do something with the GF timer
    printk(KERN_INFO "GF timer expired\n");
}

static int __init my_module_init(void)
{
    my_kobj = kobject_create_and_add("my_subdir", kernel_kobj);
    if (!my_kobj) {
        printk(KERN_ERR "Failed to create kobject\n");
        return -ENOMEM;
    }

    if (sysfs_create_file(my_kobj, &id_attr.attr)) {
        printk(KERN_ERR "Failed to create id file\n");
        kobject_put(my_kobj);
        return -ENOMEM;
    }

    if (sysfs_create_file(my_kobj, &gf_attr.attr)) {
        printk(KERN_ERR "Failed to create gf file\n");
        kobject_put(my_kobj);
        return -ENOMEM;
    }

    if (sysfs_create_file(my_kobj, &foo_attr.attr)) {
        printk(KERN_ERR "Failed to create foo file\n");
        kobject_put(my_kobj);
        return -ENOMEM;
    }

    timer_setup(&gf_timer, gf_timer_func, 0);
    mod_timer(&gf_timer, jiffies + HZ); // Start the GF timer

    printk(KERN_INFO "Kernel module loaded\n");
    return 0;
}

static void __exit my_module_exit(void)
{
    sysfs_remove_file(my_kobj, &id_attr.attr);
    sysfs_remove_file(my_kobj, &gf_attr.attr);
    sysfs_remove_file(my_kobj, &foo_attr.attr);
    del_timer_sync(&gf_timer);
    kobject_put(my_kobj);
    printk(KERN_INFO "Kernel module unloaded\n");
}

module_init(my_module_init);
module_exit(my_module_exit);

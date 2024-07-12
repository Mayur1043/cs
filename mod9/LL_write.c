#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/ioctl.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A kernel module that accepts integers from user space and adds them to a linked list");

// Define the linked list structure
struct node {
    int data;
    struct node *next;
};

// Define the linked list head
struct node *head = NULL;

// Define the file operations structure
static const struct file_operations fops = {
    .owner = THIS_MODULE,
    .write = my_write,
    .read = my_read,
    .unlocked_ioctl = my_ioctl,
};

// Define the write function
static ssize_t my_write(struct file *filp, const char __user *buf, size_t count, loff_t *ppos)
{
    int data;
    struct node *new_node;

    // Copy the data from user space to kernel space
    if (copy_from_user(&data, buf, sizeof(int))) {
        return -EFAULT;
    }

    // Allocate a new node and add it to the linked list
    new_node = kmalloc(sizeof(struct node), GFP_KERNEL);
    if (!new_node) {
        return -ENOMEM;
    }
    new_node->data = data;
    new_node->next = head;
    head = new_node;

    return sizeof(int);
}

// Define the read function
static ssize_t my_read(struct file *filp, char __user *buf, size_t count, loff_t *ppos)
{
    char temp[256];
    struct node *curr = head;
    int len = 0;

    // Traverse the linked list and build a string to display
    while (curr) 
    {
        len += sprintf(temp + len, "%d ", curr->data);
        curr = curr->next;
    }

    // Copy the string to user space
    if (copy_to_user(buf, temp, len)) 
    {
        return -EFAULT;
    }

    return len;
}

// Define the IOCTL function
static long my_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
    switch (cmd) {
    case IOCTL_DELETE_LIST:
        // Delete the linked list
        while (head) {
            struct node *next = head->next;
            kfree(head);
            head = next;
        }
        break;
    default:
        return -ENOTTY;
    }

    return 0;
}

// Define the IOCTL command
#define IOCTL_DELETE_LIST _IO('k', 1)

// Define the module initialization function
static int __init my_init(void)
{
    // Register the character device
    if (register_chrdev(0, "my_device", &fops) < 0) {
        printk(KERN_ERR "Failed to register character device\n");
        return -1;
    }

    printk(KERN_INFO "Kernel module loaded\n");
    return 0;
}

// Define the module exit function
static void __exit my_exit(void)
{
    // Unregister the character device
    unregister_chrdev(0, "my_device");

    // Free the linked list
    while (head) {
        struct node *next = head->next;
        kfree(head);
        head = next;
    }

    printk(KERN_INFO "Kernel module unloaded\n");
}

module_init(my_init);
module_exit(my_exit);

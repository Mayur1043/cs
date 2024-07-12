#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/list.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A kernel module implementing a linked list");

// Define the structure for a linked list node
struct node {
    int data;
    struct list_head list;
};

// Define the head of the linked list
static LIST_HEAD(linked_list);

// Function to add an entry to the list
static void add_entry(int data)
{
    struct node *new_node = kmalloc(sizeof(struct node), GFP_KERNEL);
    if (!new_node) {
        printk(KERN_ERR "Failed to allocate memory for new node\n");
        return;
    }
    new_node->data = data;
    list_add(&new_node->list, &linked_list);
    printk(KERN_INFO "Added entry %d to the list\n", data);
}

// Function to add an entry to the tail of the list
static void add_entry_tail(int data)
{
    struct node *new_node = kmalloc(sizeof(struct node), GFP_KERNEL);
    if (!new_node) {
        printk(KERN_ERR "Failed to allocate memory for new node\n");
        return;
    }
    new_node->data = data;
    list_add_tail(&new_node->list, &linked_list);
    printk(KERN_INFO "Added entry %d to the tail of the list\n", data);
}

// Function to delete an entry from the list
static void delete_entry(int data)
{
    struct node *node, *tmp;
    list_for_each_entry_safe(node, tmp, &linked_list, list) {
        if (node->data == data) {
            list_del(&node->list);
            kfree(node);
            printk(KERN_INFO "Deleted entry %d from the list\n", data);
            return;
        }
    }
    printk(KERN_INFO "Entry %d not found in the list\n", data);
}

// Function to traverse the list
static void traverse_list(void)
{
    struct node *node;
    list_for_each_entry(node, &linked_list, list) {
        printk(KERN_INFO "Entry %d\n", node->data);
    }
}

// Function to delete the full list
static void delete_full_list(void)
{
    struct node *node, *tmp;
    list_for_each_entry_safe(node, tmp, &linked_list, list) {
        list_del(&node->list);
        kfree(node);
    }
    printk(KERN_INFO "Deleted the full list\n");
}

// Function to check if the list is full
static bool is_list_full(void)
{
    return list_empty(&linked_list) ? false : true;
}

// Kernel module initialization function
static int __init linked_list_init(void)
{
    printk(KERN_INFO "Linked list module initialized\n");
    return 0;
}

// Kernel module exit function
static void __exit linked_list_exit(void)
{
    delete_full_list();
    printk(KERN_INFO "Linked list module exited\n");
}

module_init(linked_list_init);
module_exit(linked_list_exit);

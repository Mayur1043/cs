#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/ioctl.h>
#include <linux/slab.h> 

#define MY_CLASS_NAME	"cdac_cls"
#define MY_DEV_NAME	"cdac_dev"

struct node {
	int data;
	struct node *next;
};

struct node *head=NULL;
#define IOCTL_DELETE_LIST _IO('k',1)
static void __exit my_exit(void);
static int my_open(struct inode *inode, struct file *file);
static ssize_t my_write (struct file *filp,const char __user *buf,size_t count,loff_t *ppos);
static ssize_t my_read(struct file *filp,char __user *buf,size_t count , loff_t *ppos);
static long my_ioctl(struct file *filp,unsigned int cmd,unsigned long arg);
static int my_open(struct inode *inode, struct file *file);
static int __init my_init(void);

static const struct file_operations fops = {
	.owner = THIS_MODULE,
	.write = my_write,
	.read = my_read,
	.unlocked_ioctl = my_ioctl,
};

static ssize_t my_write (struct file *filp,const char __user *buf,size_t count,loff_t *ppos)
{
	int data;
	struct node *new_node;
	
	if(copy_from_user(&data,buf,sizeof(int)))
	{
		return -EFAULT;
	}

	new_node = kmalloc(sizeof(struct node),GFP_KERNEL);
	if(!new_node)
	{
		return -EFAULT;
	}
	new_node ->data = data;
	new_node -> next = head;
	head=new_node;

	return sizeof(int);
}

static ssize_t my_read(struct file *filp,char __user *buf,size_t count , loff_t *ppos)

{
	char temp[256];
	struct node *curr = head;
	int len=0;

	while(curr)
	{
		len += sprintf(temp+len,"%d",curr->data);
		curr = curr->next;
	}

	if(copy_to_user(buf,temp,len))
	{
		return -EFAULT;
	}
	return len;
}

static long my_ioctl(struct file *filp,unsigned int cmd,unsigned long arg)
{
	switch(cmd)
	{
		case IOCTL_DELETE_LIST:
		while(head)
		{
			struct node *next=head->next;
			kfree(head);
			head=next;
		}
		break;
		default:
		return -ENOTTY;
	}
	return 0;
}


static int __init my_init(void)
{
	if(register_chrdev(0,"My_Device",&fops)<0)
	{
		pr_info("Faild to register\n");
		return -1;
	}
	pr_info("Loaded\n");
	return 0;
}

static void __exit my_exit(void)
{
	unregister_chrdev(0,"my_device");

	while(head)
	{
		struct node *next = head->next;
		kfree(head);
		head=next;
	}
	pr_info("unloaded\n");

}

module_init(my_init);
module_exit(my_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A kernel module that accepts integers from user space and adds them to a linked list");

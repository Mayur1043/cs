/* Kernel linked list - static nodes */

#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/list.h>

// linked list node definition
struct my_node
{
	int data;
	struct list_head my_list;
};

struct my_node2
{
	int data2;
	struct list_head2 my_list2;
};


// create list head pointer/node
EVEN_HEAD(my_head);
ODD_HEAD(my_head1);

static int __init my_mod_init(void)
{
	int count = 0;
	struct my_node *tmp;

	pr_info("Hello world from %s!\n", KBUILD_MODNAME);
	
	// create node1 using option #1
	struct my_node node1 =  
	{
		.data=10,
		.my_list = LIST_HEAD_INIT(node1.my_list)
	};
	// add node1
	list_add(&node1.my_list, &my_head);
	
	struct my_node node1 =  
	{
		.data=20,
		.my_list = LIST_HEAD_INIT(node2.my_list)
	};
	// add node2
	list_add(&node1.my_list, &my_head);
		
	
	//2ND structure of trail
	int count1 = 0;
	struct my_node2 *tmp;

	pr_info("Hello world from struct 2 %s!\n", KBUILD_MODNAME);
	
	// create node1 using option #1
	struct my_node node2 =  
	{
		.data2=21,
		.my_list2 = LIST_HEAD_INIT(node2.my_list2)
	};
	// add node1
	list_add(&node1.my_list2, &my_head1);
	
	struct my_node node2 =  
	{
		.data2=22,
		.my_list2 = LIST_HEAD_INIT(node2.my_list2)
	};
	// add node1
	list_add(&node1.my_list2, &my_head1);


	// create node2 using option #2
	/*struct my_node node2;
	node2.data = 20;
	INIT_LIST_HEAD(&node2.my_list);
	// add node2
	list_add(&node2.my_list, &my_head);
	
	list_for_each_entry(tmp, &my_head, my_list)
	{
		pr_info("Node %d, data=%d\n", count++, tmp->data);
	}*/

	return 0;
}

static void __exit my_mod_exit(void)
{
	pr_info("Goodbye world from %s!\n", KBUILD_MODNAME);

	return;
}

module_init(my_mod_init);
module_exit(my_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EDD <edd@cdac.gov.in>");
MODULE_DESCRIPTION("Kernel linked list - static nodes!");

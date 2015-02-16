#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");

static char *whom = "World";
static int howmany = 1;

module_param(howmany, int, S_IRUGO);
module_param(whom, charp, S_IRUGO);

static int __init hello_init(void)
{
	int i;
	for (i = 0; i < howmany; i++) 
		printk(KERN_INFO "Hello, %s!\n", whom);
	return 0;
}

static void __exit hello_cleanup(void)
{
	int i;
	for (i = 0; i < howmany; i++) 
		printk(KERN_INFO "See you later, %sigator.\n", whom);
}

module_init(hello_init);
module_exit(hello_cleanup);

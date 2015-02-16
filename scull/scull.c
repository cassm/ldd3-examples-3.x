#include <linux/module.h>
#include <linux/init.h>
#include "scull.h"

int scull_major =   SCULL_MAJOR;
int scull_minor =   0;

struct file_operations scull_fops = {
	.owner = THIS_MODULE,
	.llseek = scull_llseek,
	.read = scull_read,
	.write = scull_write,
	.ioctl = scull_ioctl,
	.open = scull_open,
	.release = scull_release,
};

static int __init scull_init_module(void)
{
	if (scull_major) {		
		dev = MKDEV(scull_major, scull_minor);
		result = register_chrdev_region(dev, scull_nr_devs, "scull");
	} else {
		result = alloc_chrdev_region(&dev, scull_minor, scull_nr_devs, "scull");
		scull_major = MAJOR(dev);
	}
	if (result < 0) {
		printk(KERN_WARNING "scull: can't get major %d\n", scull_major);
		return result;
	}
}

static int __exit scull_cleanup_module(void)
{
	
}

module_init(scull_init_module);
module_exit(scull_cleanup_module);

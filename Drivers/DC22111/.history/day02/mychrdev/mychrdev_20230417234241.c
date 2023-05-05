#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>


int (*open) (struct inode *, struct file *);
ssize_t (*read) (struct file *, char __user *, size_t, loff_t *);
	ssize_t (*write) (struct file *, const char __user *, size_t, loff_t *);

const struct file_operations fops = 
{
    .open = ,
    .read =,
    .write =,
    .release =,
};

int __init mychrdev_init(void)
{
    //字符设备驱动注册
    register_chrdev(0,"mychrdev",&fops);
    return 0;
}

void __exit mychrdev_exit(void)
{
    unregister_chrdev();
}


module_init(mychrdev_init);
module_exit(mychrdev_exit);
MODULE_LICENSE("GPL");

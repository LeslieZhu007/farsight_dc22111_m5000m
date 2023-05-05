#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#define CNAME "myled"

ssize_t myled_read (struct file *fp, char __user *ubuf, size_t size, loff_t *offs)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}
ssize_t myled_write (struct file *fp, const char __user *ubuf, size_t size, loff_t *offs)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;

}
int myled_open (struct inode *inp, struct file *fp)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}
int myled_release (struct inode *inp, struct file *fp)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}


const struct file_operations fops
={
	.read = myled_read,
	.write = myled_write,
	.open = myled_open,
	.release = myled_release,

};

int major = 0;

static int __init myled_init(void)
{
	//创建字符设备驱动
	major = register_chrdev(0,CNAME,&fops);

	if(major < 0)
	{
		printk("register char device driver error\n");
		return major;
	}
	return 0;

}

static void __exit myled_exit(void)
{
	//销毁字符设备驱动
	unregister_chrdev(major,CNAME);
}

module_init(myled_init);
module_exit(myled_exit);
MODULE_LICENSE("GPL");

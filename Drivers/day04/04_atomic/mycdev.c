#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/spinlock.h>
#include <linux/types.h>

#define CNAME "mycdev"
#define COUNT 3

struct cdev *cdev = NULL;
struct class *cls = NULL;
struct device *dev = NULL;

int major = 0;
int minor = 0;
char kbuf[100] = {0};

atomic_t atm = ATOMIC_INIT(1);
;

int mycdev_open(struct inode *inode, struct file *filp)
{
	if(!atomic_dec_and_test(&atm))
	{
		printk("atomic dec and test error\n");
		atomic_inc(&atm);
		return -EBUSY;
	}
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}

ssize_t mycdev_read(struct file *filp, 
	char __user *ubuf, size_t size, loff_t *offs)
{
	int ret; 
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	
	if(size > sizeof(kbuf))
	{
		size = sizeof(kbuf);	
	}

	ret = copy_to_user(ubuf,kbuf,size);

	if(ret)
	{
		printk("copy_to_user error\n");
		return -EINVAL;
	}


	return 0;
}
ssize_t mycdev_write(struct file *filp, 
	const char __user *ubuf, size_t size, loff_t *offs)
{
    int ret; 
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);

	if(size > sizeof(kbuf))
	{
		size = sizeof(kbuf);
	}

	ret =  copy_from_user(kbuf,ubuf,size);
	if(ret)
	{
		printk("copy from user error\n");

		return -EINVAL;
	}
	
	return 0;
}

int mycdev_close(struct inode *inode, struct file *filp)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	atomic_inc(&atm);
	return 0;
}

const struct file_operations fops = {
	.open = mycdev_open,
	.read = mycdev_read,
	.write = mycdev_write,
	.release = mycdev_close,
};




static int __init mycdev_init(void)
{
	int ret,i;
	dev_t devno;
	//1.分配对象
	cdev = cdev_alloc();
	if(cdev == NULL)
	{
		printk("cdev alloc error\n");
		ret = -ENOMEM;
		goto ERR_STEP1;
	}

	//2.对象初始化
	cdev_init(cdev,&fops);

	//3.设备号的申请
	if(major > 0)
	{
		//3.1 major > 0静态指定设备号
		ret = register_chrdev_region(MKDEV(major,minor),COUNT,CNAME);
		if(ret)
		{
			printk("register chrdev region error\n");
			goto ERR_STEP2;
		}

	} else
	{
		//3.2 major <= 0 动态指定设备号
		ret = alloc_chrdev_region(&devno,minor,
		COUNT,CNAME);
		if(ret)
		{
			printk("dynamically alloc chrdev region error\n");
			goto ERR_STEP2;
		}
		major = MAJOR(devno);
		minor = MINOR(devno);
	}
	
	printk("major = %d,minor = %d\n",major,minor);
	//4.对象注册
	ret = cdev_add(cdev,MKDEV(major,minor),COUNT);
	if(ret)
	{
		printk("cdev add error\n");
		goto ERR_STEP3;
	}

	//5.自动创建设备节点
	
	//5.1 向上提交一个目录名
	cls = class_create(THIS_MODULE,"hello");
	if(IS_ERR(cls))
	{
		printk("class create error\n");
		ret = PTR_ERR(cls);
		goto ERR_STEP4;
	}
	//5.2 提交节点的信息
	for(i = 0; i < COUNT;i++)
	{
		dev = device_create(cls,NULL,MKDEV(major,minor+i),NULL,
			"mycdev%d",i);
		if(IS_ERR(dev))
		{
			printk("device create error\n");
			ret = PTR_ERR(dev);
			goto ERR_STEP5;
		}
	}

		
	return 0;
	
ERR_STEP5:
	for(--i; i >= 0;i--)
	{
		device_destroy(cls,MKDEV(major,minor+i));
	}
	class_destroy(cls);
ERR_STEP4:
	cdev_del(cdev);
ERR_STEP3:
	unregister_chrdev_region(MKDEV(major,minor),COUNT);
ERR_STEP2:
	kfree(cdev);
ERR_STEP1:
	return ret;
	
}


static void __exit mycdev_exit(void)
{
	int i;
	for(i = 0; i < COUNT;i++)
	{
		device_destroy(cls,MKDEV(major,minor+i));
	}

	
	class_destroy(cls);

	cdev_del(cdev);

	unregister_chrdev_region(MKDEV(major,minor),COUNT);

	kfree(cdev);

}

module_init(mycdev_init);
module_exit(mycdev_exit);

MODULE_LICENSE("GPL");


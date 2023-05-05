#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#define CNAME "myled"
int major = 0;
char kbuf[128] = {0};
int ret1;
int ret2;
ssize_t myled_read (struct file *fp, char __user *ubuf, size_t size, loff_t *offs)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	//�Դ�С����У��
	if(size > sizeof(kbuf))
	{
		size = sizeof(kbuf);	
	}
	ret1 = copy_to_user(ubuf,kbuf,size);

	//�ɹ�����0��ʧ�ܷ���δ�������ֽڵĸ���
	if(ret1)
	{
		printk("copy_to_user error\n");
		//���ܹ����ⷵ��
		return -EINVAL;
	}

	return size;
}
ssize_t myled_write (struct file *fp, const char __user *ubuf, size_t size, loff_t *offs)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);

	//�Դ�С����У��
	if(size > sizeof(kbuf))
	{
		size = sizeof(kbuf);	
	}
	ret2 = copy_from_user(kbuf,ubuf,size);

	//�ɹ�����0��ʧ�ܷ���δ�������ֽڵĸ���
	if(ret2)
	{
		printk("copy_from_user error\n");
		//���ܹ����ⷵ��
		return -EINVAL;
	}

	return size;

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



static int __init myled_init(void)
{
	//�����ַ��豸����
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
	//�����ַ��豸����
	unregister_chrdev(major,CNAME);
}

module_init(myled_init);
module_exit(myled_exit);
MODULE_LICENSE("GPL");

#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/io.h> 
#include "myled.h"
#define CNAME "myled"
int major = 0;
char kbuf[128] = {0};
gpio_t *gpioe = NULL;
unsigned int *rcc;
#define LED1_ON  (gpioe->ODR|=(0x1<<10))
#define LED1_OFF (gpioe->ODR&=~(0x1<<10))

int myled_open (struct inode *inp, struct file *fp)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);

	
	//1.ӳ���ַ
	gpioe = ioremap(GPIOE_PHY_BASE,sizeof(gpio_t));
	if(gpioe == NULL)
	{
		printk("gpioe ioremap error\n");
		return -ENOMEM;
	}
	
	rcc = ioremap(RCC_ENB,4);	
	if(rcc == NULL)
	{
		printk("rcc ioremap error\n");
		return -ENOMEM;
	}


	//2.��ʼ����
	
	*rcc |=(0x1<<4); //rcc enable gpioe
	gpioe->MODER&=~(0x3<<20); //clear bit 20-21
	gpioe->MODER|=(0x1<<20); //output
	gpioe->ODR&=~(0x1<<10);	//led1 off


	
	return 0;
}



ssize_t myled_read (struct file *fp, char __user *ubuf, size_t size, loff_t *offs)
{
	int ret;
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	
	//�Դ�С����У��
	if(size > sizeof(kbuf))
	{
		size = sizeof(kbuf);	
	}
	ret = copy_to_user(ubuf,kbuf,size);

	//�ɹ�����0��ʧ�ܷ���δ�������ֽڵĸ���
	if(ret)
	{
		printk("copy_to_user error\n");
		//���ܹ����ⷵ��
		return -EINVAL;
	}

	return size;
}
ssize_t myled_write (struct file *fp, const char __user *ubuf, size_t size, loff_t *offs)
{
	int ret;
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	
	//�Դ�С����У��
	if(size > sizeof(kbuf))
	{
		size = sizeof(kbuf);	
	}
	ret = copy_from_user(kbuf,ubuf,size);

	//�ɹ�����0��ʧ�ܷ���δ�������ֽڵĸ���
	if(ret)
	{
		printk("copy_from_user error\n");
		//���ܹ����ⷵ��
		return -EINVAL;
	}

	
	//LED_ON;
	//kbuf[0] == 1?LED1_ON:LED1_OFF;
	if(kbuf[0] == 1)
	{
		LED1_ON;
	} else
	{
		LED1_OFF;
	}
	

	

	return size;

}
int myled_release (struct inode *inp, struct file *fp)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	//�ص��ҽ��ӳ��
	gpioe->ODR&=~(0x1<<10);
	iounmap(gpioe);
	iounmap(rcc);
	
	
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

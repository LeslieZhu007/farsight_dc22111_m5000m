#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include "myled.h"

#define CNAME "myled"

int major = 0;
char kbuf[128] = {0};
gpio_t *gpioe = NULL;
unsigned int * rcc;

#define LED1_ON (gpioe->ODR   |=(1<<10)) //led1 on
#define LED1_OFF (gpioe->ODR  &=~(1<<10)) //led1 off

int myled_open(struct inode *inode, struct file *filp)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	//1.映射地址
	gpioe = ioremap(GPIOE_PHY_BASE,sizeof(gpio_t));
	if(gpioe == NULL){
		printk("ioremap gpioe base error\n");
		return -ENOMEM;
	}
	
	rcc = ioremap(RCC_ENB,4);
	if(rcc == NULL){
		printk("ioremap rcc error\n");
		return -ENOMEM;
	}
	//2.初始化灯
	*rcc |= (1<<4);  //rcc enable gpioe
	gpioe->MODER &=~(3<<20);//clear bit 20-21
	gpioe->MODER |=(1<<20); //output
	gpioe->ODR   &=~(1<<10); //led1 off
	
	return 0;
}

ssize_t myled_read(struct file *filp, 
	char __user *ubuf, size_t size, loff_t *offs)
{
	int ret;
	
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	
	if(size > sizeof(kbuf)) size = sizeof(kbuf);
	ret = copy_to_user(ubuf,kbuf,size);
	if(ret){
		printk("copy data to user error\n");
		return -EINVAL;
	}
	
	return size;

}

ssize_t myled_write(struct file *filp, 
	const char __user *ubuf, size_t size, loff_t *offs)
{
	int ret;
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	if(size > sizeof(kbuf)) size = sizeof(kbuf);
	ret = copy_from_user(kbuf,ubuf,size);
	if(ret){
		printk("copy data from user error\n");
		return -EINVAL;
	}

	kbuf[0] == 1?LED1_ON:LED1_OFF;
	
	return size;
}

int myled_close(struct inode *inode, struct file *filp)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	gpioe->ODR   &=~(1<<10); //led1 off
	
	iounmap(gpioe);
	iounmap(rcc);
	return 0;
}

const struct file_operations fops = {
	.open = myled_open,
	.read = myled_read,
	.write = myled_write,
	.release = myled_close,
};

static int __init myled_init(void)
{
	//创建字符设备驱动
	major = register_chrdev(0,CNAME,&fops);
	if(major < 0){
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















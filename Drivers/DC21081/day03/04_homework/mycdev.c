#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include "myled.h"


#define CNAME "mycdev"
#define COUNT 3


gpio_t *gpioe = NULL;
gpio_t *gpiof = NULL;

unsigned int *rcc = NULL;
unsigned int *ahb5 = NULL;
unsigned int *tzen = NULL;

#define LED1_ON (gpioe->ODR |= (0x1<<10))
#define LED1_OFF (gpioe->ODR &= ~(0x1<<10))

#define LED2_ON (gpiof->ODR |= (0x1<<10))
#define LED2_OFF (gpiof->ODR &= ~(0x1<<10))

#define LED3_ON (gpioe->ODR |= (0x1<<8))
#define LED3_OFF (gpioe->ODR &= ~(0x1<<8))



struct cdev *cdev = NULL;
struct class *cls = NULL;
struct device *dev = NULL;

int major = 0;
int minor = 0;

//get minor for writing purpose
int curminor;
char kbuf[100] = {0};

int myled_open(struct inode *inode, struct file *filp)
{
	//inode contains device number
	dev_t devno = inode->i_rdev;
	curminor = MINOR(devno);
	printk("curminor = %d\n",curminor);
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}

ssize_t myled_read(struct file *filp, 
	char __user *ubuf, size_t size, loff_t *offs)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}
ssize_t myled_write(struct file *filp, 
	const char __user *ubuf, size_t size, loff_t *offs)
{
	int ret;
	
	if(size > sizeof(kbuf))
	{
		size = sizeof(kbuf);
	}
	//copy data from user space
	ret = copy_from_user(kbuf,ubuf,size);
	if(ret)
	{
		printk("copy from user error\n");
		return ret;
	}	



	//determine which light will be on and off based on curminor
	switch(curminor)
	{
		case 0:
		{
			kbuf[0] == '1'?LED1_ON:LED1_OFF;
			printk("kbuf[0] = %c\n",kbuf[0]);
			kbuf[0] == '1'?(printk("LED1 ON\n")):(printk("LED1 OFF\n"));
			break;
		}


		case 1:
		{
			kbuf[0] == '1'?LED2_ON:LED2_OFF;
			printk("kbuf[0] = %c\n",kbuf[0]);
			kbuf[0] == '1'?(printk("LED2 ON\n")):(printk("LED2 OFF\n"));
			break;
		}

		case 2:
		{
		//	kbuf[0] == '1'?LED3_ON:LED3_OFF;
			printk("kbuf[0] = %c\n",kbuf[0]);
			kbuf[0] == '1'?(printk("LED3 ON\n")):(printk("LED3 OFF\n"));
			break;
		}


	}
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return size;
}

int myled_close(struct inode *inode, struct file *filp)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}

const struct file_operations fops = {
	.open = myled_open,
	.read = myled_read,
	.write = myled_write,
	.release = myled_close,
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

	//GPIO function initialization
	
	//1.addr mapping from physical addr
		gpioe = ioremap(GPIOE_PHY_BASE,sizeof(gpio_t));
		if(gpioe == NULL)
		{
			printk("gpioe ioremap error\n");
			return -ENOMEM;
		}
	
		gpiof = ioremap(GPIOF_PHY_BASE,sizeof(gpio_t));
		if(gpiof == NULL)
		{
			printk("gpiof ioremap error\n");
			return -ENOMEM;
		}
		
		rcc = ioremap(RCC_ENB,4);	
		if(rcc == NULL)
		{
			printk("rcc ioremap error\n");
			return -ENOMEM;
		}
	
		//map the address of AHB5 and TZEN and print out the value stored in the address
		ahb5 = ioremap(0x50000210,4); //ahb5??
		if(ahb5 == NULL)
		{
			printk("ahb5 ioremap error\n");
			return -ENOMEM;
		}
	
		
		tzen = ioremap(0x54000000,4);  //RCC_TZCR	0x000
		if(tzen == NULL)
		{
			printk("tzen ioremap error\n");
			return -ENOMEM;
		}
	
		printk("value in the mapped ahb5 memory ====> %#x",*ahb5);
		printk("value in the mapped tzen memory ====> %#x",*tzen);
		printk("value in the mapped rcc memory ====> %#x",*rcc);
		printk("value in the mapped gpioe memory ====> %#x",*gpioe);
		printk("value in the mapped gpiof memory ====> %#x",*gpiof);
	
	
		//2. rcc clock enable
		
		*rcc |= (0x1<<4); //rcc enable gpioe
		*rcc |= (0x1<<5); //rcc enable gpiof
		gpioe->MODER &= ~(0x3<<20); //clear bit 20-21
		//LED1	gpioe->MODER |= ~(0x1<<20); //output
		gpioe->MODER |= (0x1<<20); //output
		gpioe->ODR &= ~(0x1<<10);	//led1 off
	
		//LED2
		gpiof->MODER &= ~(0x3<<20);  
		gpiof->MODER |= (0x1<<20); //output
		gpiof->ODR &= ~(0x1<<10);	//led2 off

		//LED3
		//gpioe->MODER &= ~(0x3<<16);//clear bit 16-17
		//gpioe->MODER |= (0x1<<16); //output
		//gpioe->ODR &= ~(0x1<<8);	//led3 off
	


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
	//LED lights off and undo ioremap
	gpioe->ODR &= ~(0x1<<10);
	gpiof->ODR &= ~(0x1<<10);
	gpioe->ODR &= ~(0x1<<8);
	iounmap(gpioe);
	iounmap(gpiof);
	iounmap(rcc);
	iounmap(ahb5);
	iounmap(tzen);


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


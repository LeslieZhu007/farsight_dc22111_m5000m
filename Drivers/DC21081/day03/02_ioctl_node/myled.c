#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/io.h> 
#include <linux/device.h>
#include "myled.h"
#define CNAME "myled"
int major = 0;
char kbuf[128] = {0};
int ret2;
int ret1;
gpio_t *gpioe = NULL;
gpio_t *gpiof = NULL;

unsigned int *rcc = NULL;
unsigned int *ahb5 = NULL;
unsigned int *tzen = NULL;



#define LED1_ON  (gpioe->ODR |= (0x1<<10))
#define LED1_OFF (gpioe->ODR &= ~(0x1<<10))

#define LED2_ON  (gpiof->ODR |= (0x1<<10))
#define LED2_OFF (gpiof->ODR &= ~(0x1<<10))

struct class *cls;
struct device *dev;



ssize_t myled_read (struct file *fp, char __user *ubuf, size_t size, loff_t *offs)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	
	//对大小进行校验
	if(size > sizeof(kbuf))
	{
		size = sizeof(kbuf);	
	}
	ret2 = copy_to_user(ubuf,kbuf,size);

	//成功返回0，失败返回未拷贝的字节的个数
	if(ret2)
	{
		printk("copy_to_user error\n");
		//不能够随意返回
		return -EINVAL;
	}

	return size;
}
int ret1;
ssize_t myled_write (struct file *fp, const char __user *ubuf, size_t size, loff_t *offs)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	
	//对大小进行校验
	if(size > sizeof(kbuf))
	{
		size = sizeof(kbuf);	
	}
	ret1 = copy_from_user(kbuf,ubuf,size);

	//成功返回0，失败返回未拷贝的字节的个数
	if(ret1)
	{
		printk("copy_from_user error\n");
		//不能够随意返回
		return -EINVAL;
	}

	printk("buf[0] in myled_write = %c\n",kbuf[0]);

	kbuf[0] == 1?LED1_ON:LED1_OFF;

	

	return size;

}
int myled_open (struct inode *inp, struct file *fp)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);

	
	//1.映射地址
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
	ahb5 = ioremap(0x50000210,4); //ahb5地址
	if(ahb5 == NULL)
	{
		printk("ahb5 ioremap error\n");
		return -ENOMEM;
	}

	
	tzen = ioremap(0x54000000,4);  //RCC_TZCR   0x000
	if(tzen == NULL)
	{
		printk("tzen ioremap error\n");
		return -ENOMEM;
	}

	printk("value in the mapped ahb5 memory ====> %#x",*ahb5);
	printk("value in the mapped tzen memory ====> %#x",*tzen);


	//2.初始化灯
	
	*rcc |= (0x1<<4); //rcc enable gpioe
	*rcc |= (0x1<<5); //rcc enable gpiof
	gpioe->MODER &= ~(0x3<<20); //clear bit 20-21
	//排查半天查不出来的错误，此处不能取反，会导致内核卡死    gpioe->MODER |= ~(0x1<<20); //output
	gpioe->MODER |= (0x1<<20); //output
	gpioe->ODR &= ~(0x1<<10);	//led1 off

	//LED2
	gpiof->MODER &= ~(0x3<<20);  
	gpiof->MODER |= (0x1<<20); //output
	gpiof->ODR &= ~(0x1<<10);	//led2 off


	
	return 0;
}


long myled_ioctl (struct file *fp, unsigned int cmd, unsigned long args)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	switch(cmd)
	{
		int data,ret;
		image_t image;
		case LED2_OP:
		{
			//对LED灯进行操作
			ret = copy_from_user((void *)&data,(void *)args,GET_CMD_SIZE(LED2_OP));
			if(ret)
			{
				printk("copy from user error\n");
			}

			printk("data received from user space is ====> %d",data);

			data == 1? LED2_ON:LED2_OFF;
			
			break;
		}
		case IMAGE_STRUCT:
		{
			//receive the image,plus 10 then return to user space
			ret = copy_from_user((void *)&image,(void *)args,GET_CMD_SIZE(IMAGE_STRUCT));
			if(ret)
			{
				printk("IMAGE_STRUCT copy from user error\n");
			}

			printk("image received from user space,height = %d,width = %d,image_type = %s\n",image.height,image.width,image.image_type);

			//height and width +10,then return to user space;
			
			image.height +=10;
			image.width += 10;
			ret = copy_to_user((void*)args,(void *)&image,GET_CMD_SIZE(IMAGE_STRUCT));
			if(ret)
			{
				printk("IMAGE_STRUCT copy to user error\n");
			}

			break;
		}

		case CHR_BUF:
		{
			//receive the value then print
			ret = copy_from_user((void *)kbuf,(void *)args,GET_CMD_SIZE(CHR_BUF));
			if(ret)
			{
				printk("CHR_BUF copy from user error\n");
			}

			printk("CHR_BUF data received from user space is ====> %s\n",kbuf);
			
			break;
		}

	}
	return 0;

}



int myled_release (struct inode *inp, struct file *fp)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	//关灯且解除映射
	gpioe->ODR &= ~(0x1<<10);
	gpiof->ODR &= ~(0x1<<10);
	iounmap(gpioe);
	iounmap(gpiof);
	iounmap(rcc);
	iounmap(ahb5);
	iounmap(tzen);
	
	
	return 0;
}


const struct file_operations fops
={
	.read = myled_read,
	.write = myled_write,
	.open = myled_open,
	.unlocked_ioctl = myled_ioctl,
	.release = myled_release,

};



static int __init myled_init(void)
{
	int ret;
	//1.创建字符设备驱动
	major = register_chrdev(0,CNAME,&fops);

	if(major < 0)
	{
		printk("register char device driver error\n");
		ret = major;
		goto ERR_STEP1;
	}

	//2. 自动创建设备节点
	cls = class_create(THIS_MODULE,CNAME);
	if(IS_ERR(cls))
	{
		printk("class create error\n");
		ret = PTR_ERR(cls);
		goto ERR_STEP2;
		
	}

	dev = device_create(cls,NULL,MKDEV(major,0),NULL,"myled");
	if(IS_ERR(dev))
	{
		printk("device create error\n");
		ret = PTR_ERR(dev);
		goto ERR_STEP3;
		
	}

	
	return 0;
	
ERR_STEP3:
	class_destroy(cls);
	
ERR_STEP2:
	unregister_chrdev(major,CNAME);
		
ERR_STEP1:
	return ret;	
	
	

}

static void __exit myled_exit(void)
{
    device_destroy(cls,MKDEV(major,0));

	class_destroy(cls);

	//销毁字符设备驱动
	unregister_chrdev(major,CNAME);
}

module_init(myled_init);
module_exit(myled_exit);
MODULE_LICENSE("GPL");

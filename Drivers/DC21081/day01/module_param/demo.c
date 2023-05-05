#include <linux/init.h>
#include <linux/init.h>
#include <linux/module.h>
int backlight = 10;
module_param(backlight,int,0664);
MODULE_PARM_DESC(backlight,"This is control backlight var,range[0-255]");

char ch='a';
module_param(ch,byte,0664);
MODULE_PARM_DESC(ch,"This is char variable");

char *p = "hello world";
module_param(p,charp,0444);
MODULE_PARM_DESC(p,"This is char pointer variable");

int array[10] = {0};
int nump;
module_param_array(array,int,&nump,0664);
MODULE_PARM_DESC(array,"This is an int[10] array");


char ch1 = 'H';
module_param(ch1,byte,0664);
MODULE_PARM_DESC(ch1,"This is added in 2022.10.6");


char *p1 = "Today is 10.6 in 2022,a decisive day";
module_param(p1,charp,0664);
MODULE_PARM_DESC(p1,"This is a charp which is basically a string");

static int __init demo_init(void)
{
	int i;
	printk(KERN_ERR "This is 21081 driver init\n");
	printk("init backlight=%d\n",backlight);
	printk("init ch=%c\n",ch);
	printk("init p=%s\n",p);
	printk("init ch1=%c\n",ch1);
	printk("init p1=%s\n",p1);
	
	printk("number of the array read is :%d\n",nump);
	for(i=0;i<nump;i++)
	{
		printk("init array[%d]=%d\n",i,array[i]);
	}


	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	printk(KERN_INFO "*************888%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}


static void __exit demo_exit(void)
{

	printk("exit backlight=%d\n",backlight);
	printk(KERN_ERR "This is 21081 driver exit\n");
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);

}

module_init(demo_init);
module_exit(demo_exit);

MODULE_LICENSE("GPL");

#include <linux/init.h>
#include <linux/module.h>
#include <linux/blkdev.h>
#include <linux/genhd.h>
#include <linux/blk-mq.h>
#include <linux/hdreg.h>
#include <linux/vmalloc.h>



#define BSIZE (1*1024*1024)
#define BNAME "mydisk"
struct gendisk *disk;
struct request_queue *q;
struct blk_mq_tag_set set;
int major;

//alloc 1MiB size of memory
char *addr;


blk_status_t mydisk_queue_rq(struct blk_mq_hw_ctx *htctx,
				 const struct blk_mq_queue_data *bd)
{
	//queue analysis
	blk_status_t status = BLK_STS_OK;
	struct request *rq = bd->rq;


	struct bio_vec bvec;
    struct req_iterator iter;
	//offset bytes relative to magnetic head
    loff_t pos = blk_rq_pos(rq) << SECTOR_SHIFT;
	/*
		Already defined in the file 1MiB
    loff_t dev_size = (loff_t)(dev->capacity << SECTOR_SHIFT);
	*/
	
	//start processing queue
	blk_mq_start_request(rq);

	/*************processing************/

	//analyze queue,finish data writing and reading
    rq_for_each_segment(bvec, rq, iter)
    {
    	//length
        unsigned long b_len = bvec.bv_len;
		//user address
        void* b_buf = page_address(bvec.bv_page) + bvec.bv_offset;

		/*
			//index out of bounds validate
	          if ((pos + b_len) > BSIZE)
              b_len = (unsigned long)(BSIZE - pos);
        */

		//disk address ==> addr + pos
		
		// rq_data_dir(rq) get read,write
        if (rq_data_dir(rq))//WRITE
        	//dest: disk
        	//source: user
        	//size: b_len
            memcpy(addr + pos, b_buf, b_len);
        else//READ
        	//dest: user
        	//source:disk 
        	//size: b_len
            memcpy(b_buf, addr + pos, b_len);

        pos += b_len;
    }
	/**************processing***********/

	//end processing queue
	blk_mq_end_request(rq, status);

	return status;
}

const struct blk_mq_ops mqops =
{
	.queue_rq = mydisk_queue_rq,
};

int mydisk_open (struct block_device * blkdev, fmode_t mode)
{
	printk("%s:%d\n",__func__,__LINE__);
	return 0;

}
void mydisk_release (struct gendisk *gdisk, fmode_t mode)
{

	printk("%s:%d\n",__func__,__LINE__);


}

/*
	struct hd_geometry {
      unsigned char heads;
      unsigned char sectors;
      unsigned short cylinders;
      unsigned long start;
};
*/

int mydisk_getgeo(struct block_device *blkdev, struct hd_geometry *hd)
{
	printk("%s:%d\n",__func__,__LINE__);

	hd->heads = (char)4;
	hd->cylinders = 16;
	hd->sectors = (BSIZE/(hd->heads)/(hd->cylinders)/512);
	return 0;
}


const struct block_device_operations fops =
{
	.open = mydisk_open,
	.release = mydisk_release,
	.getgeo = mydisk_getgeo,
};


static int __init mydisk_init(void)
{
	//1.allocate an object
	disk = alloc_disk(4);
	if(disk == NULL)
	{
		printk("alloc gendisk memory error\n");
		return -ENOMEM;
	}

	//2.initialize an object
	//2.1 apply a major dev no
	major = register_blkdev(0, BNAME);
	if (major < 0)
	{
		printk("alloc block device number error\n");
		return major;
	}

	//2.2 request a request_queue
	q = blk_mq_init_sq_queue(&set, 
	&mqops, 2, BLK_MQ_F_SHOULD_MERGE);

	if(q == NULL)
	{
		printk("alloc multi queue error\n");
		return -EAGAIN;
	}
	disk->major = major;
	disk->first_minor = 0;
	strcpy(disk->disk_name, BNAME);
	set_capacity(disk, BSIZE>>9); //BSIZE/512
	disk->fops = &fops;
	disk->queue = q;

	//3.alloc 1MiB size of memory in the kernel
	addr = vmalloc(BSIZE);
	if(addr == NULL)
	{
		printk("vmalloc error\n");
		return -ENOMEM;
	}
	
	//4.register
	

	add_disk(disk);
	return 0;
}

static void __exit mydisk_exit(void)
{
	del_gendisk(disk);
	vfree(addr);
	blk_cleanup_queue(q);
	unregister_blkdev(major, BNAME);
	put_disk(disk);

}

module_init(mydisk_init);
module_exit(mydisk_exit);
MODULE_LICENSE("GPL");




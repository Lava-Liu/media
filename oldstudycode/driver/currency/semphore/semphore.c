/* ==================================================================
 *       Filename:  chardev.c
 *    Description:  
 *        Created:  2013年10月18日 11时16分25秒
 *       Compiler:  gcc/g++
 *         Author:  Star (Liu Wei), 384439695@qq.com
 *        Company:  昆山杰普科技有限公司
 * ==================================================================*/
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
     //struct cdev , cdev_init/cdev_add/cdev_del
#include <linux/types.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
#include <linux/semaphore.h>
#include <linux/delay.h>
	//kmalloc/kfree
#define MAJOR_NUM 200
#define MINOR_NUM 0
#define DEV_NAME "chardev"
#define MAX_LEN  0x1000 //4kb
static int major_num = 0;

typedef struct
{
	struct  cdev cdev;
	char    data[MAX_LEN];
	size_t  cur_len;//记录当前的数据长度
	struct  semaphore sem;
	//unsigned char   *data;
	

}global_dev;
global_dev* devp = NULL;
static ssize_t char_read(struct file* file , char __user *buffer, size_t size, loff_t *offset)
{
	ssize_t ret = 0;
	unsigned long p = (unsigned long )*offset;
	size_t count = 0; //真正要移动的数据长度
	down_interruptible(&devp->sem);
	if(size > devp->cur_len - p)
	{

		count = devp->cur_len -p;
	}else
	{
		count = size;
	}
	ret = copy_to_user(buffer, devp->data + p, count);
	if(ret >0) //failure
	{
		ret = count -ret;
	}else{
		ret = count ;
	}
    printk(KERN_INFO"read %d bytes data(%s) successful!\n", ret, devp->data);
	//移动文件操作的偏移量
	file->f_pos +=ret;
	*offset += ret;
	ssleep(10);

	up(&devp->sem);

	return ret;
}
static ssize_t char_write(struct file* file ,const char __user *buffer, size_t size, loff_t *offset)
{
	ssize_t ret = 0;
	unsigned long p = (unsigned long )*offset;
	size_t count = 0; //真正要移动的数据长度
	down_interruptible(&devp->sem);
	if(size > MAX_LEN - p)
	{

		count = MAX_LEN -p;
	}else
	{
		count = size;
	}
	ret = copy_from_user(devp->data + p,buffer,  count);
	if(ret >0) //failure
	{
		ret = count -ret;
	}else{
		ret = count ;
	}
    printk(KERN_INFO"read %d bytes data(%s) successful!\n", ret, devp->data);

	//移动文件操作的偏移量
	file->f_pos +=ret;
	*offset += ret;
	devp->cur_len+=ret;
	ssleep(10);
	up(&devp->sem);


	return ret;
}
static int char_open(struct inode* inode, struct file* file)
{
	if(file->f_mode & FMODE_PREAD)
	{
		printk(KERN_INFO"open with readonly!\n");

	}else if(file->f_mode & FMODE_WRITE)
	{
		printk(KERN_INFO"open with writeonly!\n");

	}else{
		printk(KERN_INFO"open with rdwr!\n");

	}
	//判断文件的打开的标记
	if(file->f_flags & O_NONBLOCK)
	{
		printk(KERN_INFO"open with nonblock!\n");
		
	}else{
		printk(KERN_INFO"open with block!\n");

	}
	printk(KERN_INFO"postion: %lld\n", file->f_pos);
	printk(KERN_INFO"i_uid: %u\n " , inode->i_uid);
	printk(KERN_INFO"i_gid: %u\n " , inode->i_gid);
	//手动准备数据
	
	//strcpy(devp->data, "abcdefghijklmb");
	//devp->cur_len = strlen(devp->data);
	return 0;
}
static int char_close(struct inode* inode, struct file* file)
{
	printk(KERN_INFO"char_close() invoked\n");
	return 0;
}
//字符设备的文件操作方法的封装
static const struct file_operations fops={
	.owner   = THIS_MODULE, 
	.open    = char_open, 
	.release = char_close, 
	.read    = char_read,
	.write   = char_write, 
};

MODULE_LICENSE("Dual BSD/GPL");
static void char_setup(global_dev* devp, dev_t devno)
{
	cdev_init(&devp->cdev,&fops );
	if(cdev_add(&devp->cdev,devno, 1))
	{
		printk(KERN_ERR"cdev_add error!\n");
	}else
	{
		printk(KERN_INFO"cdev_add successful!\n");
	}

}
static int __init char_init(void)
{
	//1、分配设备编号
	int ret = 0;
	dev_t devno;
	devno=MKDEV(MAJOR_NUM, MINOR_NUM);

	ret = register_chrdev_region(devno, 1, DEV_NAME);
	if(ret <0)
	{
		printk("register_chrdev_region error!\n");
		ret=alloc_chrdev_region(&devno, 0, 1, DEV_NAME);
		if(ret < 0)
		{
			printk("alloc_chrdev_region error!\n");
			return -EBADF;
		}
	}
	major_num = MAJOR(devno);
	printk("%d,", major_num);
	//2/给自定义设备的描述分配内存
	devp = (global_dev*)kmalloc(sizeof(global_dev), GFP_KERNEL);
	if(devp == NULL)
	{
		printk(KERN_ERR"kmalloc error!\n");
		return -ENOMEM;
	}
	printk(KERN_INFO"kmalloc successful!\n");
	memset(devp, 0, sizeof(global_dev));
	//初始化设备描述结构体
	char_setup(devp, devno);
	
	//初始化信号量
	sema_init(&devp->sem, 1);
	return 0;
}
static void __exit char_exit(void)
{
	cdev_del(&devp->cdev);
	kfree(devp);
	devp=NULL;
	unregister_chrdev_region(MKDEV(major_num, 0), 1);
	printk(KERN_INFO"char_exit successful!\n");
}



module_init(char_init);
module_exit(char_exit);

#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>

#include <linux/string.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>
#include <linux/init.h>

static dev_t first;
static struct cdev c_dev; 
static struct class *cl;

static struct proc_dir_entry* entry;

static size_t _count;

static ssize_t proc_write(struct file *file, const char __user * ubuf, size_t count, loff_t* ppos) 
{
  printk(KERN_DEBUG "Attempt to write proc file");
  return 0;
}

static ssize_t proc_read(struct file *file, char __user * ubuf, size_t count, loff_t* ppos) 
{
  int max_size = 10;
  int offset = 0;  
  char output[max_size];

  snprintf(&output[0], max_size, "%ld", _count);

  size_t len = strlen(output);
	
  if (*ppos > 0 || count < len){
		return 0;
	}

	if (copy_to_user(ubuf, output, len) != 0){
		return -EFAULT;
	}

	*ppos = len;
	return len;
}

static int my_open(struct inode *i, struct file *f)
{
  printk(KERN_INFO "Driver: open()\n");
  return 0;
}

static int my_close(struct inode *i, struct file *f)
{
  printk(KERN_INFO "Driver: close()\n");
  return 0;
}

/*
  copy data from char device 's buffer -> kernel buffer -> user buffer
*/
static ssize_t my_read(struct file *f, char __user *buf, size_t len, loff_t *off)
{
  printk(KERN_INFO "Driver: read()\n");
  return 0;
}

/*
  copy data from user buffer  -> kernel buffer  -> char device 's buffer
*/
static ssize_t my_write(struct file *f, const char __user *buf,  size_t len, loff_t *off)
{
  printk(KERN_INFO "Driver: write()\n");
  _count += len -1;
  *off += len;
  return len;
}

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.read = proc_read,
	.write = proc_write,
};

static struct file_operations mychdev_fops =
{
  .owner = THIS_MODULE,
  .open = my_open,
  .release = my_close,
  .read = my_read,
  .write = my_write
};
 
static int __init ch_drv_init(void)
{
    printk(KERN_INFO "Hello!\n");

   // res = res_init();

    entry = proc_create("var1", 0444, NULL, &fops);

    if (alloc_chrdev_region(&first, 0, 1, "ch_dev") < 0) return -1;
    
    //  create a class of device, which has name called "chardrv" in /sys/class
    if ((cl = class_create(THIS_MODULE, "chardrv")) == NULL){
      unregister_chrdev_region(first, 1);
      return -1;
	  }

    // create a device name "lab1" in /dev
    // need to change name, because can not kill 
    if (device_create(cl, NULL, first, NULL, "lab11") == NULL){
      class_destroy(cl);
      unregister_chrdev_region(first, 1);
      return -1;
	  }

    cdev_init(&c_dev, &mychdev_fops);

    if (cdev_add(&c_dev, first, 1) == -1){
      device_destroy(cl, first);
      class_destroy(cl);
      unregister_chrdev_region(first, 1);
      return -1;
	  }

    return 0;
}
 
static void __exit ch_drv_exit(void)
{
    proc_remove(entry);
    cdev_del(&c_dev);
    device_destroy(cl, first);
    class_destroy(cl);
    unregister_chrdev_region(first, 1);
    printk(KERN_INFO "Bye!!!\n");
}
 
module_init(ch_drv_init);
module_exit(ch_drv_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Duc Tran + Tuan Dung");
MODULE_DESCRIPTION("Character driver");
MODULE_VERSION("1.0");





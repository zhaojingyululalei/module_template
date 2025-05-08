#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#define CHARDEV_NAME    "chrdev"
#define CHARDEV_MAJOR   200
#define dbg(fmt, ...) printk("[%s:%d] %s: " fmt, __FILE__, __LINE__, __func__, ##__VA_ARGS__)
static int chrdev_open(struct inode *inode, struct file *flip)
{
    printk("chrdev_open\r\n");
    return 0;
}
static int chrdev_read(struct file *filp, char __user *buf, size_t count, loff_t *ppos)
{
    printk("chrdev_read\r\n");
    return 0;
}
static int chrdev_write(struct file *filp, const char __user *buf, size_t count, loff_t *ppos)
{
    printk("chrdev_write\r\n");
    return 0;
}
static int chrdev_release(struct inode *inode, struct file *flip)
{
    printk("chrdev_releasse\r\n");
    return 0;
}
static loff_t chrdev_lseek(struct file *file, loff_t offset, int whence)
{
    printk("chrdev_lseek\r\n");
    return 0;
}
static const struct file_operations chrdev_ops = {
    .write = chrdev_write,
    .read = chrdev_read,
    .open = chrdev_open,
    .release = chrdev_release,
    .llseek = chrdev_lseek,
    .owner = THIS_MODULE,
};

static int __init chrdev_init(void)
{
    int ret;
    printk("chrdev init......\r\n");
    ret = register_chrdev(CHARDEV_MAJOR,CHARDEV_NAME,&chrdev_ops);
    if(ret < 0){
        dbg("register_chrdev error\r\n");
        return -1;
    }
    return 0;
}
static void __exit chrdev_exit(void)
{
  
    printk("chrdev exit......\r\n");
    unregister_chrdev(CHARDEV_MAJOR,CHARDEV_NAME);
    
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("zhao");
module_init(chrdev_init)
module_exit(chrdev_exit)

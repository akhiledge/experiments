#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <asm/highmem.h>
#include <linux/leds.h> 
MODULE_LICENSE ("Dual BSD/GPL");
#define FIRST_MINOR 0
#define NR_DEVS 1

extern void led_trig_ide_activity (void);
int myOpen (struct inode *inode, struct file *filep );
int myRelease (struct inode *in, struct file *fp );
long myIoctl (struct file *f,unsigned int num, unsigned long num1);
static int myInit ( void );
static void myExit ( void );
struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = myOpen,
    .release = myRelease,
    .unlocked_ioctl = myIoctl
};

char *devname;
int majNo;
static dev_t mydev;
struct cdev *my_cdev;

module_param ( devname, charp, 0000 );
static struct class *mychar_class;
static struct device *mychar_device;
int myOpen ( struct inode *inode, struct file *filep)
{
    printk (KERN_INFO "Open euccess\n");
    return 0;
}

int myRelease ( struct inode *in, struct file *fp )
{
    printk (KERN_INFO "file released\n");
    return 0;
}


long myIoctl (struct file *f, unsigned int num, unsigned long num1){
    printk (KERN_INFO "trig "); 
//    ledtrig_cpu (CPU_LED_STOP);
//    led_trigger_event (trig_led, LED_FULL);
    led_trig_ide_activity ();
    return 0;
}

static int __init myInit ( void )
{
    int ret = -ENODEV;
    int status;
    printk (KERN_INFO "Init char dev\n");

    status = alloc_chrdev_region ( &mydev, FIRST_MINOR, NR_DEVS, devname );

    if ( status < 0 ) {
        printk (KERN_NOTICE "failed : %d\n", status);
        goto err;
    }

    printk ( KERN_INFO "Major no. is %d\n",MAJOR ( mydev ));
    my_cdev = cdev_alloc ();

    if ( my_cdev == NULL ) {
        printk (KERN_ERR "cdev failed\n");
        goto err_cdev_alloc;
    }

    cdev_init ( my_cdev, &fops );
    my_cdev->owner = THIS_MODULE;
    status = cdev_add ( my_cdev, mydev, NR_DEVS );
    if ( status ) {
        printk (KERN_ERR "cdev_add failed\n");
        goto err_cdev_add;
    }

    mychar_class = class_create (THIS_MODULE, devname );
    if ( IS_ERR ( mychar_class )) {
        printk ( KERN_ERR "class_creat failes\n");
        goto err_class_create;
    }

    mychar_device = device_create ( mychar_class, NULL, mydev, NULL, devname);

    if ( IS_ERR( mychar_device)) {
        printk (KERN_ERR "device_create () failed\n");
        goto err_device_create;
    }
    return 0;
err_device_create:
    class_destroy ( mychar_class );
err_class_create:
    cdev_del ( my_cdev );
err_cdev_add:
    kfree ( my_cdev);
err_cdev_alloc:
    unregister_chrdev_region ( mydev, NR_DEVS );
err:
    return ret;
}


static void myExit ( void )
{
    printk (KERN_INFO "exiting the char device\n");
    device_destroy ( mychar_class, mydev );
    class_destroy ( mychar_class );
    cdev_del ( my_cdev );
    unregister_chrdev_region ( mydev, NR_DEVS );
    return ;
}

module_init (myInit);
module_exit (myExit);

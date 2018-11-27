#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <asm/highmem.h>
#include <asm/pgtable.h>
#include <asm/pgtable_32.h>
#include <linux/mm.h>
#include <asm/current.h>
MODULE_LICENSE ("Dual BSD/GPL");
#define FIRST_MINOR 0
#define NR_DEVS 1
int myOpen(struct inode *inode, struct file *filep );
int myRelease(struct inode *in, struct file *fp );
long myIoctl(struct file *f,unsigned int num, unsigned long num1);
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
    printk (KERN_INFO "Open success\n");
    return 0;
}

int myRelease ( struct inode *in, struct file *fp )
{
    printk (KERN_INFO "file released\n");
    return 0;
}


long myIoctl(struct file *f,unsigned int num, unsigned long num1){
    struct task_struct *myTask = current;
    printk ("pid:%d\n",myTask->pid);
    printk ("pgd:%.8x\n",(myTask->mm->pgd));
    printk ("num:%.8x\n",num1);
    printk ("size of pgd_t %d \n",sizeof(pgd_t));
    printk ("size of pgd_t %d \n",sizeof(pgd_t ));
    /*pgd_t *abc;
    unsigned long *ptr;
    unsigned long *val;
    printk ("10f %p \n",(num1 & 0xffc00000));
    printk ("10 %p \n",((num1/4096)%1024));
    printk ("12 %p \n",((num1%4096)));
    abc = myTask->mm->pgd;
    printk ("pgd base:%.8p\n",abc);
    //ptr = (unsigned long *)myTask->mm->pgd;
    val = abc + ((num1)>>22);
    printk ("pgd base:%.8p\n",ptr);
    printk ("pgd entry(v):%.8p\n",val);
    printk ("pgd entry (p):%.8p\n",*val);
    *val = (*val)>>12;
    printk ("*val:%.8p\n",*val);
    ptr = kmap(pfn_to_page(*val));
    printk ("pt base (v):%.8p\n",ptr);
    val = ptr + (((num1/4096)%1024)/4);
    printk ("pt entry (v):%.8p\n",val);
    printk ("pt entry (p):%.8p\n",*val);
    *val = (*val)>>12;
    ptr = kmap(pfn_to_page(*val));
    printk ("p base (v):%.8p\n",ptr);
    val = ptr + ((num1%4096)/4);
    printk ("p entry (v):%.8p\n",val);
    printk ("p entry (p):%.8p\n",*val);
    //ptr = kmap(pfn_to_page(*val));
    ptr = *val;
    *ptr = 23;
    printk("val=%d\n",*ptr);



    */unsigned long *a;
    unsigned long pta;
    printk("num1 %.8lx\n",num1);   
    pgd_t *pgb1 = myTask->mm->pgd;
    printk("pgb %.8lx\n",pgb1);   
    unsigned int *pgd = (((unsigned long)(pgb1))+((num1>>22)<<2));
    printk("pgd %.8lx\n",pgd );   
    pta = (((unsigned long )(*pgd)) >> 12);
    printk("pta %.8lx\n",pta );   
    pte_t *ptb = kmap(pfn_to_page(pta));
    printk ("ptb %.8lx\n",ptb);
    printk ("*ptb %.8lx\n",*ptb);
    a = ( ptb + ((num1<<10)>>22));
    pta = (unsigned long)*a;
    void * ptc = kmap(pfn_to_page(pta>>12));
    printk ("ptc %.8lx\n",ptc);
    int * b = (int *)(ptc + ((num1<<20)>>20));
    //unsigned long *pa = (unsigned long *)(*ptb + po);
    //printk("po %.8lx\n",po);   
    //printk ("pa %.8lx\n",pa);

    *b = 333;


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

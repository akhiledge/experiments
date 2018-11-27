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
#include <linux/pagemap.h>
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
    int j;
    struct task_struct *myTask = current;
    struct vm_area_struct *myMmaps = myTask->mm->mmap;
    void *slot_adr = NULL;
    //unsigned int offs;
    printk (KERN_INFO "pid : %d\n", myTask->pid);
    printk (KERN_INFO "state : %ld\n", myTask->state);
    printk (KERN_INFO "parent : %d\n", myTask->parent->pid);
    struct file *myFile = myMmaps->vm_file;
    printk ("address spacef %x\n",myFile->f_mapping);
    printk ("f pages %u\n",myFile->f_mapping->nrpages);
//    printk ("f tree height %u\n",myFile->f_mapping->page_tree.height);
    printk ("tree node %x\n",myFile->f_mapping->page_tree.rnode);
    for(j = 0;j < 1024;j++){
        slot_adr = myFile->f_mapping->page_tree.rnode->slots[j];
        if(slot_adr)
            break;
    }
    printk ("tree node slot 0  %x\n",((unsigned long *)slot_adr));
//    printk ("tree node slot 0  %x\n",*((unsigned long *)slot_adr));
//    printk ("f pages %u\n",myFile->f_mapping->nrpages);
//    printk ("sb %s\n",myFile->f_mapping->host->i_sb->s_uuid);
//    printk ("sb magic %x\n",myFile->f_mapping->host->i_sb->s_magic);
    //printk ("offset  %x\n",myMmaps->vm_next->vm_pgoff);
    struct page *myPage = find_get_page(myFile->f_mapping,((pgoff_t) (num1>>22)));
    printk ("t %x\n",myPage);
    printk ("t %x\n",*myPage);
    void *pageAddr = kmap(myPage);
    *((int *)pageAddr) = 11;
    pgd_t *pgb = 0x00000000;
    unsigned long a = 0x00000010;
    printk("\na+pgb = %x\n",(unsigned int)(pgb + a));

/*    printk ("%-8s-%-8s\n","vm_start","vm_end");

    while(myMmaps){
        printk ("%.8lx-%.8lx ", myMmaps->vm_start,myMmaps->vm_end);
        printk (" %c", (((myMmaps->vm_flags)&(0x0000000f))>0x0)?'r':'-');
        printk ("%c", (((myMmaps->vm_flags)&(0x0000000f))==0x3)?'w':'-');
        printk ("%c", (((myMmaps->vm_flags)&(0x0000000f))==0x5)?'x':'-');
        printk ("%c", ((unsigned long)(myMmaps->vm_page_prot.pgprot)==37)?'p':'-');
        offs = ((myMmaps->vm_pgoff)<<12);
        if(0x0 == (offs - (myMmaps->vm_start))){
            printk (" %.8x ",(offs - (myMmaps->vm_start)));
        }
        else{
            printk (" %.8x ",(offs!=0xbffde000)?offs:0x0);
        }
        struct file *myFile = myMmaps->vm_file;
        printk (" %p ", myMmaps->vm_file);
        if(((myFile))!= NULL){
            printk (" %d ", myFile->f_inode->i_ino);
        }
        printk ("\n");
        myMmaps = myMmaps->vm_next;
    }*/

        printk ("\n");
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
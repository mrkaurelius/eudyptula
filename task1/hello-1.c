#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_AUTHOR("Abdulhamit Kumru");
MODULE_LICENSE("GPL");

/*
 * hello−1.c − The simplest kernel module.
*/

int init_module(void)
{
    printk(KERN_DEBUG "Merhaba zalim dunya 1.\n");
    /*
    * A non 0 return means init_module failed; module can't be loaded.
    */
    return 0;
}

void cleanup_module(void)
{
    printk(KERN_DEBUG "Elveda zalim dunya 1.\n");
}
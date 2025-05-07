#include <linux/module.h> // needed to load module into Kernel
//#include <linux/init.h> // macros like __init
#include <linux/kernel.h> // contains types and macros for the kernel

// int return type to see if it ran successfully (return 0)
static int __init init_hello(void) // use static to avoid naming collosions 
{   // __init tells to free function memory after use  
    printk(KERN_INFO "Hi Bro\n");  // printk because running in kernel mode (no glibc )
                 // printk logs messages to kernel log buffer (can check with dmesg)
    return 0; 
}

static void __exit cleanup_hello(void) // called when module is removed from kernel 
{                               // releases all resources/memory allcoated and "undoes" stuff set up
    printk(KERN_INFO "Bye Bro\n"); 
}

module_init(init_hello); // define entry point for kernel 
module_exit(cleanup_hello); // define exit point 

MODULE_LICENSE("GPL"); 

MODULE_AUTHOR("Minty"); // additional data
MODULE_DESCRIPTION("Prints out simple messages");
MODULE_VERSION("0.1"); 

// KERN_INFO -> log-level macro 

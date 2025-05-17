#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kprobes.h>
#include <linux/init.h>
#include <linux/syscalls.h>
#include <linux/ptrace.h>

// Module Metadata
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nabil");
MODULE_DESCRIPTION("Tracks system call counts using Kprobes");


#define MAX_SYSCALL_NR 450

static unsigned long syscall_counter[MAX_SYSCALL_NR] = {0}; // max number  // max number   
static unsigned long total_syscalls = 0; // counter 


static struct kprobe kp;

static int handler_pre(struct kprobe *p, struct pt_regs *regs)
{
    unsigned long syscall_nr = regs->orig_ax;  // x86_64: syscall number is in orig_ax

    if (syscall_nr < MAX_SYSCALL_NR) { // statement to count syscalls 
        syscall_counter[syscall_nr]++;
        total_syscalls++;
    }

    return 0;
}

       
static int __init syscall_tracker_init(void)
{
    kp.symbol_name = "do_syscall_64";  // Entry point for syscalls on x86_64
    kp.pre_handler = handler_pre;

    if (register_kprobe(&kp) < 0) {
        pr_err("Failed to register kprobe\n");
        return -1;
    }

    pr_info("Syscall tracker module loaded\n");
    return 0;
}

static void __exit syscall_tracker_exit(void)
{
    unregister_kprobe(&kp);
    pr_info("Syscall tracker module unloaded\n");
    pr_info("Total syscalls tracked: %lu\n", total_syscalls);
}

// declare Entry and exit point 
module_init(syscall_tracker_init);
module_exit(syscall_tracker_exit);


                      

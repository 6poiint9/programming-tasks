#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kprobes.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

#define MAX_SYSCALLS 6900

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nabil");
MODULE_DESCRIPTION("Track read, write, open, close, mkdir syscalls using kprobes");
MODULE_VERSION("2.0");

static unsigned int read_count = 0;
static unsigned int write_count = 0;
static unsigned int open_count = 0;
static unsigned int close_count = 0;
static unsigned int mkdir_count = 0;

// Procfs entry
static struct proc_dir_entry *proc_entry;

// Kprobes
static struct kprobe read_kp = { .symbol_name = "__x64_sys_read" };
static struct kprobe write_kp = { .symbol_name = "__x64_sys_write" };
static struct kprobe open_kp = { .symbol_name = "__x64_sys_openat" };
static struct kprobe close_kp = { .symbol_name = "__x64_sys_close" };
static struct kprobe mkdir_kp = { .symbol_name = "__x64_sys_mkdir" };

// Handlers
static int handler_pre_read(struct kprobe *p, struct pt_regs *regs) {
    if (read_count < MAX_SYSCALLS) read_count++;
    return 0;
}

static int handler_pre_write(struct kprobe *p, struct pt_regs *regs) {
    if (write_count < MAX_SYSCALLS) write_count++;
    return 0;
}

static int handler_pre_open(struct kprobe *p, struct pt_regs *regs) {
    if (open_count < MAX_SYSCALLS) open_count++;
    return 0;
}

static int handler_pre_close(struct kprobe *p, struct pt_regs *regs) {
    if (close_count < MAX_SYSCALLS) close_count++;
    return 0;
}

static int handler_pre_mkdir(struct kprobe *p, struct pt_regs *regs) {
    if (mkdir_count < MAX_SYSCALLS) mkdir_count++;
    return 0;
}

// Procfs output
static int syscall_tracker_show(struct seq_file *m, void *v)
{
    seq_printf(m, "Tracked read() syscalls: %u\n", read_count);
    seq_printf(m, "Tracked write() syscalls: %u\n", write_count);
    seq_printf(m, "Tracked open() syscalls: %u\n", open_count);
    seq_printf(m, "Tracked close() syscalls: %u\n", close_count);
    seq_printf(m, "Tracked mkdir() syscalls: %u\n", mkdir_count);
    return 0;
}

static int syscall_tracker_open_proc(struct inode *inode, struct file *file)
{
    return single_open(file, syscall_tracker_show, NULL);
}

static const struct proc_ops proc_fops = {
    .proc_open    = syscall_tracker_open_proc,
    .proc_read    = seq_read,
    .proc_release = single_release,
};

// Init
static int __init syscall_tracker_init(void)
{
    int ret;

    // Assign handlers
    read_kp.pre_handler = handler_pre_read;
    write_kp.pre_handler = handler_pre_write;
    open_kp.pre_handler = handler_pre_open;
    close_kp.pre_handler = handler_pre_close;
    mkdir_kp.pre_handler = handler_pre_mkdir;

    // Register all kprobes
    if ((ret = register_kprobe(&read_kp)) < 0) goto fail;
    if ((ret = register_kprobe(&write_kp)) < 0) goto fail_unregister_read;
    if ((ret = register_kprobe(&open_kp)) < 0) goto fail_unregister_write;
    if ((ret = register_kprobe(&close_kp)) < 0) goto fail_unregister_open;
    if ((ret = register_kprobe(&mkdir_kp)) < 0) goto fail_unregister_close;

    // Create proc entry
    proc_entry = proc_create("syscall_tracker", 0, NULL, &proc_fops);
    if (!proc_entry) {
        ret = -ENOMEM;
        goto fail_unregister_mkdir;
    }

    printk(KERN_INFO "Syscall tracker module loaded.\n");
    return 0;

fail_unregister_mkdir:
    unregister_kprobe(&mkdir_kp);
fail_unregister_close:
    unregister_kprobe(&close_kp);
fail_unregister_open:
    unregister_kprobe(&open_kp);
fail_unregister_write:
    unregister_kprobe(&write_kp);
fail_unregister_read:
    unregister_kprobe(&read_kp);
fail:
    return ret;
}

// Exit
static void __exit syscall_tracker_exit(void)
{
    proc_remove(proc_entry);
    unregister_kprobe(&mkdir_kp);
    unregister_kprobe(&close_kp);
    unregister_kprobe(&open_kp);
    unregister_kprobe(&write_kp);
    unregister_kprobe(&read_kp);
    
    printk(KERN_INFO "Syscall tracker module unloaded.\n");
    printk(KERN_INFO "=== Syscall Tracker Summary ===\n");
    printk(KERN_INFO "read()  calls: %u\n", read_count);
    printk(KERN_INFO "write() calls: %u\n", write_count);
    printk(KERN_INFO "open()  calls: %u\n", open_count);
    printk(KERN_INFO "close() calls: %u\n", close_count);
    printk(KERN_INFO "mkdir() calls: %u\n", mkdir_count);
}

module_init(syscall_tracker_init);
module_exit(syscall_tracker_exit);


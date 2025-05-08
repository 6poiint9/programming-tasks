#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x37383664, "proc_remove" },
	{ 0xee43d22c, "seq_read" },
	{ 0x49847770, "single_release" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x3f66a26e, "register_kprobe" },
	{ 0xc4a68fc7, "proc_create" },
	{ 0xbb10e61d, "unregister_kprobe" },
	{ 0x92997ed8, "_printk" },
	{ 0x54e74828, "single_open" },
	{ 0xcc0b7adf, "seq_printf" },
	{ 0x9a3c56a9, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1308F31F5BD35579F52D46B");

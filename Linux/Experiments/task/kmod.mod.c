#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x7ccad388, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x590de2b9, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0x76d9e68b, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xc5c09f01, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x61e83c2f, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x13aa9921, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x973a476e, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x58d0ec0d, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0xe7354bb3, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x454ae74d, __VMLINUX_SYMBOL_STR(cdev_alloc) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0xd5d0f65, __VMLINUX_SYMBOL_STR(kmap) },
	{ 0x5b14156c, __VMLINUX_SYMBOL_STR(pagecache_get_page) },
	{ 0xc1dbeece, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "53F5A62927DD650C161DDDF");

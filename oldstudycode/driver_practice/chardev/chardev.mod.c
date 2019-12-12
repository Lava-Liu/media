#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x15b2dc7b, "module_layout" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0xe99ab841, "cdev_del" },
	{ 0x37a0cba, "kfree" },
	{ 0x593e116f, "class_destroy" },
	{ 0x22c03af0, "device_destroy" },
	{ 0xec2b40ad, "device_create" },
	{ 0x942cfb07, "__class_create" },
	{ 0x86a4889a, "kmalloc_order_trace" },
	{ 0x29537c9e, "alloc_chrdev_region" },
	{ 0xd8e484f0, "register_chrdev_region" },
	{ 0x60ac4203, "cdev_add" },
	{ 0x3d3774b, "cdev_init" },
	{ 0x50eedeb8, "printk" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "7665E3FDABB2AF01BEC3835");

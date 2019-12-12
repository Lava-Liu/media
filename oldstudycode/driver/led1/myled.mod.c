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
	{ 0x35b6b772, "param_ops_charp" },
	{ 0x15692c87, "param_ops_int" },
	{ 0xe99ab841, "cdev_del" },
	{ 0x593e116f, "class_destroy" },
	{ 0x22c03af0, "device_destroy" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0xec2b40ad, "device_create" },
	{ 0x942cfb07, "__class_create" },
	{ 0x37a0cba, "kfree" },
	{ 0xedc03953, "iounmap" },
	{ 0x60ac4203, "cdev_add" },
	{ 0x3d3774b, "cdev_init" },
	{ 0x42c8de35, "ioremap_nocache" },
	{ 0x2c9189e, "kmem_cache_alloc_trace" },
	{ 0x68c70c2d, "kmalloc_caches" },
	{ 0x29537c9e, "alloc_chrdev_region" },
	{ 0xd8e484f0, "register_chrdev_region" },
	{ 0x436c2179, "iowrite32" },
	{ 0xe484e35f, "ioread32" },
	{ 0x50eedeb8, "printk" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "E414C828D4AEFF7BE3380A2");

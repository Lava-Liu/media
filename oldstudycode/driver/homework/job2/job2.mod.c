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
	{ 0xddd1b721, "mydivi" },
	{ 0xe7f4f8b0, "mymulti" },
	{ 0x1414bf25, "mysub" },
	{ 0xfc05b364, "myadd" },
	{ 0x3bc86350, "number1" },
	{ 0x10e53093, "number2" },
	{ 0x50eedeb8, "printk" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=job1,job3";


MODULE_INFO(srcversion, "8B335B15FB45165B4375AA8");

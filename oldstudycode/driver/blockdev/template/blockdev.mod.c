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
	{ 0xe2342298, "add_disk" },
	{ 0xe914e41e, "strcpy" },
	{ 0xe8623448, "alloc_disk" },
	{ 0xe5ee988f, "blk_queue_logical_block_size" },
	{ 0x23db365f, "blk_init_queue" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xb5a459dc, "unregister_blkdev" },
	{ 0x2c9189e, "kmem_cache_alloc_trace" },
	{ 0x68c70c2d, "kmalloc_caches" },
	{ 0x71a50dbc, "register_blkdev" },
	{ 0x9a1bd025, "__blk_end_request_cur" },
	{ 0x2e60bace, "memcpy" },
	{ 0x6d60b85d, "__blk_end_request_all" },
	{ 0xba271d9b, "blk_fetch_request" },
	{ 0x50eedeb8, "printk" },
	{ 0x76ebea8, "pv_lock_ops" },
	{ 0x67f7403e, "_raw_spin_lock" },
	{ 0x2f287f0d, "copy_to_user" },
	{ 0x2bc95bd4, "memset" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "CE1FD255CB26655FD618EC7");

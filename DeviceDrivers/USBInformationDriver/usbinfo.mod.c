#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
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
	{ 0xa83edc56, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x86264dd, __VMLINUX_SYMBOL_STR(usb_deregister) },
	{ 0x8c87a246, __VMLINUX_SYMBOL_STR(usb_register_driver) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:v0781p5567d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "865F9D94FE6574021947E37");

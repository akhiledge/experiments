
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/leds.h>

#define BLINK_DELAY 30

DEFINE_LED_TRIGGER(led_trig_ide);
static unsigned long ide_blink_delay = BLINK_DELAY;

void led_trig_ide_activity(void)
{
    led_trigger_blink_oneshot(led_trig_ide,
            &ide_blink_delay, &ide_blink_delay, 0);
}
EXPORT_SYMBOL(led_trig_ide_activity);

static int __init led_trig_ide_init(void)
{
    led_trigger_register_simple("disk", &led_trig_ide);
    return 0;
}

static void __exit led_trig_ide_exit(void)
{
    led_trigger_unregister_simple(led_trig_ide);
}

module_init(led_trig_ide_init);
module_exit(led_trig_ide_exit);

MODULE_DESCRIPTION("LED IDE Disk Activity Trigger");
MODULE_LICENSE("GPL");



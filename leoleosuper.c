#include "leoleosuper.h"
//#include "usbpd.h"
#include "ws2812.h"
#include "color.h"
#include "led.h"
#define RGBLIGHT_LED_COUNT 86


void housekeeping_task_kb(void)
{
    RGB led[RGBLIGHT_LED_COUNT] = {0};
    led_t states = host_keyboard_led_state();
    led[0].r = states.num_lock?0xFF:0;
    led[0].g = states.caps_lock?0xFF:0;
    led[0].b = states.scroll_lock?0xFF:0;
    led[1].r = 0xFF;
    led[1].g = 0xFF;
    led[1].b = 0xFF;
    ws2812_setleds(led, RGBLIGHT_LED_COUNT);
    housekeeping_task_user();
}

void keyboard_post_init_user(void){

}
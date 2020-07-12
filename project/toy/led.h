#ifndef led_included
#define led_included

#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (BIT0 | BIT6)

extern unsigned char red_on,green_on;
extern unsigned char led_changed;

void led_init();
void led_update();

#endif

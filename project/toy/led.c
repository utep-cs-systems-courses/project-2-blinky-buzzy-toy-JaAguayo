#include <msp430.h>
#include "led.h"
#include "stateMachines.h"

unsigned char red_on = 0,green_on = 0;
unsigned char led_changed = 0;
char switch2_state,switch3_state;
char switch_state_changed;

static char redVal[] = {0,LED_RED},greenVal[] = {0,LED_GREEN};

void led_init(){
  P1DIR |= LEDS;
  led_changed = 1;
  switch_state_changed = 1; 
  led_update();
}

void led_update(){
  char ledFlags;

  if (led_changed && switch_state == 1){
    ledFlags = greenVal[green_on] | redVal[red_on]; //first state for led state machine
    
    P1OUT &= (0xff^LEDS) | ledFlags;
    P1OUT |= ledFlags;
    led_changed = 0;
  }

  if (switch_state_changed && switch_state == 2){
    ledFlags |= switch2_state ? LED_GREEN : 0; //green then when pressed switch to red
    ledFlags |= switch2_state ? 0 : LED_RED;
    
    P1OUT &= (0xff^LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }
  
  if (switch_state_changed && switch_state == 3){
    ledFlags |= switch3_state ? 0 : LED_GREEN; //red and when pressed goes off

    P1OUT &= (0xff^LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }
  switch_state_changed = 0;
}

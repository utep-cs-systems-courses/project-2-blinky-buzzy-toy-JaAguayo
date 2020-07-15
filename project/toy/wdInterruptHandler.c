#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0;
  switch_state_advance();
  if (++blink_count == 10){ //made the blink faster 
    led_state_advance(); //when the led state machine is used to blink back and forth
    blink_count = 0;
  }
}

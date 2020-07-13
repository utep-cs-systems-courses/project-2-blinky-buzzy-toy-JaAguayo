#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0;
  switch_state_advance();
  if (++blink_count == 50){
    led_state_advance();
    blink_count = 0;
  }
}

#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0;

  if (++blink_count == 125){
    //led_state_advance();
    switch_state_advance();
    blink_count = 0;
  }
}

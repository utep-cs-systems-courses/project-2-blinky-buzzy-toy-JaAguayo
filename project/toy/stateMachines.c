#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

int siren[] = {230};
int twinkle[] = {523,0,0,523,392,392,440,440,392,349,349,330,330,294,294,262};
int row_row[] = {200};
int i = 0;
int j = 0;

char toggle_red(){
  static char state = 0;

  switch (state){
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;
}

char toggle_green(){
  char changed = 0;
  if (red_on){
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}

void led_state_advance(){
  char changed = 0;
  
  static enum {R=0,G=1} color = G;
  switch (color){
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }
  
  led_changed = changed;
  led_update();
}

void switch_state_advance(){
  switch (switch_state){
  case 1:
    buzzer_set_period(siren);
    break;
  case 2:
    buzzer_set_period(row_row);
    break;
  case 3:
    buzzer_set_period(twinkle);
    break;
  case 4:
    buzzer_off();
    break;
  }
  led_update();
}

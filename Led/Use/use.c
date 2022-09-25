
#include "use.h"

void led_init(void){
    DDRD |= (1<<6);
    PORTD |= (1<<6);
}

extern void setup(){
    led_init();
}

extern void loop(){
    
}
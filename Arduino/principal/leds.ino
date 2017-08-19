/* Init de los leds */

void init_leds(int led1){
   pinMode(led1,OUTPUT);
   digitalWrite(led1,0); 
}

/* Para cambiar estado de leds */

void encender_leds(int led1, int state_led1){
  digitalWrite(led1, state_led1); 
}

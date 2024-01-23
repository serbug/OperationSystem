#include "dd_relay.h"
#include "Arduino.h"

int dd_relay_state = RELAY_OFF;

void dd_realy_setup(){
    pinMode(DD_RELAY_PIN, OUTPUT);
}

void dd_relay_loop(){
    int state = dd_relay_state;
    digitalWrite(DD_RELAY_PIN, state);
}

void dd_relay_on(){
    dd_relay_state = RELAY_ON;
}

void dd_relay_off(){
    dd_relay_state = RELAY_OFF;
}

void dd_relay_set_state(int state){
    dd_relay_state = state;
}

int dd_relay_get_state(){
    int state = dd_relay_state;
    return state;
}




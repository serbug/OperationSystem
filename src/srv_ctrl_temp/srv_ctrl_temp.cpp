
#include "srv_ctrl_temp.h"
#include "dd_dht/dd_dht.h"
#include "dd_relay/dd_relay.h"


float ctrl_desird_temp = 19.0;
float ctrl_current_temp = 19.0;

void srv_ctrl_temp_setup(){
    ctrl_desird_temp = 19.0;
    ctrl_current_temp = 19.0;
}

void srv_ctrl_temp_loop(){

    if (dd_dht_GetError() == 0)
    {
        ctrl_current_temp = dd_dht_GetTemperature();
        if (ctrl_current_temp < (ctrl_desird_temp - CTRL_TEMP_HISTERESIS))
        {
            dd_relay_on();
        }else if (ctrl_current_temp > (ctrl_desird_temp + CTRL_TEMP_HISTERESIS)){
            dd_relay_off();
        }else{
            // do nothing
        }        
    }
    else
    {
        dd_relay_off();
    }

}

void srv_ctrl_set_desired_temp(float desired_temp){
    ctrl_desird_temp = desired_temp;
}

float srv_ctrl_get_desired_temp(){             //
    float temp = ctrl_desird_temp;             //
    return temp;
}

void srv_ctrl_desired_temp_up(){
    float temp = srv_ctrl_get_desired_temp();
    temp += DELTA_TEMP_UP_DOWN;
    srv_ctrl_set_desired_temp(temp);
}

void srv_ctrl_desired_temp_down(){
    float temp = srv_ctrl_get_desired_temp();
    temp -= DELTA_TEMP_UP_DOWN;
    srv_ctrl_set_desired_temp(temp);
}

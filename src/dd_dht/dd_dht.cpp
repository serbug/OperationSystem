
#include "dd_dht.h"

#include <Adafruit_Sensor.h>
#include "DHT.h"

#define DHTPIN 2 
#define DHTTYPE DHT22 // DHT 22

DHT dht(DHTPIN, DHTTYPE);

void dd_dht_setup()
{
    dht.begin();
}

float dd_dht_temperature = 0;

float dd_dht_GetTemperature()
{
    return dd_dht_temperature;
}
int dd_dht_error = 0;

int dd_dht_GetError()
{
    return dd_dht_error;
}

void dd_dht_loop()
{
    float h = dht.readHumidity();
   
    float t = dht.readTemperature();
    
    dd_dht_temperature = t;

  
    float f = dht.readTemperature(true);


    if (isnan(h) || isnan(t) || isnan(f))
    {
        dd_dht_error = 1;
        return;
    }

    dd_dht_error = 0;


}




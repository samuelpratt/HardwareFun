#include <Wire.h>
#include "BlueDot_BME280.h"

//BME280 Library is here: https://github.com/BlueDot-Arduino/BlueDot_BME280

BlueDot_BME280 bme1;
int bme1Detected = 0; 


void setup() {
  Serial.begin(9600);
  Serial.println("Starting Setup");
  bme1.parameter.communication = 0;
  bme1.parameter.I2CAddress = 0x77;
  bme1.parameter.sensorMode = 0b11; 
  bme1.parameter.IIRfilter = 0b100;
  bme1.parameter.humidOversampling = 0b101;
  bme1.parameter.tempOversampling = 0b101;
  bme1.parameter.pressOversampling = 0b101; 
  bme1.parameter.pressureSeaLevel = 1013.25;
  bme1.parameter.tempOutsideCelsius = 15;
  bme1.parameter.tempOutsideFahrenheit = 59;

  if (bme1.init() == 0x60)
  {
    Serial.println(F("First BME280 Sensor found"));
    bme1Detected = 1;
  }
  else
  {    
    Serial.println(F("Ops! BME280 Sensor not found!"));
    bme1Detected = 0;
  }
  

}

void loop() {
  Serial.println("Starting Loop");
  if (bme1Detected)
  {
    Serial.print(F("Temperature Sensor 1 [°C]:\t\t")); 
    Serial.println(bme1.readTempC());
    Serial.print(F("Temperature Sensor 1 [°F]:\t\t"));            
    Serial.println(bme1.readTempF());
    Serial.print(F("Humidity Sensor 1 [%]:\t\t\t")); 
    Serial.println(bme1.readHumidity());
    Serial.print(F("Pressure Sensor 1 [hPa]:\t\t")); 
    Serial.println(bme1.readPressure());    
  }
  delay(10000);

}

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define TEMP_PIN 0;
#define THERMISTOR_OHMS 10000;

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
}

float calcTempInC(int voltage, int resistance) {

  int Vo = voltage;
  float R1 = (float)resistance; 
  float logR2, R2, Tk, Tc;
  float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

  
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  Tk = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = Tk - 273.15;

  return Tc;
}

void writeTempToSerial(float temp) {
  Serial.print("Temperature: "); 
  Serial.print(temp);
  Serial.println(" C");   
}

int readVoltage(int pin) {
  int result = 0;
  result = analogRead(pin);
  return result;
}

void writeTempToLcd(float temp) {
    String outPut;
    outPut = (String)temp + " C";
    
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Temperature:");
    lcd.setCursor(1,1);
    lcd.print(outPut);

}


void loop()
{
  int resistance = THERMISTOR_OHMS;
  int thermistorPin = TEMP_PIN;
  int voltage;
  float temp;
   
  voltage = readVoltage(thermistorPin);
  temp = calcTempInC(voltage, resistance);
  writeTempToLcd(temp);

  delay(5000);
}

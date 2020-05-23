#include <Arduino.h>
#include <SPI.h>
#include <U8x8lib.h>

/* Constructor */
U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE);

/* u8x8.begin() is required and will sent the setup/init sequence to the display */
void setup(void)
{
  u8x8.begin();
}

void loop(void)
{
  u8x8.setFont(u8x8_font_px437wyse700a_2x2_r);
  u8x8.drawString(0,0,"T:21.2C");
  u8x8.drawString(0,2,"H:56.1%");
  u8x8.drawString(0,4,"P:1023.3");
  u8x8.drawString(0,6,"OK");

  
  
  delay(1000);
}

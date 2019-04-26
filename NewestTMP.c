#include <SPI.h>
#include <Arduino.h>
#include <Wire.h>
#include <ArdusatSDK.h>

ArdusatSerial serialConnection(SERIAL_MODE_HARDWARE_AND_SOFTWARE, 8, 9);

Luminosity lum;
TemperatureMLX temp;

Display display;

void setup(void)
{
  serialConnection.begin(9600);
// turns on temp meter 
  lum.begin();
  temp.begin();
  //turns on oled
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
  serialConnection.println("");
}

void loop(void)
{
  //shows things on serial
  serialConnection.println(temp.readToJSON("infraredTemp"));
  serialConnection.println(lum.readToJSON("luminosity"));
  

 if (temp.t > 50) {  
 
  display.clearDisplay();
 
  display.drawRect(14, 4, 15, 11, WHITE);
  display.drawLine(11,9,19,13, WHITE);
  display.drawLine(19,13,31,0, WHITE);
 
  display.display();
 }
// else{}
  delay(200);
}

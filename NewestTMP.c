

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
//turns on temp and luminosity meter
  lum.begin();
  temp.begin();
  //turns on oled
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
  serialConnection.println("");
}

void loop(void)
{
  //serial monitor for debugging 
  serialConnection.println(temp.readToJSON("infraredTemp"));
  serialConnection.println(lum.readToJSON("luminosity"));
  
//triggers when tmp>60 and displays check mark on oled 
 if (temp.t > 60) {  
  display.clearDisplay();
 
  display.drawRect(14, 4, 15, 11, WHITE);
  display.drawLine(11,9,19,13, WHITE);
  display.drawLine(19,13,31,0, WHITE);
 
  display.display();
 }
 //else theres no check mark
 else{
  display.clearDisplay();
 
  display.drawRect(14, 4, 15, 11, WHITE);
  display.display();
 }
  delay(200);
}

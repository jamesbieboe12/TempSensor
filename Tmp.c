#include <Arduino.h>
#include <Wire.h>
#include <ArdusatSDK.h>

ArdusatSerial serialConnection(SERIAL_MODE_HARDWARE_AND_SOFTWARE, 8, 9);

Luminosity lum;
TemperatureMLX temp;

void setup(void)
{
  serialConnection.begin(9600);

  lum.begin();
  temp.begin();

  serialConnection.println("");
}

void loop(void)
{
  serialConnection.println(temp.readToJSON("infraredTemp"));
  serialConnection.println(lum.readToJSON("luminosity"));

 if (temp.t > 15) {  
  display.drawPixel(2, 5, WHITE);
  display.drawPixel(3, 6, WHITE);
  display.drawPixel(4, 7, WHITE);
  display.drawPixel(5, 7, WHITE);
  display.drawPixel(6, 7, WHITE);
  display.drawPixel(7, 7, WHITE);
  display.drawPixel(8, 7, WHITE);
  display.display();
 }
// else{}
  delay(200);
}

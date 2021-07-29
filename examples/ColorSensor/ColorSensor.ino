/*
  APDS-9960 - Color Sensor

  This example reads color data from the on-board APDS-9960 sensor of the and prints the color RGB (red, green, blue)
  values to the Serial Monitor once a second.

  This example code is in the public domain.

  Modified by soldered.com for https://solde.red/333047
*/

#include "APDS9960-SOLDERED.h"

APDS_9960 APDS;

void setup()
{
    Serial.begin(115200);
    while (!Serial)
        ;

    if (!APDS.begin())
    {
        Serial.println("Error initializing APDS-9960 sensor.");
    }
}

void loop()
{
    // check if a color reading is available
    while (!APDS.colorAvailable())
    {
        delay(5);
    }
    int r, g, b;

    // read the color
    APDS.readColor(r, g, b);

    // print the values
    Serial.print("r = ");
    Serial.println(r);
    Serial.print("g = ");
    Serial.println(g);
    Serial.print("b = ");
    Serial.println(b);
    Serial.println();

    // wait a bit before reading again
    delay(1000);
}

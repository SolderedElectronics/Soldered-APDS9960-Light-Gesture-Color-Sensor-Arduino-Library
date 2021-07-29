/*
  APDS-9960 - Proximity Sensor

  This example reads proximity data from the on-board APDS-9960 sensor of the
  Nano 33 BLE Sense and prints the proximity value to the Serial Monitor
  every 100 ms.

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
        Serial.println("Error initializing APDS-9960 sensor!");
    }
}

void loop()
{
    // check if a proximity reading is available
    if (APDS.proximityAvailable())
    {
        // read the proximity
        // - 0   => close
        // - 255 => far
        // - -1  => error
        int proximity = APDS.readProximity();

        // print value to the Serial Monitor
        Serial.println(proximity);
    }

    // wait a bit before reading again
    delay(100);
}

/**
 **************************************************
 *
 * @file        get_voltage.ino
 * @brief       This example sets desired voltage on DACs output and then reads set voltage from DAC and prints it on
 *serial. monitor. You can use a voltmeter to measure volttage on DACs output.
 *
 * Product: solde.red/333052
 *
 *
 * @authors     Borna Biro @ soldered.com
 ***************************************************/

#include "MCP47A1-SOLDERED.h" // Include Soldered library for MCP47A1 DAC.

MCP47A1_SOLDERED dac; // Create object for DAC library.

void setup()
{
    Serial.begin(115200); // Initialize serial communication at 115200 bauds.
    dac.begin();          // Initialize DACs library.
}

void loop()
{
    float volts;

    // Set DAC output voltage to 0 V and read it back.
    dac.setVoltage(0);
    printVoltage(dac.getVoltage());
    delay(2000);

    // Set DAC output voltage to 1 V and read it back.
    dac.setVoltage(1);
    printVoltage(dac.getVoltage());
    delay(2000);

    // Set DAC output voltage to 2.5 V and read it back.
    dac.setVoltage(2.5);
    printVoltage(dac.getVoltage());
    delay(2000);

    // Set DAC output voltage to 3.3 V and read it back.
    dac.setVoltage(3.3);
    printVoltage(dac.getVoltage());
    delay(2000);
}

// Function prints set voltage on Serial Monitor.
void printVoltage(float _v)
{
    Serial.print("DAC output: ");
    Serial.print(_v, 2);
    Serial.println('V');
}
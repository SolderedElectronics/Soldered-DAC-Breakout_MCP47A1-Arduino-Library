/**
 **************************************************
 *
 * @file        set_voltage.ino
 * @brief       This example shows how to set voltage at DACs output. You can measure voltage that you set with a
 *voltmeter at DACs output. It will cycle between four voltages: 0V, 1V, 2.5V and 3.3V.
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

    // Set DAC output voltage to 0 V
    volts = 0;
    dac.setVoltage(volts);
    printVoltage(volts);
    delay(2000);

    // Set DAC output voltage to 1 V
    volts = 1;
    dac.setVoltage(volts);
    printVoltage(volts);
    delay(2000);

    // Set DAC output voltage to 2.5 V
    volts = 2.5;
    dac.setVoltage(volts);
    printVoltage(volts);
    delay(2000);

    // Set DAC output voltage to 3.3 V
    volts = 3.3;
    dac.setVoltage(volts);
    printVoltage(volts);
    delay(2000);
}

// Function prints set voltage on Serial Monitor.
void printVoltage(float _v)
{
    Serial.print("DAC output: ");
    Serial.print(_v, 2);
    Serial.println('V');
}
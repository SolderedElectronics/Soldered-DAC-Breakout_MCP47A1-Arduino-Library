/**
 **************************************************
 *
 * @file        waveform_generator.ino
 * @brief       This example shows how to generate simple wavefroms like sinewave, triangle wave and sawtooth wave. You
 *will need 330 Ohm resistor and LED. Connect LED and resistor at the output of a DAC. You can alternatively use
 *oscilloscope or small speaker.
 *
 * Product: solde.red/333052
 *
 *
 * @authors     Borna Biro @ soldered.com
 ***************************************************/

#include "MCP47A1-SOLDERED.h" // Include Soldered library for MCP47A1 DAC.


MCP47A1_SOLDERED dac;    // Create object for DAC library.
uint8_t waveformLUT[65]; // Array for storing samples of desired waveform.

int delay_ms = 100;       // Delay between samples.
int selectedWaveform = 0; // 0 for sinewave, 1 for triangle wave, 2 for sawtooth wave.

void setup()
{
    dac.begin();               // Initialize DACs library.
    makeLut(selectedWaveform); // Fill LUT (look up table) with values for each waveform.
}

int k = 0; // Counter varable for selevting samples from LUT.
void loop()
{
    dac.setByte(waveformLUT[k]); // Send waveform samples stored in LUT one by one to DAC.
    k++;
    if (k > 64)
        k = 0;
    delay(delay_ms); // Wait a little bit between samples. Smaller delay, higher frequency of the generated signal.
}

// Function calculates values for each sample of each waveform and puts that values into LUT.
void makeLut(int _waveform)
{
    int dir = 2;
    uint8_t n = 0;
    switch (_waveform)
    {
    case 0: // Sinewave
        for (int i = 0; i < 65; i++)
        {
            waveformLUT[i] = 32 * sin(2.0 * PI * i / (sizeof(waveformLUT) / sizeof(uint8_t))) + 32;
        }
        break;

    case 1: // Triangle wave
        for (int i = 0; i < 65; i++)
        {
            if (i == 32)
                dir = -2;
            n += dir;
            waveformLUT[i] = n;
        }
        break;

    case 2: // Sawtooth wave
        for (int i = 0; i < 65; i++)
        {
            waveformLUT[i] = i;
        }
        break;
    }
}
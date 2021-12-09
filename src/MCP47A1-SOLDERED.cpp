/**
 **************************************************
 *
 * @file        MCP47A1-SOLDERED.cpp
 * @brief       Source file for MCP47A1 DAC code.
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors    Borna Biro @ soldered.com
 ***************************************************/


#include "MCP47A1-SOLDERED.h"

/**
 * @brief                   MCP47A1 Library constructor.
 */
MCP47A1_SOLDERED::MCP47A1_SOLDERED()
{
    native = 1;
}

/**
 * @brief                   Initializer function for MCP47A1 DAC library. Sets up I2C address and inits I2C
 * communication.
 */
void MCP47A1_SOLDERED::initializeNative()
{
    address = MCP47A1_I2C_ADDRESS >> 1;
    Wire.begin();
}

/**
 * @brief                   Set supply voltage of DAC (needed for calculation).
 *
 * @param float _vcc        Supply voltage of DAC (in range from 1.8V to 5.5V).
 *
 * @note                    Use if only if you are VCC pin instead of easyC connector. Default value is 3.3V (easyC
 * voltage).
 */
void MCP47A1_SOLDERED::dacVcc(float _vcc)
{
    if ((_vcc > 5 || _vcc < 1.8))
        return;
    _dacSupply = _vcc;
}

/**
 * @brief                   Set voltage at DACs output.
 *
 * @param float _volts      Voltage at DACs output in range from 0V to VCC.
 */
void MCP47A1_SOLDERED::setVoltage(float _volts)
{
    if ((_volts > _dacSupply) || (_volts < 0))
        return;
    char _byte = _volts / _dacSupply * 64;
    setByte(_byte);
}

/**
 * @brief                   Set voltage at with digital word (byte).
 *
 * @param float _volts      DAC digital word (byte) in range from 0 to 64.
 */
void MCP47A1_SOLDERED::setByte(uint8_t _byte)
{
    if (_byte > 64)
        return;
    const uint8_t _reg[2]{0, _byte};
    sendData(_reg, 2);
}

/**
 * @brief                   Get digital word from DAC (byte) that represents output voltage.
 *
 * @return                  Digital word in range from 0 (0V) to 64 (VCC).
 */
uint8_t MCP47A1_SOLDERED::getByte()
{
    char _reg = 0;
    sendAddress(_reg);
    readData(&_reg, 1);
    return _reg;
}

/**
 * @brief                   Get currently set voltage at the DACs output.
 *
 * @return                  Voltage at DACs output.
 */
float MCP47A1_SOLDERED::getVoltage()
{
    char _byte = getByte();
    return (_byte / 64.0 * _dacSupply);
}
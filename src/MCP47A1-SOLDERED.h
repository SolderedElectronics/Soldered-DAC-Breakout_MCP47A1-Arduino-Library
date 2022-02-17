/**
 **************************************************
 *
 * @file        MCP47A1-SOLDERED.h
 * @brief       Header file for MCP47A1 DAC code.
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     Borna Biro @ soldered.com
 ***************************************************/

#ifndef __MCP47A1_SOLDERED__
#define __MCP47A1_SOLDERED__

#include "Arduino.h"
#include "libs/Generic-easyC/easyC.hpp"

#define MCP47A1_I2C_ADDRESS 0x5C

class MCP47A1_SOLDERED : public EasyC
{
  public:
    MCP47A1_SOLDERED();
    void dacVcc(float _vcc);
    void setVoltage(float _volts);
    void setByte(uint8_t _byte);
    uint8_t getByte();
    float getVoltage();

  protected:
    void initializeNative();

  private:
    float _dacSupply = 3.3;
};

#endif

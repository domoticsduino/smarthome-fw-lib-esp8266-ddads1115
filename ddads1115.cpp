/* 1.0.0 VERSION */

#include "ddads1115.h"
#include "ddcommon.h"

DDADS1115::DDADS1115(uint8_t gain = (uint8_t)0U){
    this->_gain = gain;
    Wire.begin();
    if(!ADS.begin())
        writeToSerial("ADS not connected", true);
    else
        writeToSerial("ADS connected", false);
}

DDADS1115Val DDADS1115::getValues(){
    DDADS1115Val ret;
    ADS.setGain(this->_gain);
    float f = ADS.toVoltage(1); 
    ret.anag1 = ADS.readADC(0);
    ret.anag2 = ADS.readADC(1);
    ret.anag3 = ADS.readADC(2);
    ret.anag4 = ADS.readADC(3);
    ret.volt1 = ret.anag1 * f;
    ret.volt2 = ret.anag2 * f;
    ret.volt3 = ret.anag3 * f;
    ret.volt4 = ret.anag4 * f;
    writeToSerial("F: ", false);writeToSerial(f * 1000.0, true);
    writeToSerial("A0: ", false);writeToSerial(ret.anag1, false);
    writeToSerial(" A1: ", false);writeToSerial(ret.anag2, false);
    writeToSerial(" A2: ", false);writeToSerial(ret.anag3, false);
    writeToSerial(" A3: ", false);writeToSerial(ret.anag4, true);
    writeToSerial("V0: ", false);writeToSerial(ret.volt1, false);
    writeToSerial(" V1: ", false);writeToSerial(ret.volt2, false);
    writeToSerial(" V2: ", false);writeToSerial(ret.volt3, false);
    writeToSerial(" V3: ", false);writeToSerial(ret.volt4, true);
    return ret;
}

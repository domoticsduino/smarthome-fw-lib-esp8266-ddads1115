/* 1.0.0 VERSION */

#include "ddads1115.h"

DDADS1115::DDADS1115(uint8_t gain = (uint8_t)0U){
    this->_gain = gain;
    Wire.begin();
    if(!ADS.begin()){
        if (SERIAL_ENABLED)
            Serial.println("ADS not connected");
    }
    else{
        if (SERIAL_ENABLED)
            Serial.println("ADS connected");
    }
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
    if (SERIAL_ENABLED){
        Serial.print("F: ");Serial.println(f * 1000.0);
        Serial.print("A0: ");Serial.print(ret.anag1);
        Serial.print(" A1: ");Serial.print(ret.anag2);
        Serial.print(" A2: ");Serial.print(ret.anag3);
        Serial.print(" A3: ");Serial.println(ret.anag4);
        Serial.print("V0: ");Serial.print(ret.volt1);
        Serial.print(" V1: ");Serial.print(ret.volt2);
        Serial.print(" V2: ");Serial.print(ret.volt3);
        Serial.print(" V3: ");Serial.println(ret.volt4);
    }
    return ret;
}

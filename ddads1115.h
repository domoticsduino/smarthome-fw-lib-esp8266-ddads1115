/* 1.0.0 VERSION */

#ifndef ads1115_h
#define ads1115_h

#include <SPI.h>
#include "ADS1x15.h"

struct DDADS1115Val{
    int16_t anag1 = 0;
    int16_t anag2 = 0;
    int16_t anag3 = 0;
    int16_t anag4 = 0;
    float volt1 = 0.0;
    float volt2 = 0.0;
    float volt3 = 0.0;
    float volt4 = 0.0;
};

class DDADS1115{

    private:
        ADS1115 ADS = ADS1115(0x48);
        uint8_t _gain;

    public:
        DDADS1115(uint8_t);
        DDADS1115Val getValues();

};

#endif
#pragma once

namespace lights {
    #include "driving.h"

    const int BLINK_INTERVAL = 100;
    bool blink_left = false;
    bool blink_right = false;
    bool back_lights = false;
    bool brake_lights = false;

    void setup() {
        for(int i = 16;i <= 19;i++){
            pinMode(i, OUTPUT);
        }
        for(int i = 32;i <= 39;i++){
            pinMode(i, OUTPUT);
        }
    }

    void loop() {
        for(int i = 0; i < 8; i += 2){    
            if(blink_right && (millis() / BLINK_INTERVAL) % 8 > i) digitalWrite(38 - i, HIGH);
            else digitalWrite(38 - i, LOW);
        }
        for(int i = 0; i < 8; i += 2){    
            if(blink_left && (millis() / BLINK_INTERVAL) % 8 > i) digitalWrite(39 - i, HIGH);
            else digitalWrite(39 - i, LOW);
        }
        if(back_lights){
            digitalWrite(16, HIGH);
        } else {
            digitalWrite(16, LOW);  
        }
        if (brake_lights || driving::emergency_brakes) { 
            for(int i = 17; i <= 19; i++){
                digitalWrite(i, HIGH);
            }
        }
        else {
            for(int i = 17; i <= 19; i++) {
                digitalWrite(i, LOW);
            }
        }
    }

    void bt_blink(int value) {
        blink_right  = (value & 0b0001) != 0;
        blink_left   = (value & 0b0010) != 0;
        back_lights  = (value & 0b0100) != 0;
        brake_lights = (value & 0b1000) != 0;
        if(brake_lights) driving::speed = 0;
    }
}
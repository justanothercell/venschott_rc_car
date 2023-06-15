#pragma once

namespace lights {
    const int BLINK_INTERVAL = 250;
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
        for(int i = 0;i <= 4;i++){    
            if(blink_left && (millis() / BLINK_INTERVAL) % 5 > i) digitalWrite(i + 32, HIGH);
            else digitalWrite(i + 32, LOW);
        }
        for(int i = 0;i <= 4;i++){    
            if(blink_right && (millis() / BLINK_INTERVAL) % 5 > i) digitalWrite(i + 36, HIGH);
            else digitalWrite(i + 36, LOW);
        }
        if(back_lights){
            digitalWrite(16,HIGH);
        } else {
            digitalWrite(16,LOW);  
        }
        if (brake_lights) { 
            for(int i = 17; i <= 19; i++){
                digitalWrite(i,HIGH);}
            }
        else {
            for(int i = 17; i <= 19; i++) {
                digitalWrite(i,LOW);
            }
        }
    }

    void bt_blink(int value) {
        blink_right  = value & 0b0001;
        blink_left   = value & 0b0010;
        back_lights  = value & 0b0100;
        brake_lights = value & 0b1000;
    }
}
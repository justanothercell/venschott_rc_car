#pragma once

namespace horn {
    const int HONK_PIN = 42;
    const int BEEP_PIN = 44;
    const int HONK_FREQ = 330;
    unsigned long honking = 0;

    void setup(){
        pinMode(HONK_PIN, OUTPUT);
    }

    void loop(){
        if(millis() - honking >= 200 && honking != 0) {
            digitalWrite(HONK_PIN, LOW);
            honking = 0;
        }
    }

    void bt_honk(int value) {
        if (value == 1) { 
           honking = millis();
           digitalWrite(HONK_PIN, HIGH);
        } else {
           honking = 0;
           digitalWrite(HONK_PIN, LOW);
        }
    }
}
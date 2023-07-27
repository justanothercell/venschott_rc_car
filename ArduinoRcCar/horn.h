#pragma once

namespace horn {
    const int BEEP_PIN = 11;
    const int HONK_FREQ = 330;
    unsigned long honking = 0;

    void setup(){
        pinMode(BEEP_PIN, OUTPUT);
    }

    void loop(){
        if(millis() - honking >= 200 && honking != 0) {
            digitalWrite(BEEP_PIN, LOW);
            honking = 0;
        }
    }

    void bt_honk(int value) {
        if (value == 1) { 
           honking = millis();
           digitalWrite(BEEP_PIN, HIGH);
        } else {
           honking = 0;
           digitalWrite(BEEP_PIN, LOW);
        }
    }
}
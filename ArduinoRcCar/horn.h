#pragma once

namespace horn {
    const int BEEP_PIN = 11;
    const int HONK_FREQ = 580;
    unsigned long honking = 0;

    void setup(){
        pinMode(BEEP_PIN, OUTPUT);
        noTone(BEEP_PIN);
    }

    void loop(){
        if(millis() - honking >= 300 && honking != 0) {
            noTone(BEEP_PIN);
        }
    }

    void bt_honk(int value) {
        if (value == 1) { 
           honking = millis();
           tone(BEEP_PIN, HONK_FREQ);
        } else {
           honking = 0;
           noTone(BEEP_PIN);
        }
    }
}
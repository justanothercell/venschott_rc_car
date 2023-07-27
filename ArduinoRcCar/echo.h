#pragma once

namespace echo {
    #include "horn.h"
    #include "driving.h"
    #include "utility.h"

    const int ECHO_FRONT_TRIGGER = 7;
    const int ECHO_FRONT_RECEIVER = 8;
    const int ECHO_BACK_TRIGGER = 5;
    const int ECHO_BACK_RECEIVER = 6;

    const unsigned long ECHO_INTERVAL = 200;

    unsigned long next_echo = 0;
    unsigned long next_beep = 0;
    float distance = 0.0;

    void setup(){
        pinMode(ECHO_BACK_TRIGGER, OUTPUT);
        pinMode(ECHO_BACK_RECEIVER, INPUT);
        pinMode(ECHO_FRONT_TRIGGER, OUTPUT);
        pinMode(ECHO_FRONT_RECEIVER, INPUT);
        next_echo = millis();
    }

    void loop(){
        if(driving::speed == 0) return;
        if(millis() > next_beep && distance > 0) {
            next_beep = millis() + (distance + 5) * 15;
            tone(horn::BEEP_PIN, 900, 75);
        }
        if(millis() > next_echo) {
            next_echo = millis() + ECHO_INTERVAL;

            int duration = 0;
            // trigger the echo
            // TODO: add if/else to trigger front/back depending on driving direction
            if(driving::forward) {
                digitalWrite(ECHO_FRONT_TRIGGER, HIGH);
                delayMicroseconds(10);
                digitalWrite(ECHO_FRONT_TRIGGER, LOW);
                duration = pulseIn(ECHO_FRONT_RECEIVER, HIGH, 25000);
            } else {
                digitalWrite(ECHO_BACK_TRIGGER, HIGH);
                delayMicroseconds(10);
                digitalWrite(ECHO_BACK_TRIGGER, LOW);
                duration = pulseIn(ECHO_BACK_RECEIVER, HIGH, 25000);
            }

            distance = (duration / 2.0) / 29.1; // caluclate distance using speed of sound
            if(distance > 40) distance = 0;
            driving::emergency_brakes = distance < 5;
        }
    }
}
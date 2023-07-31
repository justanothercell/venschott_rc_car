#pragma once

namespace echo {
    #include "horn.h"
    #include "driving.h"
    #include "utility.h"

    const int ECHO_FRONT_TRIGGER = 5;
    const int ECHO_FRONT_RECEIVER = 6;
    const int ECHO_BACK_TRIGGER = 7;
    const int ECHO_BACK_RECEIVER = 8;

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
            tone(horn::BEEP_PIN, 800, 75);
        }
        if(millis() > next_echo) {
            Serial.print(driving::speed);
            Serial.print(" ");
            Serial.println(driving::forward);
            next_echo = millis() + ECHO_INTERVAL;

            int duration = 0;

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
            Serial.println(distance);
            if(distance > 40) distance = 0;
            driving::emergency_brakes = distance < 7 && distance > 0;
        }
    }
}
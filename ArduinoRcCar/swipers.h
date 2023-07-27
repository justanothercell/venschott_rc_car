#pragma once

namespace swipers {
    const int SWIPER_SERVO = 3;
    const int MOISTURE_SENSOR = A2; // 56
    const int THRESHOLD = 400;

    Servo swiper;

    bool sweeper_right = false;
    int sweeper_angle = 30;

    void setup(){
        pinMode(SWIPER_SERVO, OUTPUT);
        swiper.attach(SWIPER_SERVO);
        swiper.write(sweeper_angle);
    }

    void loop(){
        int value = analogRead(MOISTURE_SENSOR);
        Serial.println(value);
        if(value > THRESHOLD){
            if(sweeper_right) {
                sweeper_angle ++;
                sweeper_right = sweeper_angle < 175;
            } else {
                sweeper_angle --;
                sweeper_right = sweeper_angle < 25;
            }
        } else {
            if(sweeper_angle >= 25) {
                sweeper_angle --;
            }
        }
        swiper.write(sweeper_angle);
    }
}
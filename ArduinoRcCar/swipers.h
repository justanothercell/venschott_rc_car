#pragma once

namespace swipers {
    const int SWIPER_SERVO = 3;
    const int MOISTURE_SENSOR = A0; // 54
    const int THRESHOLD = 400; // threshold needed for the sweepers to activate

    Servo swiper;

    bool sweeper_right = false;
    int sweeper_angle = 0;

    void setup(){
        pinMode(SWIPER_SERVO, OUTPUT);
        swiper.attach(SWIPER_SERVO);
    }

    void loop(){
        int value = analogRead(MOISTURE_SENSOR);
        if(value > THRESHOLD){
            if(sweeper_right) {
                sweeper_angle ++;
                sweeper_right = sweeper_angle >= 175;
            } else {
                sweeper_angle --;
                sweeper_right = sweeper_angle < 25;
            }
        }
        swiper.write(sweeper_angle);
    }
}
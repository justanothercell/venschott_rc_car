#pragma once

namespace driving {
    const int MOTOR_1_SPEED = 28; // 8
    const int MOTOR_1_FWD = 27; // 9
    const int MOTOR_1_BCK = 26; // 10
    const int MOTOR_2_SPEED = 31; // 12
    const int MOTOR_2_FWD = 30; // 11
    const int MOTOR_2_BCK = 29; // 12

    const int STEERING_SERVO = 3;

    Servo steering;

    int current_angle = 0;
    int desired_angle = 0;

    int speed = 0;
    bool forward = true;

    void setup(){
        pinMode(STEERING_SERVO, OUTPUT);
        steering.attach(STEERING_SERVO);

        
        pinMode(MOTOR_1_SPEED, OUTPUT);
        pinMode(MOTOR_1_FWD, OUTPUT);
        pinMode(MOTOR_1_BCK, OUTPUT);
        pinMode(MOTOR_2_SPEED, OUTPUT);
        pinMode(MOTOR_2_FWD, OUTPUT);
        pinMode(MOTOR_2_BCK, OUTPUT);
    }

    void loop(){
        if(desired_angle > current_angle) {
            current_angle --;
            steering.write(current_angle);
        }
        if(desired_angle < current_angle) {
            current_angle ++;
            steering.write(current_angle);
        }
    }

    void bt_steering(int value) {
        desired_angle = value;
    }

    void bt_speed(int value) {
    }
}
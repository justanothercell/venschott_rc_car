#pragma once

namespace driving {
    const int MOTOR_1_SPEED = 28; // 8
    const int MOTOR_1_FWD = 27; // 9
    const int MOTOR_1_BCK = 26; // 10
    const int MOTOR_2_SPEED = 31; // 12
    const int MOTOR_2_FWD = 29; // 11
    const int MOTOR_2_BCK = 30; // 12

    const int STEERING_SERVO = 9;
    const int STEERING_FWD_OFFSET = 90;

    Servo steering;

    int current_angle = STEERING_FWD_OFFSET;
    int desired_angle = STEERING_FWD_OFFSET;

    int speed = 0;
    bool forward = true;
    bool emergency_brakes = false;

    void setup(){
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
            current_angle += 1;
        }
        if(desired_angle < current_angle) {
            current_angle -= 1;
        }
        steering.write(current_angle);
        if(emergency_brakes || speed == 0) {
            digitalWrite(MOTOR_1_FWD, LOW);
            digitalWrite(MOTOR_2_FWD, LOW);
            digitalWrite(MOTOR_1_BCK, LOW);
            digitalWrite(MOTOR_2_BCK, LOW);
            analogWrite(MOTOR_1_SPEED, 0);
            analogWrite(MOTOR_2_SPEED, 0);
        } else {
            if(forward){
                digitalWrite(MOTOR_1_FWD, HIGH);
                digitalWrite(MOTOR_2_FWD, HIGH);
                digitalWrite(MOTOR_1_BCK, LOW);
                digitalWrite(MOTOR_2_BCK, LOW);
            } else {
                digitalWrite(MOTOR_1_FWD, LOW);
                digitalWrite(MOTOR_2_FWD, LOW);
                digitalWrite(MOTOR_1_BCK, HIGH);
                digitalWrite(MOTOR_2_BCK, HIGH);
            }
            analogWrite(MOTOR_1_SPEED, speed);
            analogWrite(MOTOR_2_SPEED, speed);
        }
    }

    void bt_steering(int value) {
        desired_angle = value;
    }

    void bt_speed(int value) {
        if(value >= 0) {
            speed = value;
            forward = false;
        } else {
            speed = -value;
            forward = true;
        }
    }
}
namespace driving {
    const int MOTOR = 2;
    const int STEERING_SERVO = 3;

    Servo steering;

    int current_angle = 0;
    int desired_angle = 0;

    void setup(){
        pinMode(MOTOR, OUTPUT);
        pinMode(STEERING_SERVO, OUTPUT);
        steering.attach(STEERING_SERVO);
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
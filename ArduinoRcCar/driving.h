namespace steering {
    const int STEERING_SERVO = 3;

    Servo steering;

    void setup(){
        pinMode(STEERING_SERVO, OUTPUT);
        steering.attach(STEERING_SERVO);
    }

    void loop(){

    }

    void bt_steering(int value) {

    }

    void bt_speed(int value) {

    }
}
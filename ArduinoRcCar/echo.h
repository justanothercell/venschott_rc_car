namespace echo {
    const int ECHO_BACK_TRIGGER = 5;
    const int ECHO_BACK_RECEIVER = 6;
    const int ECHO_FRONT_TRIGGER = 7;
    const int ECHO_FRONT_RECEIVER = 8;

    void setup(){
        pinMode(ECHO_BACK_TRIGGER, OUTPUT);
        pinMode(ECHO_BACK_RECEIVER, INPUT);
        pinMode(ECHO_FRONT_TRIGGER, OUTPUT);
        pinMode(ECHO_FRONT_RECEIVER, INPUT);
    }

    void loop(){

    }
}
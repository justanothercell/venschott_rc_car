namespace echo {
    const int ECHO_BACK_TRIGGER = 5;
    const int ECHO_BACK_RECEIVER = 6;
    const int ECHO_FRONT_TRIGGER = 7;
    const int ECHO_FRONT_RECEIVER = 8;

    const int BEEP_PIN = 11;

    unsigned long next_echo = 0;
    const unsigned long ECHO_INTERVAL = 500;

    void setup(){
        pinMode(ECHO_BACK_TRIGGER, OUTPUT);
        pinMode(ECHO_BACK_RECEIVER, INPUT);
        pinMode(ECHO_FRONT_TRIGGER, OUTPUT);
        pinMode(ECHO_FRONT_RECEIVER, INPUT);

        pinMode(BEEP_PIN, OUTPUT);
    }

    void loop(){
        if(millis() - next_echo > 0) {
            next_echo += ECHO_INTERVAL;

            int duration = 0;
            // trigger the echo
            // TODO: add if/else to trigger front/back depending on driving direction
            digitalWrite(ECHO_BACK_TRIGGER, HIGH);
            delayMicroseconds(10);
            digitalWrite(ECHO_BACK_TRIGGER, LOW);
            duration = pulseIn(ECHO_BACK_RECEIVER, HIGH);
            float distance = (duration / 2.0) / 29.1; // caluclate distance using speed of sound

            if (distance > 30 || distance == 0) {
              // too far away or invalid: do nothing
            }
            else if (distance > 20) {
                tone(BEEP_PIN, 500, 100);
            }
            else if (distance > 12) {
                tone(BEEP_PIN, 400, 100);
            }
            else if (distance > 6) {
                tone(BEEP_PIN, 300, 100);
            }
            else {
                tone(BEEP_PIN, 200, 100);
            }
        }
    }
}
namespace lights {
    const int BLINK_INTERVAL = 250;
    bool blink_left = false;
    bool blink_right = false;

    void setup() {
        for(int i = 32;i <= 39;i++){
            pinMode(i, OUTPUT);
        }
    }

    void loop() {
        for(int i = 0;i <= 4;i++){    
            if(blink_left && (millis() / BLINK_INTERVAL) % 4 == i) digitalWrite(i + 32, HIGH);
            else digitalWrite(i + 32, LOW);
        }
        for(int i = 0;i <= 4;i++){    
            if(blink_left && (millis() / BLINK_INTERVAL) % 4 == i) digitalWrite(i + 36, HIGH);
            else digitalWrite(i + 36, LOW);
        }
    }

    void bt_blink(int value) {
        blink_left = value & 0b10 > 0;
        blink_right = value & 0b01 > 0;
    }
}
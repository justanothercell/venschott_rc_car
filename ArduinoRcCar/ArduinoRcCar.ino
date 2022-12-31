#include "SoftwareSerial.h"
#include "Servo.h"

#include "echo.h"
#include "lights.h"
#include "driving.h"
#include "swipers.h"
#include "horn.h"

using namespace echo;
using namespace lights;
using namespace driving;
using namespace swipers;
using namespace horn;

SoftwareSerial BT(13, 14);

void setup(){
    BT.begin(9600);
    Serial.begin(9600);

    echo::setup();
    lights::setup();
    driving::setup();
    swipers::setup();
    horn::setup();
}

void loop(){
    String raw_data = String();
    while(BT.available()) { 
        char c = BT.read();
        if(c == '\n') break;
        raw_data += c;
    }
    if(raw_data.length() > 0){
        int split = raw_data.indexOf(';');
        int command = raw_data.substring(0, split - 1).toInt();
        int value = raw_data.substring(split + 1).toInt();
        switch(command){
            case 0: // steering angle
                driving::bt_steering(value);
                break;
            case 1: // speed
                driving::bt_speed(value);
                break;
            case 2: // blinker lights on/off
                lights::bt_blink(value);
                break;
            case 3: // horn
                horn::bt_honk(value);
                break;
        }
    }
    echo::loop();
    lights::loop();
    driving::loop();
    swipers::loop();
    horn::loop();
}


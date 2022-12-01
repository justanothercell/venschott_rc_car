int messwert = 0;
int triggerR = 7;
int triggerV = 5;
int echoV = 8;
int echoR = 6;

void setup(){
    BT.begin(9600);
}

void loop(){

}

void setup() {

    pinMode(2, OUTPUT);
    wischen.attach(3);
    Lenkung.attach(9);
    for (int i = 10; i < 40; i++) {
        pinMode(i, OUTPUT);
    }
    pinMode(echoV, INPUT); pinMode(echoR, INPUT);
    pinMode(triggerV, OUTPUT); pinMode(triggerR, OUTPUT);
}

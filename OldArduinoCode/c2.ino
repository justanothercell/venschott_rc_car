// Lenkung links: 2;100 bis 2;200 rechts: 2;300 bis 2;400. Achtung!! 2;100 steht für (wieder) geradeaus.
// Fahrtrichtung vorwärts: 3;100 bis 3;355
// Fahrtrichtung rückwärts: 4;100 bis 4;355
// Hupe an: 6;100
// Warnblinker an: 5;100 aus: 5;200
// Standby: 0;000

#include #include #include
SoftwareSerial BT(13, 14);

Servo wischen;
Servo Lenkung;

muTimer myTimer1 = muTimer();
muTimer myTimer2 = muTimer();
muTimer myTimer3 = muTimer();
muTimer myTimer4 = muTimer();
muTimer myTimer5 = muTimer();
muTimer myTimer6 = muTimer();
muTimer myTimer7 = muTimer();

bool output1;
bool output2;
bool output3;
bool output4;

int B;
int triggerR = 7;
int triggerV = 5;
int echoV = 8;
int echoR = 6;
long Dauer = 0;
float Entfernung = 0;
int Drehzahl;

void setup() {
    BT.begin(9600);
    pinMode(2, OUTPUT);
    wischen.attach(3);
    Lenkung.attach(9);
    for (int i = 10; i < 40; i++) {
        pinMode(i, OUTPUT);
    }
    pinMode(echoV, INPUT); pinMode(echoR, INPUT);
    pinMode(triggerV, OUTPUT); pinMode(triggerR, OUTPUT);
}

void loop() {
    digitalWrite(5, LOW); digitalWrite(7, LOW);


    if (BT.available()) {
        String Wert = String(BT.read()); String Wert1 = Wert.substring(1); String Wert2 = Wert.substring(3, Wert.length()); //5

        switch (Wert1.toInt()) {
            case 2: if (Wert2.toInt() == 100) {
                    for (int i = 32; i <= 39; i++) {
                        digitalWrite(i, LOW);
                    }
                }
                if (Wert2.toInt() > 100 && Wert2.toInt() < 200)
                { Lenkung.write(Wert2.toInt() - 100);
                    output1 = myTimer1.cycleOnOff(700, 100);
                    output2 = myTimer2.cycleOnOff(550, 250);
                    output3 = myTimer3.cycleOnOff(400, 400);
                    output4 = myTimer4.cycleOnOff(250, 550);
                    digitalWrite(32, output1);
                    digitalWrite(33, output2);
                    digitalWrite(34, output3);
                    digitalWrite(35, output4);
                }

                if (Wert2.toInt() > 300 && Wert2.toInt() < 400)
                { Lenkung.write(Wert2.toInt() - 200);
                    output1 = myTimer1.cycleOnOff(700, 100);
                    output2 = myTimer2.cycleOnOff(550, 250);
                    output3 = myTimer3.cycleOnOff(400, 400);
                    output4 = myTimer4.cycleOnOff(250, 550);
                    digitalWrite(36, output1);
                    digitalWrite(37, output2);
                    digitalWrite(38, output3);
                    digitalWrite(39, output4);
                } break;

            case 3: if (Wert2.toInt() >= 100 && Wert2.toInt() <= 355 ) {
                    digitalWrite(16, LOW);
                    for (int i = 32; i <= 39; i++) {
                        digitalWrite(i, LOW);
                    }
                    analogWrite(10, Wert2.toInt() - 100);
                }

            case 4: if (Wert2.toInt() >= 100 && Wert2.toInt() <= 355 ) {
                    digitalWrite(16, HIGH);
                    for (int i = 32; i <= 39; i++) {
                        digitalWrite(i, LOW);
                    }
                    analogWrite(10, Wert2.toInt() - 100);
                }

            case 5: if (Wert2.toInt() == 100) {
                    output1 = myTimer1.cycleOnOff(700, 100);
                    output2 = myTimer2.cycleOnOff(550, 250);
                    output3 = myTimer3.cycleOnOff(400, 400);
                    output4 = myTimer4.cycleOnOff(250, 550);
                    digitalWrite(32, output1); digitalWrite(36, output1);
                    digitalWrite(33, output2); digitalWrite(37, output2);
                    digitalWrite(34, output3); digitalWrite(38, output3);
                    digitalWrite(35, output4); digitalWrite(39, output4);
                }
                if (Wert2.toInt() == 200) {
                    for (B = 32; B <= 39; B++) {
                        digitalWrite(B, LOW);
                    }
                } break;

            case 6: if (Wert2.toInt() == 100) {
                    tone(11, 250, 400);
                } break;

            case 0: for (int i = 32; i <= 39; i++) {
                    digitalWrite(i, LOW);
                } Lenkung.write(90); break;

            default: for (int i = 32; i <= 39; i++) {
                    digitalWrite(i, LOW);
                } Lenkung.write(90); break;
        }
    }
}
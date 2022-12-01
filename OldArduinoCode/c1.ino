#include #include
Servo wischen;
muTimer myTimer1 = muTimer();
muTimer myTimer2 = muTimer();
muTimer myTimer3 = muTimer();
muTimer myTimer4 = muTimer();
muTimer myTimer5 = muTimer();

int wischerCounter = 20;
bool wischerDir = true;
bool Fahrtrichtung = false;
int messwert = 0;
int triggerR = 7;
int triggerV = 5;
int echoV = 8;
int echoR = 6;
bool cycleTrigger (uint32_t cycleTime);
bool wechsel = false;

void setup () {
    pinMode(4, OUTPUT);
    pinMode(11, OUTPUT);
    Serial.begin(9600);
    wischen.attach(12);
    pinMode(echoV, INPUT);
    pinMode(echoR, INPUT);
    pinMode(triggerV, OUTPUT);
    pinMode(triggerR, OUTPUT);
}
/* ==========
Wir haben pulseIn mit timeIt ersetzt und den zweiten timer entfernt.
Das Programm wartet nun maximal 5ms auf eine Antwort und bricht ggf die Suche ab
==========
*/
void loop () {
    digitalWrite(5, LOW); digitalWrite(7, LOW);
    if (myTimer3.cycleTrigger(1980)) {
        int dauer;
        if (Fahrtrichtung) {
            digitalWrite(triggerV, HIGH);
            delayMicroseconds(10);
            digitalWrite(triggerV, LOW);
            dauer = pulseIn(echoV, HIGH);
        }
        else {
            digitalWrite(triggerR, HIGH);
            delayMicroseconds(10);
            digitalWrite(triggerR, LOW);
            dauer = pulseIn(echoR, HIGH);
        }
        Serial.print("dauer ");
        Serial.println(dauer);
        float entfernung = (dauer / 2.0) / 29.1;

        if (entfernung > 30 || dauer == 0) {
// nichts tun, zu weit weg
        }//tone(11,600,100);}
        else if (entfernung > 20) {
            Serial.println("4");
        }//tone(11,500,100);}
        else if (entfernung > 12) {
            Serial.println("3");
        }//tone(11,400,100);}
        else if (entfernung > 6) {
            Serial.println("2");
        }//tone(11,300,100);}
        else {
            Serial.println("1");
        }//tone(11,200,100);}
    }

    if (myTimer1.cycleTrigger(3210)) {
        if (wechsel == false) {
            digitalWrite(4, HIGH);
            wechsel = true;
        } else {
            digitalWrite(4, LOW);
            wechsel = false;
        }
    }
    messwert = analogRead(A0);

    if (myTimer2.cycleTrigger(5)) {
        if (messwert > 400) {
            if (wischerDir) { // nach rechts
                wischerCounter++;
                if (wischerCounter >= 170) wischerDir = false;
            }
            else { // nach links
                wischerCounter--;
                if (wischerCounter <= 20) wischerDir = true;
            }
        }
        else {
            if (wischerCounter > 20) wischerCounter--;
        }
        wischen.write(wischerCounter);
    }
}

/*
int timeIt(int pin, int trigger, int timeout)

pin: the pin observed
trigger: the trigger value, either HIGH or LOW
timeout: the time after which this fucntion aborts

returns: number of milliseconds until pin switches to trigger or the timeout
*/
int timeIt(int pin, int trigger, int timeout) {
    int s = millis();
    while (millis() - s < timeout) {
        if (digitalRead(pin) == trigger) return millis() - s;
    }
    return timeout;
}
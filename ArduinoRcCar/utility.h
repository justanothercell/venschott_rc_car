#pragma once

/*
int timeIt(int pin, int trigger, int timeout)

pin: the pin observed
trigger: the trigger value, either HIGH or LOW
timeout: the time after which this function aborts

returns: number of milliseconds until pin switches to trigger or the timeout
*/
int timeIt(int pin, int trigger, int timeout) {
    int s = millis();
    while (millis() - s < timeout) {
        if (digitalRead(pin) == trigger) return millis() - s;
    }
    return timeout;
}
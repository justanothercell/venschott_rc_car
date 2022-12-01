# RC car school project
Started by 10th graders (year '21-'22), software by me

### Components
- [Arduino Rc Car Software](./ArduinoRcCar)
- [Android (Processing) remote control app](./AndroidApp)
- [Old Arduino Source Code](./OldArduinoCode)

### Protocol

send: `<id>;<value>\n`

| command        | id  | value range |
|----------------|-----|-------------|
| steering angle | 0   |             |
| speed          | 1   |             |
| blinker lights | 2   | 0 &#124 1   |
| horn           | 3   | 0           |

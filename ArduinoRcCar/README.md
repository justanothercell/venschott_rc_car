### Arduino RC Car
This is the arduino side of the project, which runs on the rc car.

### Pins

| pin     | pinMode | description                |
|---------|---------|----------------------------|
| 1       | OUTPUT  | motor_forward              |
| 2       | OUTPUT  | motor_backward             |
| 3       | OUTPUT  | swiper servo               |
| 5       | OUTPUT  | echo trigger back          |
| 6       | INPUT   | echo back                  |
| 7       | OUTPUT  | echo trigger front         |
| 8       | INPUT   | echo front                 |
| 9       | OUTPUT  | steering servo             |
| 11      | OUTPUT  | beeper                     |
| 12      | OUTPUT  | horn                       |
| 13      | ?       | bluetooth TXD data out     |
| 14      | INPUT   | bluetooth RXD Rdata in     |
| 16      | OUTPUT  | back lights                |
| 17      | OUTPUT  | BRAKE LIGHTS LEFT          |
| 18      | OUTPUT  | BRAKE LIGHTS RIGHT         |
| 19      | OUTPUT  | BRAKE LIGHTS BACK          |
| 30      | ?       | motor driver               |
| 32-39   | OUTPUT  | blinker, %2->left/right    |
| A2 (56) | INPUT   | water detector for sweeper |

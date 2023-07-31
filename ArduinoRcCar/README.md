### Arduino RC Car
This is the arduino side of the project, which runs on the rc car.

### Pins

| pin     | pinMode | description                |
|---------|---------|----------------------------|
| 3       | OUTPUT  | swiper servo               |
| 5       | OUTPUT  | echo trigger front         |
| 6       | INPUT   | echo front                 |
| 7       | OUTPUT  | echo trigger back          |
| 8       | INPUT   | echo back                  |
| 9       | OUTPUT  | steering servo             |
| 11      | ?       | servo internal             |
| 12      | ?       | servo internal             |
| 13      | ?       | bluetooth TXD data out     |
| 14      | INPUT   | bluetooth RXD Rdata in     |
| 16      | OUTPUT  | back lights                |
| 17      | OUTPUT  | BRAKE LIGHTS LEFT          |
| 18      | OUTPUT  | BRAKE LIGHTS RIGHT         |
| 19      | OUTPUT  | BRAKE LIGHTS BACK          |
| 30      | ?       | motor driver               |
| 32-39   | OUTPUT  | blinker, %2->left/right    |
| 42      | OUTPUT  | beeper                     |
| 44      | OUTPUT  | horn                       |
| A5 (59) | INPUT   | water detector for sweeper |

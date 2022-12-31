// init and update replace setup and draw

float speed = 0;
float steering = 0;
boolean blinkerLeft = false;
boolean blinkerRight = false;
boolean blinkerWarn = false;
boolean lights = false;

void init(){
  strokeWeight(5);
}

void update(){
  background(255);
  steering = sliderH(steering, u(200), u(50),  u(600), u(100));
  speed = sliderV(speed, u(70), u(500),  u(100), u(800));
  
  // steering
  int steeringMask = (blinkerLeft ? 0b10 : 0b00) | (blinkerRight ? 0b01 : 0b00);
  blinkerLeft = buttonToggle("L", blinkerLeft && !blinkerRight && !blinkerWarn, u(150), u(200),  u(200), u(200));
  blinkerWarn = buttonToggle("!", blinkerWarn, u(400), u(200),  u(200), u(200));
  blinkerRight = buttonToggle("R", blinkerRight && !blinkerLeft && !blinkerWarn, u(650), u(200),  u(200), u(200));
  int steeringMaskNew = (blinkerLeft ? 0b10 : 0b00) | (blinkerRight ? 0b01 : 0b00) | (blinkerWarn ? 0b11 : 0b00);
  if(steeringMask != steeringMaskNew){
    // blinker updates
  }
  
  // lights
  boolean pl = lights;
  lights = buttonToggle("Lights", lights, u(250), u(450),  u(500), u(200));
  if(lights != pl){
    // lights updates
  }
  
  // horn
  if(button("Horn", u(250), u(700),  u(500), u(200)) == BUTTON_CLICK){
    // horn honked
  }
}

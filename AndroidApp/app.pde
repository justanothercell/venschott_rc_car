// init and update replace setup and draw

float speed = 0;
float steering = 0;
boolean blinkerLeft = false;
boolean blinkerRight = false;
boolean blinkerWarn = false;
boolean lights = false;

void init(){
  isConfiguring = false;
  strokeWeight(5);
}

void update(){
  if (isConfiguring){
    configureBT();
    return;
  }
  
  runMain();
}

void runMain(){
  background(255);
  steering = sliderH(steering, u(200), u(50),  u(600), u(100));
  speed = sliderV(speed, u(70), u(500),  u(100), u(800));
  
  // steering
  int steeringMask = (blinkerLeft ? 0b10 : 0b00) | (blinkerRight ? 0b01 : 0b00);
  blinkerLeft = buttonToggle("L", blinkerLeft && !blinkerRight && !blinkerWarn, u(150), u(200),  u(200), u(200));
  blinkerWarn = buttonToggle("!", blinkerWarn, u(400), u(200),  u(200), u(200));
  blinkerRight = buttonToggle("R", blinkerRight && !blinkerLeft && !blinkerWarn, u(650), u(200),  u(200), u(200));
  if(button("connectBT", u(200), h(-200), w(-400), u(170)) == BUTTON_CLICK) isConfiguring = true;
  int steeringMaskNew = (blinkerLeft ? 0b10 : 0b00) | (blinkerRight ? 0b01 : 0b00) | (blinkerWarn ? 0b11 : 0b00);
  if(steeringMask != steeringMaskNew){
    sendData(2, steeringMask);
  }
  
  // lights
  boolean pl = lights;
  lights = buttonToggle("Lights", lights, u(250), u(450),  u(500), u(200));
  if(lights != pl){
    //sendData();
  }
  
  // horn
  if(button("Horn", u(250), u(700),  u(500), u(200)) == BUTTON_CLICK){
    sendData(3, 0);
  }
}

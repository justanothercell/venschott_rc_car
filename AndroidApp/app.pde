// init and update replace setup and draw

float speed = 0.5;
float steering = 0.5;
boolean blinkerLeft = false;
boolean blinkerRight = false;
boolean blinkerWarn = false;
boolean lights = false;
boolean brakes = false;

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
  //println(bt.isConnected);
  background(255);  
  
  if(connectedDevice==null) { if(button("connectBT", u(200), h(-200), w(-400), u(170)) == BUTTON_CLICK) isConfiguring = true; }
  else { if(button(connectedDevice, u(200), h(-200), w(-400), u(170)) == BUTTON_CLICK) isConfiguring = true; }
  
  // steering
  int lightMask = (int(blinkerRight) << 0) | (int(blinkerLeft) << 1) | (blinkerWarn ? 0b11 : 0b00) | (int(lights) << 2) | (int(brakes) << 3);
  blinkerLeft = buttonToggle("L", blinkerLeft && !blinkerRight && !blinkerWarn, u(150), u(200),  u(200), u(200));
  blinkerWarn = buttonToggle("!", blinkerWarn, u(400), u(200),  u(200), u(200));
  blinkerRight = buttonToggle("R", blinkerRight && !blinkerLeft && !blinkerWarn, u(650), u(200),  u(200), u(200));
  lights = buttonToggle("Lights", lights, u(250), u(450),  u(500), u(200));
  boolean pBrakes = brakes;
  brakes = buttonToggle("Stop", brakes, u(250), u(950),  u(500), u(200));
  
  int lightMaskMaskNew =  (int(blinkerRight) << 0) | (int(blinkerLeft) << 1) | (blinkerWarn ? 0b11 : 0b00) | (int(lights) << 2) | (int(brakes) << 3);
  if(lightMask != lightMaskMaskNew){
    sendData(2, lightMaskMaskNew);
  }
  // 1024 is arbtrary range for transmission
  int pSteering = int(steering * 1024);
  int cp = colorButtonPressed;
  if(steering==0.5) colorButtonPressed = colorButtonNormal;
  steering = sliderH(steering, u(200), u(50),  u(600), u(100));
  colorButtonPressed = cp;
  if(abs(steering-0.5) < 0.075) steering = 0.5;
  int newSteering = int(steering * 1024);
  if(pSteering != newSteering) sendData(0, newSteering);
  // analogWrite is 0-255
  int pSpeed = int(speed * 512) - 256;
  if(speed==0.5) colorButtonPressed = colorButtonNormal;
  int cn = colorButtonNormal;
  if(brakes) {
    colorButtonNormal = cp;
    colorButtonPressed = cp;
  }
  speed = sliderV(speed, u(70), u(500),  u(100), u(800));
  colorButtonPressed = cp;
  colorButtonNormal = cn;
  if(abs(speed-0.5) < 0.075) speed = 0.5;
  int newSpeed = int(speed * 512) - 256;
  if(pSpeed != newSpeed && !brakes) sendData(1, newSpeed);
  if(brakes) {
    speed = 0.5;
    if(!pBrakes) sendData(1, 0);
  }
  
  // horn
  if(button("Horn", u(250), u(700),  u(500), u(200)) == BUTTON_CLICK){
    sendData(3, 1);
  }
}

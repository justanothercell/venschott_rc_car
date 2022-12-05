// init and update replace setup and draw

float speed = 0;
float steering = 0;

void init(){
  strokeWeight(5);
}

void update(){
  background(255);
  button("BUTTON", u(300), u(100),  u(400), u(200));
  steering = sliderH(steering, u(200), u(400),  u(600), u(50));
  speed = sliderV(speed, u(100), u(500),  u(50), u(800));
}

float u;
float uwidth;
float uheight;

color colorBg = #333333;
color colorButtonNormal = #AAAAAA;
color colorButtonPressed = #666666;
color colorText = #FFFFFF;
color colorTextButton = #000000;

int BUTTON_UP = 0;
int BUTTON_DOWN = 1;
int BUTTON_CLICK = 2;

int selectedElement;
int currentElement;

void setSize(PVector size){
  setSize((int)size.x, (int)size.y);
}

void initUI(){
  u = width/1000.0;
  uwidth = 1000;
  uheight = height/u;
  textSize(u*80);
}

void updateUIPre(){
  currentElement = 0;
}

void updateUIPost(){
  if(mousePressed && selectedElement==0){
    selectedElement = -1;
  }
  if(!mousePressed){
    selectedElement = 0;
  }
}

int button(String text, PVector pos, PVector size){
  return button(text, pos.x, pos.y, size.x, size.y);
}

int button(String text, float x, float y, float w, float h){
  textAlign(CENTER,CENTER);
  currentElement++;
  if(selectedElement==0 && mousePressed && mouseX > x && mouseX < x+w && mouseY > y && mouseY < y+h){
    selectedElement = currentElement;
  }
  if(selectedElement==currentElement){
    fill(colorButtonPressed);
    rect(x, y, w, h);
    fill(colorTextButton);
    text(text, x+w/2, y+h/2);
    if(!mousePressed) return BUTTON_CLICK;
    return BUTTON_DOWN;
  }
  fill(colorButtonNormal);
  rect(x, y, w, h);
  fill(colorTextButton);
  text(text, x+w/2, y+h/2);
  return BUTTON_UP;
}

float sliderH(float value, PVector pos, PVector size){
  return sliderH(value, pos.x, pos.y, size.x, size.y);
}

float sliderH(float value, float x, float y, float w, float h){
  textAlign(CENTER,CENTER);
  currentElement++;
  fill(colorButtonNormal);
  rect(x, y, w, h);
  fill(colorButtonPressed);
  rect(value*w+x-u(20), y-u(10), u(40), h+u(20));
  if(selectedElement==0 && mousePressed && mouseX > x && mouseX < x+w && mouseY > y && mouseY < y+h){
    selectedElement = currentElement;
  }
  if(selectedElement==currentElement){
    return constrain((mouseX-x)/w, 0, 1);
  }
  return value;
}

float sliderV(float value, PVector pos, PVector size){
  return sliderV(value, pos.x, pos.y, size.x, size.y);
}

float sliderV(float value, float x, float y, float w, float h){
  textAlign(CENTER,CENTER);
  currentElement++;
  fill(colorButtonNormal);
  rect(x, y, w, h);
  fill(colorButtonPressed);
  rect(x-u(10), value*h+y-u(20), w+u(20), u(40));
  if(selectedElement==0 && mousePressed && mouseX > x && mouseX < x+w && mouseY > y && mouseY < y+h){
    selectedElement = currentElement;
  }
  if(selectedElement==currentElement){
    return constrain((mouseY-y)/h, 0, 1);
  }
  return value;
}


float u(float i){
  return i*u;
}

float cx(float i){
  return u(uwidth/2+i);
}

float cy(float i){
  return u(uheight/2+i);
}

float w(float i){
  return u(uwidth+i);
}

float h(float i){
  return u(uheight+i);
}

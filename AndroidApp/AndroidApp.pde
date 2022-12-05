void setup(){
  orientation(PORTRAIT);
  fullScreen();
  initUI();
  init();
}

void draw(){
  updateUIPre();
  update();
  updateUIPost();
}

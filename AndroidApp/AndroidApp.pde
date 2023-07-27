import java.nio.charset.StandardCharsets;
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

void ellipse(PVector a, PVector size){
  ellipse(a.x, a.y, size.x, size.y);
}

void circle(PVector origin, float size){
  circle(origin.x, origin.y, size);
}

void rect(PVector a, PVector b){
  rect(a.x, a.y, b.x, b.y);
}

void image(PImage image, PVector a, PVector b){
  image(image, a.x, a.y, b.x, b.y);
}

void line(float x1, float y1, float x2, float y2, DashSegment... dashes){
  line(new PVector(x1, y1), new PVector(x2, y2), dashes);
}

// dash example:
// line(100, 100, 500, 500, dash(5, #00FF00), emptyDash(5), dash(5, #FFFF00), emptyDash(5));

void line(PVector pos1, PVector pos2, DashSegment... dashes){
  PVector dir = pos2.copy().sub(pos1);
  float mag = dir.mag();
  float traveled = 0;
  dir.normalize();
  while(traveled < mag){
    for(DashSegment dash:dashes){
      if(!dash.empty){
        stroke(dash.col);
        strokeWeight(dash.weight);
        line(pos1.x, pos1.y, pos1.x+dir.x*dash.len, pos1.y+dir.y*dash.len);
      }
      pos1.add(dir.copy().mult(dash.len));
      traveled += dash.len;
      if(traveled > mag) break;
    }
  }
}

DashSegment dash(float len, color col){
  return new DashSegment(len, 1, col);
}

DashSegment dash(float len, float weight, color col){
  return new DashSegment(len, weight, col);
}

DashSegment emptyDash(float len){
  return new DashSegment(len);
}

class DashSegment{
  float len;
  float weight;
  color col;
  boolean empty;
  
  public DashSegment(float len, float weight, color col){
    this.len = len;
    this.weight = weight;
    this.col = col;
  }
  
  public DashSegment(float len){
    this.len = len;
    this.empty = true;
  }
}

void setup(){
  size(300,500);
  
  face(150,150,10);
  eye(120,140,10);
  mouth(150,170,10);
  
  face(150,300,15);
  eye(105,285,15);
  mouth(150,330,15);
}

void face(float x, float y, float d){
  fill(251,206,177);
  circle(x,y,d*10);
}

void eye(float eye_x, float eye_y, float d){
  stroke(0,0,0);
  line(eye_x,eye_y,eye_x+2*d,eye_y-2*d);
  line(eye_x+2*d,eye_y,eye_x,eye_y-2*d);
  
  line(eye_x+4*d,eye_y,eye_x+6*d,eye_y-2*d);
  line(eye_x+6*d,eye_y,eye_x+4*d,eye_y-2*d);
}

void mouth(float mouth_x, float mouth_y, float d){
  fill(128,128,128);
  circle(mouth_x,mouth_y,d*2);
}

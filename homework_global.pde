float d,x,y,eye_x,eye_y,mouth_x,mouth_y;
void setup(){
  size(300,500);
  
  d=10;
  x=150; //face x
  y=150; // face y
  
  eye_x=x-3*d;
  eye_y=y-d;
  
  mouth_x=x;
  mouth_y=y+2*d;
  
  
  face();
  eye();
  mouth();
  
  x=150;
  y=300;
  d=15;
  
  eye_x=x-3*d;
  eye_y=y-d;
  mouth_x=x;
  mouth_y=y+2*d;
  
  face();
  eye();  
  mouth();
}

void face(){
  fill(251,206,177);
  circle(x,y,d*10);
}
  
void eye(){
 stroke(0,0,0);
 line(eye_x,eye_y,eye_x+2*d,eye_y-2*d);
 line(eye_x+2*d,eye_y,eye_x,eye_y-2*d);
 
 line(eye_x+4*d,eye_y,eye_x+6*d,eye_y-2*d);
 line(eye_x+6*d,eye_y,eye_x+4*d,eye_y-2*d);
}

void mouth(){
  fill(128,128,128);
  circle(mouth_x,mouth_y,d*2);
} 

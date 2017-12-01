#define RedButton 12
#define GreenButton 13
#define UpButton 9
#define DownButton 11
#define LeftButton 10
#define RightButton 8

short up=4; //u
short upEnd=5;
short down=6; //d
short downEnd=7;
short left=8; //l
short leftEnd=9;
short right=10; //r
short rightEnd=11;
short leftClick=1; //LDown
short leftUnclick=0; //LUp
short rightClick=2; //RDown
short rightUnclick=3; //RUp
//bool Ready=false;
bool yPosActive=false;
bool yNegActive=false;
bool xPosActive=false;
bool xNegActive=false;
bool b1Active=false;
bool b2Active=false;


void setup(){
  
 pinMode(RedButton,INPUT);
 digitalWrite(RedButton,HIGH);
 pinMode(GreenButton,INPUT);
 digitalWrite(GreenButton,HIGH);
 pinMode(UpButton,INPUT);
 digitalWrite(UpButton,HIGH);
 pinMode(DownButton,INPUT);
 digitalWrite(DownButton,HIGH);
 pinMode(LeftButton,INPUT);
 digitalWrite(LeftButton,HIGH);
 pinMode(RightButton,INPUT);
 digitalWrite(RightButton,HIGH);
 
 Serial.begin(115200,SERIAL_8N1);
 //delay(100);
}

//Function that checks if connection is working
/*bool state(){
  Serial.write("Controller Ready");
  if (Serial.available() < 0){
    delay(500);
    state();
  }
  else{
    return true;
  }
}
*/

void loop() {
  /*
  while (Ready==false){
    Ready=state();
  }
  */
  
  //Serial.write("Controller Ready");
  //Left click serial out
  if ((digitalRead(RedButton)==0)&&(b1Active==false)){
    Serial.write(leftClick);
    b1Active=true;
  }
  if ((digitalRead(RedButton)==1)&&(b1Active==true)){
    Serial.write(leftUnclick);
    b1Active=false;
  }
  
  //Right click serial out
  if((digitalRead(GreenButton)==0)&&(b2Active==false)){
    Serial.write(rightClick);
    b2Active=true;
  }
  if((digitalRead(GreenButton)==1)&&(b2Active==true)){
    Serial.write(rightUnclick);
    b2Active=false;
  }
  
  //Up movement serial out
  if((digitalRead(UpButton)==0)&&(yPosActive==false)){
    Serial.write(up);
    yPosActive=true;
  }
  if((digitalRead(UpButton)==1)&&(yPosActive==true)){
    Serial.write(upEnd);
    yPosActive=false;
  }
  
  //Down movement serial out
  if((digitalRead(DownButton)==0)&&(yNegActive==false)){
    Serial.write(down);
    yNegActive=true;
  }
    if((digitalRead(DownButton)==1)&&(yNegActive==true)){
    Serial.write(downEnd);
    yNegActive=false;
  }
  
  //Left movement serial out
  if((digitalRead(LeftButton)==0)&&(xNegActive==false)){
    Serial.write(left);
    xNegActive=true;
  }
  if((digitalRead(LeftButton)==1)&&(xNegActive==true)){
    Serial.write(leftEnd);
    xNegActive=false;
  }
  
  //Right movement serial out
  if((digitalRead(RightButton)==0)&&(xPosActive==false)){
    Serial.write(right);
    xPosActive=true;
  }
  if((digitalRead(RightButton)==1)&&(xPosActive==true)){
    Serial.write(rightEnd);
    xPosActive=false;
  }
  
  delay(50);
  
}

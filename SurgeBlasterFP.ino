//this will go over every lit pixel
#include <Adafruit_NeoPixel.h>
#include<Wire.h>
const int MPU=0x68; 
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
int pixelNum = 64;
int pixelPin = 13;
Adafruit_NeoPixel strip(pixelNum, pixelPin);
int state=3;

int buttonPin=12;
boolean buttonState = false;
boolean prevButtonState = false;














void setup() {
  // put your setup code here, to run once:
   Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
  strip.begin();

AcX=0;
  Serial.begin(9600);
strip.clear();
strip.show();
state=3;


}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);  
  AcX=Wire.read()<<8|Wire.read();    
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read();  
  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read();  
   Serial.println(state);
  Serial.println(AcX);




if(AcX>15000){
  strip.clear();
  state--;
  delay(750);
  
  Serial.println(state);
  Serial.println(AcX);
}


buttonState= digitalRead(buttonPin);
  //Serial.println(buttonStateOne);
//  Serial.println(swapState);

  buttonState = debounce(buttonPin, prevButtonState);

  if (buttonState == HIGH && prevButtonState == LOW) {
    strip.clear();
    state++;
    Serial.println("Button Pressed");
  }



//if(AcX<=15000){
//strip.clear();
//state++;
//delay(750);
//}

if(state==-1){
  state=0;
}

if(state==4){
  state=3;
}



  

switch (state){



case 0:

for (int i=16; i<strip.numPixels(); i++){

strip.setPixelColor(i,0,200,155);//Surge Blue
//strip.setBrightness(50);
//strip.show();
  
}

strip.setPixelColor(0,255,75,0);//Ammo orange
strip.setPixelColor(1,255,75,0);
strip.setPixelColor(3,255,75,0);
strip.setPixelColor(4,255,75,0);
strip.setPixelColor(6,255,75,0);
strip.setPixelColor(7,255,75,0);
strip.setPixelColor(8,255,75,0);
strip.setPixelColor(9,255,75,0);
strip.setPixelColor(11,255,75,0);
strip.setPixelColor(12,255,75,0);
strip.setPixelColor(14,255,75,0);
strip.setPixelColor(15,255,75,0);
strip.setBrightness(5);
strip.show();
break;

case 1:

for (int i=16; i<strip.numPixels()-16; i++){
strip.setPixelColor(i,0,200,155);//Surge Blue
//strip.setBrightness(100);
//strip.show();
}

strip.setPixelColor(0,255,75,0);//Ammo orange
strip.setPixelColor(1,255,75,0);
strip.setPixelColor(3,255,75,0);
strip.setPixelColor(4,255,75,0);
//strip.setPixelColor(6,255,75,0);
//strip.setPixelColor(7,255,75,0);
//strip.setPixelColor(8,255,75,0);
//strip.setPixelColor(9,255,75,0);
strip.setPixelColor(11,255,75,0);
strip.setPixelColor(12,255,75,0);
strip.setPixelColor(14,255,75,0);
strip.setPixelColor(15,255,75,0);
strip.setBrightness(5);
strip.show();
break;


case 2:

for (int i=16; i<strip.numPixels()-32; i++){
strip.setPixelColor(i,0,200,155);//Surge Blue
//strip.setBrightness(100);
//strip.show();
}

strip.setPixelColor(0,255,75,0);//Ammo orange
strip.setPixelColor(1,255,75,0);
//strip.setPixelColor(3,255,75,0);
//strip.setPixelColor(4,255,75,0);
//strip.setPixelColor(6,255,75,0);
//strip.setPixelColor(7,255,75,0);
//strip.setPixelColor(8,255,75,0);
//strip.setPixelColor(9,255,75,0);
//strip.setPixelColor(11,255,75,0);
//strip.setPixelColor(12,255,75,0);
strip.setPixelColor(14,255,75,0);
strip.setPixelColor(15,255,75,0);
strip.setBrightness(5);
strip.show();
break;

case 3:

for (int i=16; i<strip.numPixels()-40; i++){
strip.setPixelColor(i,0,200,155);//Surge Blue
//strip.setBrightness(100);
//strip.show();
}

//strip.setPixelColor(0,255,75,0);//Ammo orange
//strip.setPixelColor(1,255,75,0);
//strip.setPixelColor(3,255,75,0);
//strip.setPixelColor(4,255,75,0);
//strip.setPixelColor(6,255,75,0);
//strip.setPixelColor(7,255,75,0);
//strip.setPixelColor(8,255,75,0);
//strip.setPixelColor(9,255,75,0);
//strip.setPixelColor(11,255,75,0);
//strip.setPixelColor(12,255,75,0);
//strip.setPixelColor(14,255,75,0);
//strip.setPixelColor(15,255,75,0);
strip.setBrightness(5);
strip.show();
break;


















  }//end of switch state

}//end of loop


boolean debounce(int aButPin, boolean aPrevState) {
  // get the bouncy reading of the button
  boolean aButtonState = digitalRead(aButPin);

  // if the button state is different from what it
  // was last frame, then delay so it doesn't read
  // while the button is bouncing
  if (aButtonState != aPrevState) {
    delay(150);
  }

  return aButtonState;
}

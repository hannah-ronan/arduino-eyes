//Hannah Ronan
//December 10, 2020
//This program controls a set of animatronic eyes using 2 servos which affect the left/right and up/down movement of the eyes
//


#include <Servo.h>
Servo xServo;
Servo yServo;
int xPot = A0;//The potentiometer for the x axis is on analog pin 0
int yPot = A1;//The potentiometer for the y axis is on analog pin 1
int xVal = 0;//This will hold the desired x position of the x servo
int yVal = 0;//This will hold the desired y position of the y servo
int buttonPin = 12;

void setup() {
  // put your setup code here, to run once:
xServo.attach(6);
yServo.attach(5);
pinMode(xPot, INPUT);
pinMode(yPot, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
xVal = analogRead(xPot); //Read the value from the potentiometer and store it in the xVal variable.
xVal = map(xVal,1023,0,50,120); //Map the value to an angle between 50 and 120 degrees, this is the range of rotation for the left and right movement of the eyes
yVal = analogRead(yPot); //Read the value from the potentiometer and store it in the yVal variable.
yVal = map(yVal,1023,0,30,120); //Map the value to an angle between 30 and 120 degrees, this is the range of rotation for the up and down movement of the eyes
xServo.write(xVal);//write to the servo using the mapped angle for the x axis
yServo.write(yVal);//write to the servo using the mapped angle for the y axis

if (digitalRead(buttonPin)== HIGH) {
  eyeMove();
  }
}


void eyeMove() {
  //A preset sequence of eye movements that plays when the button is pressed
  xServo.write(80);//move the xservo to the default position, facing forwards
  yServo.write(80);//move the yservo to the default position, facing forwards
  delay (500);
  int y = 80;
  for (int x=50; x<120;x++) {
    //roll the eyes 
      if (x>80){
        y= y+2;
       }
       else {
        y=y-2;
        }
       Serial.print("x=");
       Serial.println(x);
       Serial.print("y=");
       Serial.println(y);
      yServo.write(y);
      xServo.write(x);
      delay (7);
    }
  y=80;
  for (int x=120; x>50;x--) {
    //roll the eyes downward
      if (x<80){
        y= y-1;
       }
       else {
        y=y+1;
        }
       Serial.print("x=");
       Serial.println(x);
       Serial.print("y=");
       Serial.println(y);
      yServo.write(y);
      xServo.write(x);
      delay (7);
    }
    yServo.write(80);
    xServo.write(50);
    delay(300);
    for (int x=50; x<120;x++) {
      //move the eyes from left to right
      xServo.write(x);
      delay (7);
      }
      delay(300);
    for (int x=120; x>50;x--) {
      //move the eyes from right to left
      xServo.write(x);
      delay (7);
      }
      delay(300);     
  xServo.write(80);//move the xservo to the default position, facing forwards
  yServo.write(80);//move the yservo to the default position, facing forwards
  delay (500);
  }

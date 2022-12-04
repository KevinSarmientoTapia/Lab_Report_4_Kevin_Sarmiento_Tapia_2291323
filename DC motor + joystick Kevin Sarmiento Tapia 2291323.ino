
/*
 DC motor + joystick

 The program's goal is controling the speed and the direccion of a dc motor with a joystick.

 The theme is the use of the motor pins to control it.
*/

int x = A0; // pin x of the joystick connected to analog pin
int Motor_1_A=5 // motor part A to pin 5
int Motor_1_B=4 // motor part B to pin 4
int speed=6 //speed to pin 6

void setup() // this program will run once
{
  // all pins defined as outputs
  pinMode(Motor_1_A,OUTPUT); 
  pinMode(Motor_1_B,OUTPUT);
  pinMode(speed,OUTPUT);
}
void loop() // this program will run forever
{
  analogRead(x); //analog read reads the position of the pin x in the joystick
  if(x >= 1019){ 
    // if the position is greater or equal to 1019, set the speed to 255 and move counterclockwise 
    analogWrite(speed,255); 
    digitalWrite(Motor_1_A, 0); 
    digitalWrite(Motor_1_B, 1);
    }
  if(950<x<1019){
    // if the position is between 950 and 1019, set the speed to 200 and move counterclockwise 
    analogWrite(speed,200); 
    digitalWrite(Motor_1_A, 0); 
    digitalWrite(Motor_1_B, 1);
    }
  if(800<x<950){
    // if the position is between 800 and 950, set the speed to 180 and move counterclockwise 
    analogWrite(speed,180); 
    digitalWrite(Motor_1_A, 0); 
    digitalWrite(Motor_1_B, 1);
    }
  if(712<x<800){
    // if the position is between 712 and 800, set the speed to 128 and move counterclockwise 
    analogWrite(speed,128); 
    digitalWrite(Motor_1_A, 0); 
    digitalWrite(Motor_1_B, 1);
    }
  if(600<x<712){
    // if the position is between 600 and 712, set the speed to 80 and move counterclockwise 
    analogWrite(speed,80); 
    digitalWrite(Motor_1_A, 0); 
    digitalWrite(Motor_1_B, 1);
    }    
  if(500<x<600){
    // if the position is between 500 and 600, stop 
    analogWrite(speed,0); 
    digitalWrite(Motor_1_A, 0); 
    digitalWrite(Motor_1_B, 1);
    }
  if(390<x<500){
    // if the position is between 390 and 500, set the speed to 80 and move clockwise 
    analogWrite(speed,80); 
    digitalWrite(Motor_1_A, 1); 
    digitalWrite(Motor_1_B, 0);
    }   
  if(220<x<390){
    // if the position is between 220 and 390, set the speed to 128 and move clockwise 
    analogWrite(speed,128); 
    digitalWrite(Motor_1_A, 1); 
    digitalWrite(Motor_1_B, 0);
    } 
  if(100<x<220){
    // if the position is between 100 and 220, set the speed to 180 and move clockwise 
    analogWrite(speed,180); 
    digitalWrite(Motor_1_A, 1); 
    digitalWrite(Motor_1_B, 0);
    }
  if(25<x<100){
    // if the position is between 25 and 100, set the speed to 200 and move clockwise 
    analogWrite(speed,200); 
    digitalWrite(Motor_1_A, 1); 
    digitalWrite(Motor_1_B, 0);
    }
  if(x <= 20){
    // if the position is minor or equal to 20 , set the speed to 255 and move clockwise 
    analogWrite(speed,255); 
    digitalWrite(Motor_1_A, 1); 
    digitalWrite(Motor_1_B, 0);
    }
}
  
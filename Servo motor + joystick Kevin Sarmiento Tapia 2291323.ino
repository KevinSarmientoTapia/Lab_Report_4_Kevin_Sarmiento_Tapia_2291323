/*
 Servo motor + joystick

 The program's goal is controlling the position of the servo motor using a joystick.

 The theme is the use of "map" to scale the values from the joystick to the angles of the position of the servo motor.
*/
#include <Servo.h> // includes the library Servo motor to program the servo motor.

Servo myservo; // create servo object to control a servo

int Potpinx = A0; // x pin of joystick connected to analog pin 

void setup() { // this program runs once
  myservo.attach(7); // sets the pin of the servo to pin 7
}

void loop() { // this program runs forever
  int val = analogRead(Potpinx); // analog pin stores the value of Potpinx in a variable called "val"      
  val = map(val, 0, 1023, 0, 180); //  converts the values of "val" from 0-1023 to 0-180 to change the position of the servo based on the position of the joystick
  myservo.write(val); // sets the postion of the servo based on the value of val.              
  delay(15); // waits for the servo to get to its position                        
}

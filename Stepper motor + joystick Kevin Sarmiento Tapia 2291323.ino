/*
 Stepper motor + joystick

 The program's goal is to control the stepper motor's position using a joystick.

 the theme is the use of the library "#include <Stepper.h>" to program the stepper motor.
*/
int potpinx = A0; // joystick pin x will be Analog Input 0

#include <Stepper.h> // includes the library Stepper.h

const float STEPS_PER_REV = 32; // Number of steps per internal motor revolution

int StepsRequired; // number of Steps Required

Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 11); // Create Instance of Stepper Class and specifies pins used for motor coils (8, 9, 10, 11)

void setup() // this program will run once
{
  Serial.begin(9600); //the serial monitor starts
}

void loop() // this program will run forever
{
  int value = analogRead(potpinx); // value will have the value of the reading of joystick pin x
  steppermotor.setSpeed(700); // stepper motor speed to 700
  Serial.println(value); // serial monitor prints the value of variable "value"
  if (50<value<900){ // if the value is less than 50 and more than 900, the stepper motor will not move
  StepsRequired  =  0;
  steppermotor.step(StepsRequired);
  }
  else if (value>900){ // else if the value is higher than 900, the stepper motor will move backwards
  StepsRequired  =  -1;
  steppermotor.step(StepsRequired);
  }
  else if (value<50){ // else if the value is lower than 50, the stepper motor will move forward
  StepsRequired  =  +1;
  steppermotor.step(StepsRequired);
  } 
}

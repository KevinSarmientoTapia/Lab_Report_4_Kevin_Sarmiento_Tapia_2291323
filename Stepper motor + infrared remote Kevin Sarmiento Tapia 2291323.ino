/*
 Stepper motor + infrared remote Kevin

 The program's goal is to control the direction, position and speed of the stepper motor with the infrared remote (IR).

 The program's theme is the use of the libraries  of the Stepper motor and the IR to be able to program them.
*/
#include <Stepper.h> // includes the library Stepper.h

const float STEPS_PER_REV = 32; // Number of steps per internal motor revolution

int StepsRequired; // number of Steps Required

Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 11); // Create Instance of Stepper Class and specifies pins used for motor coils (8, 9, 10, 11)

#include <IRremote.h> // inlcudes the Infrared remote library
 
const int RECV_PIN = 6; // define sensor pin

IRrecv irrecv(RECV_PIN); // Define IR Receiver
decode_results results; // define IR Results Objects

unsigned long speed=500; // define the inicial speed to 500

void setup() // this program will run once
{ 
  irrecv.enableIRIn(); // starts the infrared remote
}

void loop() // this program will run forever
{
if (irrecv.decode(&results)){ // if one of the IR buttons are pressed, then:
       if(results.value == 0xFF30CF){ // if the button 1 is pressed, the speed increases to the maximum
        speed=700; 
       }
       if(results.value == 0xFF18E7){ // if the button 2 is pressed, the speed goes back to 500
        speed=500;  
       }
       if(results.value == 0xFF7A85){ // if the button 1 is pressed, the speed decreases to 300
        speed=300;  
       }
        if(results.value == 0xFF629D){ // if vol+ is pressed, then:
          steppermotor.setSpeed(speed); // stepper motor speed sets to the defined speed
          steppermotor.step(2048); // stepper motor makes a full turn (360) to the right
          delay(2000); // waits 2000
          break; // breaks the loop
          }
       if(results.value == 0xFFA857){ // if vol- is pressed, then:
         steppermotor.setSpeed(speed); // stepper motor speed to the defined speed
          steppermotor.step(-2048);  // stepper motor makes a full turn (360) to the left
          delay(2000); // waits 2000
          break; // breaks the loop
       }
       if(results.value == 0xFFC23D){ // if >>| is pressed, then:
         steppermotor.setSpeed(speed); // stepper motor to the defined speed
          steppermotor.step(1024); // stepper motor makes a half turn (180) to the right
          delay(2000); // waits 2000
          break; // breaks the loop
       }
       if(results.value == 0xFF22DD){ // if |<< is pressed, then:
          steppermotor.setSpeed(speed); // stepper motor speed to the defined speed
          steppermotor.step(-1024); // stepper motor makes a half turn (180) to the left
          delay(2000); // waits 2000
          break; // breaks the loop
       }
     irrecv.resume();
}
}

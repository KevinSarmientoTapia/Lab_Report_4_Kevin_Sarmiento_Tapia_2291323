/*
 Servo motor + LDR

 The program's goal is to measure the resistance of the LDR and based on that move the position of the servomotor.

 The theme is the use of maths to measure the value of the LDR.
*/
#include <Servo.h> // Includes the library Servo motor to program the servo motor.

Servo myservo; // Creates servo object to control a servo.

float voltage_Resistor1;// Stores the value of the voltage of resistor 1 2k.
float voltage_LDR;// Stores the value of the voltage LDR.
float resistance_LDR;// Stores the value of the resitance of LDR.
float current;// Stores the value of the current.
float a=5;// Float variable named "a" with a value of 5.
float b=1023;// Float variable named "b" with a value of 1023.

void setup() {// This program will run once.
Serial.begin(9600); // Starts the serial monitor
myservo.attach(7); // Sets the pin of the servo motor.
}
void loop() {// This program will run forever.
int sensorValue = analogRead(A0);// Int variable named "sensorValue" equals the value of analogRead(A0).
voltage_LDR = sensorValue*a/b;// Calculates the voltage. 
voltage_Resistor1 = 5-voltage_LDR;// Calculates the voltage of the Resistor 2K.
current = voltage_Resistor1/2000;// Calculates the current.
resistance_LDR= voltage_LDR/current;// Calculates the resistance of the LDR.

 // Prints bit value.
Serial.print("Bit value= "); 
Serial.print(sensorValue);
Serial.print("     ");
// Prints voltage value.
Serial.print("voltage= ");
Serial.print(voltage_LDR);
Serial.print("     ");
// Prints resistance value of LDR.
Serial.print("Resistance LDR= ");
Serial.println(resistance_LDR);

int position = map(resistance_LDR, 200, 20000, 0, 180); //  Converts the values of "Resistance" from 200Ω-20000Ω to 0-180 degrees to change the position of the servo based on the resistance of LDR.
myservo.write(position); // Sets the postion of the servo based on the position.
delay(15); // waits for the servo to get to its position
}



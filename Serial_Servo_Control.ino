/* 
   Serial Servo Control 
   
   by Matthias Dietrich @ Didis Maker Industries

   This Sketch alows you to control any servo over the keyboard of your PC 
   and monitor it´s actual position. This can be helpfull for calibrating
   your servo for instance.

   V1.00 - 14/07/2018  
*/

#include <Servo.h>  // includes servo library

Servo myservo;  // create servo object to control a servo

const int servopin =  9; // constant to store desired pin which attaches the servo

String StringReceived;  // variable to store the received string from the keyboard
int pos = 90; // variable to store the servo position - this is also the starting position


void setup()
{
  myservo.attach(servopin);  // attaches the servo to the declared servopin
  Serial.begin(9600);  // sets the data rate for the serial data transmission
  Serial.println("--- Serial Servo Control ---");
  Serial.println("Servo attached on Pin " + String(servopin));
  Serial.println("Type in target position (0-180 degrees)");
  Serial.println();
  Serial.print("Actual Servo Position in degrees: " + String(pos));
  Serial.println();  
}

void loop()
{
if (Serial.available() > 0)
  {
  StringReceived = Serial.readString();  // reads the serial string
  pos = StringReceived.toInt();  // converts the serial string to integer
  if (pos <= 180 && pos >= 0)  // value of pos must be between 0 and 180
    {  
    myservo.write(pos);  // writes the servo position
    Serial.print("Actual Servo Position: " + String(pos)); // shows the actual servo position on the serial monitor 
    Serial.println();
    }
  else
    {
    Serial.print("Target position needs to be between 0 and 180 degrees");
    Serial.println();  
    }  
  }
}

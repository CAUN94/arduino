#include <Servo.h>


Servo Servo1360; // Is the same for every Servo
Servo Servo2360; // Is the same for every Servo
int Red = 4; // Specify Red Pin
int Green = 3; // Specify Green Pin
int S1360 = 2; // Specify Servo 180 Pin
int S2360 = 5; // Specify Servo 360 Pin
int spin1 = 90; // Set the rotation to null (only in full rotation servo)
int spin2 = 90; // Specify the Servo 180 start Position

void setup() {

  Servo1360.attach(S1360);
  Servo2360.attach(S2360);
  Servo1360.write(spin1);
  Servo2360.write(spin2);
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  digitalWrite(Red, LOW);
  digitalWrite(Green, LOW);
  Serial.begin(9600);

}
void loop() {

  unsigned char comando = 0; // set comando to 0

  if (Serial.available()) // if is connected to bluetooth or with Serial Monitor
  {
    comando = Serial.read(); // Read the values of Serial Communication
    if (comando == 'w')  // If read a 1
    {

      spin1 = 359; // change the value of int Spin
      Servo1360.write(spin1); // Write in the Servo 360 the value of variable spin
    }
    else if (comando == 's') // If read a 1
    {
      spin1 = 1; // change the value of int Spin
      Servo1360.write(spin1); // Write in the Servo 360 the value of variable spin
    }
    else if (comando == 'a')
    {
      spin2 = 10; // change the value of int Spin
      Servo2360.write(spin2); // Write in the Servo 360 the value of variable spin
    }
    else if (comando == 'd')
    {
      spin2 = 800; // change the value of int Spin
      Servo2360.write(spin2); // Write in the Servo 360 the value of variable spin
    }
  }
}

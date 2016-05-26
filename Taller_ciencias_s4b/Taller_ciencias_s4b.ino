#include <Servo.h>

Servo Servo180; // Add Servo attributes
Servo Servo360; // Is the same for every Servo
int Red = 4; // Specify Red Pin
int Green = 3; // Specify Green Pin
int S180 = 2; // Specify Servo 180 Pin
int S360 = 5; // Specify Servo 360 Pin
int spin = 90; // Set the rotation to null (only in full rotation servo)
int pos = 0; // Specify the Servo 180 start Position

void setup() {

  Servo180.attach(S180);
  Servo360.attach(S360);
  Servo180.write(pos);
  Servo360.write(spin);
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
    if (comando == '1')  // If read a 1
    {
      // for to make a complete rotation from 0 to 180
      for (pos = 0; pos <= 180; pos += 1) {

        Servo180.write(pos); // Write the position in the Servo
        delay(10); // delay of 0,01 second
        digitalWrite(Green, HIGH); // turn on the green led
        digitalWrite(Red, LOW); // turn off the red led
        spin = 359; // change the value of int Spin
        Servo360.write(spin); // Write in the Servo 360 the value of variable spin
      }
      digitalWrite(Green, HIGH); // turn on the green led
      digitalWrite(Red, LOW); // turno of the red led
      spin = 359; // change the value of int Spin
      Servo360.write(spin); // Write in the Servo 360 the value of variable spin
    }
    else if (comando == '2') // If read a 1
    {
      // for to make a complete rotation from 180 to 0
      for (pos = 180; pos >= 0; pos -= 1) {
        Servo180.write(pos); // Write the position in the Servo
        delay(10); // delay of 0,01 second
        digitalWrite(Green, LOW); // turn off the green led
        digitalWrite(Red, HIGH); // turno on the red led
        spin = 1; // change the value of int Spin
        Servo360.write(spin); // Write in the Servo 360 the value of variable spin
      }
      digitalWrite(Green, LOW); // turn off the green led
      digitalWrite(Red, HIGH); // turno on the red led
      spin = 1; // change the value of int Spin
      Servo360.write(spin); // Write in the Servo 360 the value of variable spin

    }
    else if (comando == '3')
    {
      pos = 90; // Set position to 90
      Servo180.write(pos); // Write in Servo 180 the value of position
      digitalWrite(Green, HIGH); // turno on the green led
      digitalWrite(Red, HIGH); // turno on the red led
      spin = 90; // Set spin to 90 (stop the servo360)
      Servo360.write(spin); // Write in the Servo 360 the value of variable spin
    }
    else if (comando == '4')
 {
      pos = 90; // Set position to 90
      Servo180.write(pos); // Write in Servo 180 the value of position
      digitalWrite(Green, LOW); // turno off the green led
      digitalWrite(Red, LOW); // turno off the red led
      spin = 90; // Set spin to 90 (stop the servo360)
      Servo360.write(spin); // Write in the Servo 360 the value of variable spin
    }
  }
}

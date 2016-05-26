#include <Ultrasonic.h>
#define pin 8

unsigned long previousmillis = 0;

Ultrasonic izq(3, 2);
Ultrasonic der(12, 10);

int pinA = A0;
int speedPinL = 11;
int speedPinR = 9;
int motor1APin = 6; //motor 1
int motor2APin = 7;
int motor3APin = 4; //motor 2
int motor4APin = 5;
int speed1 = 200;
int speed2 = 200;
int bol = 1;

void setup() {
  Serial.begin(9600);
  pinMode(speedPinR, OUTPUT);
  pinMode(speedPinL, OUTPUT);
  pinMode(motor1APin, OUTPUT);
  pinMode(motor2APin, OUTPUT);
  pinMode(motor3APin, OUTPUT);
  pinMode(motor4APin, OUTPUT);

}

void loop() {
  unsigned long currentmillis = millis();
  int value = analogRead(pinA);
  int speedT = value / 4;
  //int speedT = 255;
  int vuelta = int(value / 8);

  int distanciaIzq = izq.Ranging(CM);




  int distanciaDer = der.Ranging(CM);


  if (currentmillis - previousmillis >= 200)
  {

    if (distanciaIzq > 18)
    {
      Serial.print(1);
      Serial.print(",");
    }

    if (distanciaDer > 18)
    {
      Serial.print(2);
      Serial.print(",");
    }



    if (distanciaIzq <= 18 && distanciaIzq >= 7)
    {

      Serial.print(3);
      Serial.print(",");
    }

    if (distanciaDer <= 18 && distanciaDer >= 7)
    {

      Serial.print(4);
      Serial.print(",");

    }
    if (bol == -1)
    {
      if (distanciaIzq <= 6 )
      {

        speed1 = speedT;
        speed2 = speedT;
        digitalWrite(motor1APin, LOW);
        digitalWrite(motor2APin, LOW);
        digitalWrite(motor3APin, LOW);
        digitalWrite(motor4APin, LOW);


        delay(1000);

        digitalWrite(motor2APin, LOW);
        digitalWrite(motor1APin, HIGH);
        digitalWrite(motor4APin, LOW);
        digitalWrite(motor3APin, HIGH);

        delay(1000);
        digitalWrite(motor1APin, LOW);
        digitalWrite(motor2APin, LOW);
        digitalWrite(motor3APin, LOW);
        digitalWrite(motor4APin, LOW);
        Serial.print(5);
        Serial.print(",");

      }

      if (distanciaDer <= 6 )
      {
        speed1 = speedT;
        speed2 = speedT;
        digitalWrite(motor1APin, LOW);
        digitalWrite(motor2APin, LOW);
        digitalWrite(motor3APin, LOW);
        digitalWrite(motor4APin, LOW);


        delay(1000);

        digitalWrite(motor2APin, LOW);
        digitalWrite(motor1APin, HIGH);
        digitalWrite(motor4APin, LOW);
        digitalWrite(motor3APin, HIGH);

        delay(1000);
        digitalWrite(motor1APin, LOW);
        digitalWrite(motor2APin, LOW);
        digitalWrite(motor3APin, LOW);
        digitalWrite(motor4APin, LOW);
        Serial.print(6);
        Serial.print(",");
      }
    }

    else if ((distanciaDer <= 6 ) && bol == 1)
    {
      Serial.print(7);
      Serial.print(",");
    }

    else if ((distanciaIzq <= 6 ) && bol == 1)
    {
      Serial.print(8);
      Serial.print(",");
    }

    unsigned char comando = 0;

    comando = Serial.read();
    if (comando == 'a')
    {


      digitalWrite(motor1APin, LOW);
      digitalWrite(motor2APin, HIGH);




      //control del motor 2
      digitalWrite(motor3APin, LOW);
      digitalWrite(motor4APin, HIGH);

      speed1 = speedT;
      speed2 = speedT;






    }
    else if (comando == 'b')
    {


      digitalWrite(motor1APin, HIGH);
      digitalWrite(motor2APin, LOW);



      //control del motor 2
      digitalWrite(motor3APin, HIGH);
      digitalWrite(motor4APin, LOW);



      //Serial.println("Estas en reversa" );
      speed1 = speedT;
      speed2 = speedT;


    }


    else if (comando == 'c')
    {
      speed1 = speedT;
      speed2 = speedT;
      digitalWrite(motor1APin, LOW);
      digitalWrite(motor2APin, LOW);




      //control del motor 2
      digitalWrite(motor3APin, LOW);
      digitalWrite(motor4APin, LOW);




      // Ser

    }



    else if (comando == 'd')
    {

      speed1 = speedT;
      speed2 = vuelta;

      digitalWrite(motor1APin, LOW);
      digitalWrite(motor2APin, HIGH);



      //control del motor 2
      digitalWrite(motor3APin, LOW);
      digitalWrite(motor4APin, HIGH);





      // Serial.println("Estas detenido" );


    }

    else if (comando == 'e')
    {
      speed1 = vuelta;
      speed2 = speedT;


      digitalWrite(motor1APin, LOW);
      digitalWrite(motor2APin, HIGH);



      //control del motor 2
      digitalWrite(motor3APin, LOW);
      digitalWrite(motor4APin, HIGH);




      // Serial.println("Estas detenido" );


    }

    else if (comando == 'f')
    {

      bol = bol * (-1);

    }


    int lectura = readQD();

    if (lectura > 3000)
    {
      Serial.print(9);



    }
    else
    {
      Serial.print(10);



    }

    Serial.print("\n");


    previousmillis = currentmillis;

  }

  analogWrite(speedPinR, speed1);
  analogWrite(speedPinL, speed2);



}

int readQD() {

  pinMode( pin, OUTPUT );
  digitalWrite( pin, HIGH );
  delayMicroseconds(10);
  pinMode( pin, INPUT );

  long time = micros();

  while (digitalRead(pin) == HIGH && micros() - time < 3000);
  int diff = micros() - time;

  return diff;
}


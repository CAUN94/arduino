
// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// Rev.4 (06/2012)
// J.Rodrigo ( www.jra.so )
// more info at www.ardublog.com

#include <Ultrasonic.h>

Ultrasonic ultrasonic1(9, 8);
Ultrasonic ultrasonic2(11, 10);
int pin1 = 12;
int pin2 = 6;
int a ;
int b ;
int gente = 0;
int Bol1;
int Bol2;
char data = 0;


void setup() {

  Serial.begin(9600);
  pinMode(pin1, OUTPUT);
  digitalWrite(pin1, LOW);
  pinMode(pin2, OUTPUT);
  digitalWrite(pin2, LOW);
}

void loop()
{
  /*
    Serial.print(ultrasonic.Ranging(CM)); // CM or INC
    Serial.println(" cm" );
    delay(100);
  */
  //Serial.print(ultrasonic.Ranging(CM)); // CM or INC
  // set comando to 0


  // read the incoming byte:
  data = Serial.read();

  int u1 = ultrasonic1.Ranging(CM);
  int u2 = ultrasonic2.Ranging(CM);
  // Serial.println(a);
  if (u1 < 20 && a == 0 && b == 0 ) //Entrando 1
  {
    a = 1;
    Serial.println(u1);
    Serial.println(u2);
    Serial.println(a);
    Serial.println(b);
    Serial.println("E1");

  }
  if (u2 < 20 && a == 1 && b == 0 ) // Entrando 2
  {
    b = 1;
    Serial.println(u1);
    Serial.println(u2);
    Serial.println(a);
    Serial.println(b);
    Serial.println("E2");

    delay(1000);
  }

  if (u2 < 20 && a == 0 && b == 0 ) //Saliendo 1
  {
    a = 2;
    Serial.println(u1);
    Serial.println(u2);
    Serial.println(a);
    Serial.println(b);
    Serial.println("S1");


  }
  if (u1 < 20 && a == 2 && b == 0 ) // Saliendo 2
  {
    b = 2 ;
    Serial.println(u1);
    Serial.println(u2);
    Serial.println(a);
    Serial.println(b);
    Serial.println("S2");

    delay(1000);
  }


  if (a == 1 && b == 1)
  {
    gente = gente + 1;
    a = 0;
    b = 0;
    Serial.println(u1);
    Serial.println(u2);
    Serial.println(a);
    Serial.println(b);
    Serial.println("E");

  }
  if (a == 2 && b == 2)
  {
    gente = gente - 1;
    a = 0;
    b = 0;
    Serial.println(u1);
    Serial.println(u2);
    Serial.println(a);
    Serial.println(b);
    Serial.println("S");

  }



  if (data == 'a')
  {
    Bol1 = 1;
  }
  else if (data == 's')
  {
    Bol1 = 0;
    Serial.println(Bol1);
  }
  else if (data == 'd')
  {
    Bol2 = 1;
    Serial.println(Bol2);
  }
  else if (data == 'f')
  {
    Bol2 = 0;
    Serial.println(Bol2);
  }

  

  if (gente == 0 && Bol1 == 1)
  {
    digitalWrite(pin1, LOW);

  }
  else if (gente > 0 && Bol1 == 1)
  {
    digitalWrite(pin1, HIGH);

  }

  if (gente == 0 && Bol2 == 1 )
  {
    digitalWrite(pin2, LOW);
  }
  else if (gente > 0 && Bol2 == 1 )
  {
    digitalWrite(pin2, HIGH);
  }



}

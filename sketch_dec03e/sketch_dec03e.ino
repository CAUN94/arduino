#define pin 8


int pinR = 3;
int pinA = 4;
int speedPinL = 11;
int speedPinR = 9;
int motor1APin = 6; //motor 1
int motor2APin = 7;
int motor3APin = 4; //motor 2
int motor4APin = 5;
int speed_value_motor = 255;

void setup() {
  Serial.begin(9600);
  pinMode(speedPinR, OUTPUT);
  pinMode(speedPinL, OUTPUT);
  pinMode(motor1APin, OUTPUT);
  pinMode(motor2APin, OUTPUT);
  pinMode(motor3APin, OUTPUT);
  pinMode(motor4APin, OUTPUT);
  pinMode(pinR, OUTPUT);
  pinMode(pinA, OUTPUT);
}

void loop() {

  unsigned char comando = 0;
  if (Serial.available())
  {
    comando = Serial.read();
    if (comando == 'b')
    {


      digitalWrite(motor1APin, LOW);
      digitalWrite(motor2APin, HIGH);
      analogWrite(speedPinR, speed_value_motor);



      //control del motor 2
      digitalWrite(motor3APin, LOW);
      digitalWrite(motor4APin, HIGH);
      analogWrite(speedPinL, speed_value_motor);

      digitalWrite(pinA, HIGH);
      digitalWrite(pinR, LOW);



    }
    else if (comando == 'a')
    {


      digitalWrite(motor1APin, HIGH);
      digitalWrite(motor2APin, LOW);
      analogWrite(speedPinR, speed_value_motor);



      //control del motor 2
      digitalWrite(motor3APin, HIGH);
      digitalWrite(motor4APin, LOW);
      analogWrite(speedPinL, speed_value_motor);

      digitalWrite(pinA, LOW);
      digitalWrite(pinR, HIGH);



    }


    else if (comando == 'c')
    {


      digitalWrite(motor1APin, LOW);
      digitalWrite(motor2APin, LOW);
      analogWrite(speedPinR, speed_value_motor);



      //control del motor 2
      digitalWrite(motor4APin, LOW);
      digitalWrite(motor3APin, LOW);
      analogWrite(speedPinL, speed_value_motor);

      digitalWrite(pinA, LOW);
      digitalWrite(pinR, LOW);


    }

    else if (comando == 'd')
    {

      digitalWrite(pinA, LOW);
      digitalWrite(pinR, LOW);
      int lectura = readQD();
      if (lectura > 2000)
      {
        Serial.println("Estas sobre negro");
      }
      else
      {
        Serial.println("Estas sobre blanco");

      }
    }




  }

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

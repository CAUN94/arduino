#define pin 8


void setup() {

  Serial.begin(9600);
}

void loop() {
  int lectura = readQD();
  if (lectura > 1500)
  {

  }
  else
  {


  }

  Serial.println(lectura);
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

int numero;
void setup() {
  Serial.begin(9600); //comienza comunicacion serial
}

void loop() {
  
  numero=analogRead(A0); //lee un dato del puerto analogo cero
  Serial.write(numero); //envía el numero

}

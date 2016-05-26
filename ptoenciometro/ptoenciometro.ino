int pinA = A0;
void setup() {
  Serial.begin(9600); 
}
void loop() {
 
  
  int value = analogRead(pinA); 
  
   Serial.print(value / 4); 
   Serial.print(" ");
   int vuelta=int(value/5);
   Serial.println(vuelta);
}

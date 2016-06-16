int conta=1;
int demora=1000;
int leds[3] = {2,4,7};
int buttones[3] = {3,5,9};
int u;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT);
  pinMode(7, OUTPUT);
  pinMode(9, INPUT);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(9, HIGH);
  Serial.begin(9600);
}

void loop() {
u = rand()%3+0;
int led = leds[u];
int button = buttones[u];  
digitalWrite(led, HIGH); //se prende la ampolleta
  while (digitalRead(led)== HIGH){
  if (digitalRead(button)== LOW) { //si el boton es presionado se debe apagar la ampolleta y "decir": BIEN
    digitalWrite(led, LOW);
    Serial.println("BIEN");
    Serial.println(conta);
    conta++;
    delay(demora);
    demora=demora-50;
  }
   else {
    delay(demora);
    digitalWrite(led, LOW); }//se apaga la ampolleta
  }

while(digitalRead(led)== LOW){
      if (digitalRead(button)==LOW){
      Serial.println("MAL");
      Serial.println(conta);
      conta--;
      }
    }
  
  }

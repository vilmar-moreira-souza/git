//vilmar moreira de souza
// ligação de rele 5v 
int relay = 2;

void setup() { 
  pinMode(relay, OUTPUT); // rele como saida
  Serial.begin(9600); // Abre monitor serial
}

void loop() {  
  digitalWrite(relay, HIGH); // liga rele
  Serial.println("Rele ligado");
  delay(2000);           // 2 segundo  
  digitalWrite(relay, LOW);  // desliga rele
  Serial.println("Rele desligado");
  delay(2000);           // 2 segundo

}

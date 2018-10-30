//https://br-arduino.org/2016/03/arduino-triac-dimmer.html
// dimmer amanhercer artificial

#include <Ethernet.h> // no meu caso estou usando ethernet shield , PODE REIRAR
#define PINO_ZC 2 // isso nao esta fazendo nada , estava no codigo original, PODE RETIRAR
#define PINO_DIM 9

volatile long luminosidade = 0;  // 0 a 100 
 
void zeroCross()  {
  if (luminosidade>100) luminosidade=100;
  if (luminosidade<0) luminosidade=0;
  long t1 = 8200L * (100L - luminosidade) / 100L;      
  delayMicroseconds(t1);   
  digitalWrite(PINO_DIM, HIGH);  
  delayMicroseconds(6);      // t2
  digitalWrite(PINO_DIM, LOW);   
}
 
void setup() {
  pinMode(PINO_DIM, OUTPUT);
  attachInterrupt(0, zeroCross, RISING);// chama a funçao zerocross quando mudar de estado high-low
}
 
void loop() {
  for (byte i=20; i<95; i++) {
    luminosidade=i;
    delay(150);  //esse delay e muito importante   
  }
  delay(1000);
}

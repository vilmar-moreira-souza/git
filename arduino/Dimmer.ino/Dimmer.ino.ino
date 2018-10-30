// vilmar m. de souza  

//https://br-arduino.org/2016/03/arduino-triac-dimmer.html
//https://www.youtube.com/watch?v=sYMe6ljAaSU&t=140s&index=8&list=PLkN0CRUJb-IyOldd8d1ceWMh8JRvvzlLT
// acende uma lampada  em 20% e depois em 9%
#include <Ethernet.h>
#define dimmer 9 //controle de disparo do triac
volatile long lum =0;  //intensiadade de luminosidade de a 100%
// interrupção
void zerocross(){
   if(lum > 100) lum = 100 ;
   if(lum < 0 ) lum = 0 ;
   long t1 = 8200L * (100L - lum)/ 100L;
   delayMicroseconds (t1);
   digitalWrite(dimmer,HIGH);
   delayMicroseconds (6);
   digitalWrite(dimmer,LOW);
}
//
void setup() { // configura a saida para disparo do triac
   pinMode(dimmer, OUTPUT);// UTILIZA INTO- DIGITAL 2 DO ARDUINO
   attachInterrupt(0, zerocross, RISING); // chama a função zerocross na borda de subida 
}
void loop() {
   //lum = analogRead(A0);//le potenciometro
   //lum = map(lum, 0, 1023, 10, 90); // ajusta range de 0 a 100
   for (byte i=20; i<50; i++) {
     lum = 20;
     delay(150)// isso e importante;     
  }   
   lum = 90;
   delay(1500);
}

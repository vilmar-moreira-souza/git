
//controle dimmer via arduino e app android
// vilmar m. de souza  
//controla carga com dimmer
//BIBLIOTECAS
#include <SPI.h>  
#include <Ethernet.h> 
//VARIAVEIS
#define dimmer 9 //controle de disparo do triac
volatile long lum =0;  //intensiadade de luminosidade de 0 a 100%
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };// mac adress 
byte ip[] = { 192, 168, 0, 140 };// ip disponivel     
EthernetServer server(80);//porta 80 padrao  
String readString;
// INTERRUPÇAO
void zerocross(){
   if(lum > 100) lum = 100 ;
   if(lum < 0 ) lum = 0 ;
   long t1 = 8200L * (100L - lum)/ 100L;
   delayMicroseconds (t1);
   digitalWrite(dimmer,HIGH);
   delayMicroseconds (6);
   digitalWrite(dimmer,LOW);
}
//INICIA CONFIGURAÇOES
void setup(){  
   Ethernet.begin(mac, ip); //inicia ethernet
   server.begin();
   pinMode(dimmer, OUTPUT);// UTILIZA INTO- DIGITAL 2 DO ARDUINO
   attachInterrupt(0, zerocross, RISING); // chama a função zerocross na borda de subida
}
// LOOP  
void loop(){
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read(); //c recebe leitura do cliente(navegador)  
        if (readString.length() < 100) { // maximo 100 caracteres
          readString += c;      // string recebe c       
        } 
        if (c == '\n') {
          client.println("HTTP/1.1 200 OK");  //definição do padrao http 
          client.println("Content-Type: text/html"); //definição da linguaguem
          client.println();           
          client.println("<HTML>");
          client.println("<BODY>");
          client.println("<H1>Aciona rele serial</H1>");
          client.println("<hr />"); //lihna no navegador
          client.println("<br />");           
          client.println("<a href='?on'>Ligar a carga</a>"); //metodo get ligar
          client.println("<a href='?off'>Desligar a carga</a> <br/>");         //metodo get desligar
          client.println("<a href='?on20'>Ligar a carga com 20%</a> <br/>"); //metodo get ligar 20%
          client.println("<a href='?on40'>Ligar a carga com 40%</a> <br/>"); //metodo get ligar 40%
          client.println("<a href='?on60'>Ligar a carga com 60%</a> <br/>"); //metodo get ligar 60%
          client.println("<a href='?on80'>Ligar a carga com 80%</a>"); //metodo get ligar 80%
          client.println("</BODY>");
          client.println("</HTML>");           
          delay(1);
          client.stop();           
          if(readString.indexOf("?on") > 0)
          {
            lum = 95;   // liga a carga com 95%
          }          
            if(readString.indexOf("?off") > 0)
            {
              lum = 0;   // liga a carga com 0%  
            }
            //20%            
            if(readString.indexOf("?on20") > 0)
            {
              lum = 20;   // liga a carga com 20%  
            }
            // 40%            
            if(readString.indexOf("?on40") > 0)
            {
              lum = 40;   // liga a carga com 40%  
            }
            //60%            
            if(readString.indexOf("?on60") > 0)
            {
              lum = 60;   // liga a carga com 60%  
            }
            // 80%
            else {
            if(readString.indexOf("?on80") > 0)
            {
              lum = 80;   // liga a carga com 80%  
            }
            
          }
          readString="";    
        }
      }
    }
  }
}

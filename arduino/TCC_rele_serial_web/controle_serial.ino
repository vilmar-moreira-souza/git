
//controle serial de reles via arduino e app android
// vilmar m. de souza  
//ligar rele serial


#include <SPI.h>  // serial
#include <Ethernet.h> //
#include <SerialRelay.h>
//
const byte NumModules = 1;
SerialRelay relays(4,5,NumModules); // (data, clock, number of modules)
//  
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };// mac adress 
byte ip[] = { 192, 168, 0, 140 };// ip disponivel     
EthernetServer server(80);//porta 80 padrao  
String readString;
 // 
void setup(){  
    Ethernet.begin(mac, ip); //inicia ethernet
  server.begin();
}
//  
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
          client.println("Content-Type: text/html"); //drfinição da linguaguem
          client.println();
           
          client.println("<HTML>");
          client.println("<BODY>");
          client.println("<H1>Aciona rele serial</H1>");
          client.println("<hr />"); //lihna no navrgador
          client.println("<br />");           
          client.println("<a href='?on'>Ligar o led</a>"); //metodo get ligar
          client.println("<a href='?off'>Desligar o led</a><br />");         //metodo get desligar  
          client.println("</BODY>");
          client.println("</HTML>");
           
          delay(1);
          client.stop();           
          if(readString.indexOf("?on") > 0)
          {
            relays.SetRelay(1, SERIAL_RELAY_ON, 1);   // liga rele 1
          }
          else {
            if(readString.indexOf("?off") > 0)
            {
              relays.SetRelay(1, SERIAL_RELAY_OFF, 1);  // desliga rele 1
            }
          }
          readString="";    
        }
      }
    }
  }
}

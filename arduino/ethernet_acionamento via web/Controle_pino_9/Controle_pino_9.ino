// vilmar m. de souza  03/10/2018
//ligar rele ou pino 9 via web


#include <SPI.h>  
#include <Ethernet.h>
  
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };// mac adress 
byte ip[] = { 192, 168, 0, 140 };// ip disponivel
     
EthernetServer server(80);//porta 80 padrao
  
String readString;
int Pin = 9;
  
void setup(){
  
  pinMode(Pin, OUTPUT);//pino 9 como saida
  Ethernet.begin(mac, ip); //inicia ethernet
  server.begin();
}
  
void loop(){
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read(); //c recebe leitura do cliente(navegador)
  
        if (readString.length() < 100) { // maximo 100 caracteres
          readString += c;             
        }
 
        if (c == '\n') {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
           
          client.println("<HTML>");
          client.println("<BODY>");
          client.println("<H1>Acende LED</H1>");
          client.println("<hr />");
          client.println("<br />");
           
          client.println("<a href='?on'>Ligar o led</a>"); 
          client.println("<a href='?off'>Desligar o led</a><br />");   
           
          client.println("</BODY>");
          client.println("</HTML>");
           
          delay(1);
          client.stop();
           
          if(readString.indexOf("?on") > 0)
          {
            digitalWrite(Pin, HIGH);
          }
          else {
            if(readString.indexOf("?off") > 0)
            {
              digitalWrite(Pin, LOW);
            }
          }
          readString="";    
        }
      }
    }
  }
}


// vilmar m. de souza  
//ligar rele ou porta 9 via web
#include <SPI.h>  // seril
#include <Ethernet.h> //
  
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
          readString += c;      // string recebe c       
        } 
        if (c == '\n') {
          client.println("HTTP/1.1 200 OK");  //definição do padrao http 
          client.println("Content-Type: text/html"); //definição da linguaguem
          client.println();
           
          client.println("<HTML>");
          client.println("<BODY>");
          client.println("<H1>Aciona porta 9</H1>");
          client.println("<hr />"); //lina no navrgador
          client.println("<br />");           
          client.println("<a href='?on'>Ligar o led</a>"); //metodo get ligar
          client.println("<a href='?off'>Desligar o led</a><br />"); //metodo get desligar          
          client.println("</BODY>");
          client.println("</HTML>");
           
          delay(1);
          client.stop();           
          //testa a condição e liga/desliga
          if(readString.indexOf("?on") > 0)//liga
          {
            digitalWrite(Pin, HIGH);
          }
          else {
            if(readString.indexOf("?off") > 0)//desliga
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

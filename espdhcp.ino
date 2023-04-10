#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

bool ledStatus = false;
#include "pagina.h"

const char* ssid = "pppp";
const char* password = "darksouls9TM";
ESP8266WebServer server(300);

void requisicao(String);

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, !ledStatus);

  Serial.println("");
  Serial.println("");
  Serial.print("Conectando...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Conectado à rede: ");
  Serial.println(ssid);
  server.begin();
  Serial.println("Server Iniciado");

  Serial.print("IP:");
  Serial.print("http://");
  Serial.println(WiFi.localIP());
}

void loop(){
  WiFiClient client = server.client();
  if (!client) {
    return;
  }

  Serial.println("Novo Cliente");
  while(!client.available()) {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  requisicao(request);
  client.flush();
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println(pagina);

  //itens html   

  client.println("<section>");
  client.println("<div class='item-head'>");
  client.println("<div class='titulo'>LED AZUL</div>");
  if (!ledStatus) {
    client.println("<div class='estado on'>on</div>");
  }
  client.println("</div>");
  client.println("<div class='acoes'>");
  client.println("<a href='/LED=ON' class-'ligar'>ligar</a>");
  client.println("<a href='/LED=ON' class-'desligar'>desligar</a>");
  client.println("</div>");
  client.println("<section>");
  //itens finalizados

  //rodape
  client.println(rodape);
  delay(1);  
  Serial.println("Desconectado");
  Serial.println("");
}

void requisicao(String request) {
  if(request.indexOf("/LED=ON") != -1) {
    ledStatus = true;
    digitalWrite(LED_BUILTIN, ledStatus);    
  }
  if(request.indexOf("/LED=OFF") != -1) {
    ledStatus = false;
    digitalWrite(LED_BUILTIN, ledStatus);
  }
}

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#ifndef STASSID
#define STASSID "your-ssid"
#define STAPSK "my%40password"
#endif

const char* ssid = "deathsdance";
const char* password = "darksouls9TM@";
const char* host = "192.168.0.27"; // replace with your static IP address

ESP8266WebServer server(80);
#define led D2
bool ledStatus = false;

void handleRequest(String);

#include "pagina.h"

void handleRequest(String request) {
  if (request.indexOf("/LED=ON") != -1) {
    ledStatus = true;
    digitalWrite(led, ledStatus);
  }
  if (request.indexOf("/LED=OFF") != -1) {
    ledStatus = false;
    digitalWrite(led, !ledStatus);
  }
}

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(led, OUTPUT);
  digitalWrite(led, ledStatus);

  Serial.println("");
  Serial.println("");
  Serial.print("Connecting to WiFi ");
  Serial.print(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected! ");
  Serial.println(ssid);

  if (!MDNS.begin(host)) {
    Serial.println("Error setting up MDNS responder!");
  } else {
    Serial.println("MDNS responder started");
    MDNS.addService("http", "tcp", 80);
  }

  server.begin();
  Serial.println("Server started");

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  MDNS.update();
  WiFiClient client = server.client();
  if (!client) {
    return;
  }

  String request = client.readStringUntil('\r');
  handleRequest(request);
  Serial.println(request);
  client.flush();
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println(pagina);

  client.println("<section>");
  client.println("<div class='item-head'>");
  client.println("<div class='titulo'>LED 1</div>");
  ledStatus ? client.println("<div class='estado on'>on</div>") : client.println("<div class='estado off'>off</div>");
  client.println("</div>");
  client.println("<div class='acoes'>");
  client.println("<a href='/LED=ON' class='ligar'>ligar</a>");
  client.println("<a href='/LED=OFF' class='desligar'>desligar</a>");
  client.println("</div>");
  client.println("</section>");

  client.println(rodape);
  delay(1);
  client.stop();
  Serial.println("Client disconnected");
  Serial.println("");
}

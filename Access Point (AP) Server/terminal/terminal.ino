#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

const char* ssid = "NodeMCU ESP8266 (Mithun)";

void setup() {

  Serial.begin(115200);

  // Connecting WiFi

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, "87654321");

  Serial.print("\nAP IP address: ");
  Serial.println(WiFi.softAPIP());

  // Starting WEB-server
  server.on ( "/test", fnc );
  server.onNotFound ( html );
  server.begin();
}

void loop() {
  server.handleClient();
}

void fnc() {
  Serial.println("Example");
  server.send (200, "<!DOCTYPE HTML>");
}

void html() {
  server.send (200, "<!DOCTYPE HTML>");
  if (server.hasArg("m2n")) {
    String str = server.arg("m2n");
    Serial.println(str);
  }
}

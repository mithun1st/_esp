//input this link on browser
//  http://192.168.4.1/?m2n=on
//  http://192.168.4.1/?m2n=off

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

const char* ssid = "NodeMCU ESP8266 (Mithun)";

void setup() {

  pinMode(D4, OUTPUT);
  Serial.begin(115200);

  // Connecting WiFi

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, "87654321");

  Serial.print("\nAP IP address: ");
  Serial.println(WiFi.softAPIP());

  // Starting WEB-server
  server.on ( "/", HTTP_handleRoot );
  server.onNotFound ( HTTP_handleRoot );
  server.begin();
}

void loop() {
  server.handleClient();
  if (!server.hasArg("m2n")) {
    return;
  }
  String str = server.arg("m2n");
  Serial.println(str);

  if (str == "on") {
    digitalWrite(D4, 1);
  }
  else if (str == "off") {
    digitalWrite(D4, 0);
  }

}

void HTTP_handleRoot(void) {
  server.send (200, "<html>");
  server.send (200, "<h>Mahadi Hassan</h>");
  server.send (200, "</html>");
}

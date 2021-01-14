#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#define led1 D0
#define led2 D4

ESP8266WebServer server(80);

const char* ssid = "NodeMCU ESP8266 (Mithun)";

String str = "";

void setup() {

  Serial.begin(115200);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

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
  if (!server.hasArg("m2n") || str == server.arg("m2n")) {
    return;
  }
  str = server.arg("m2n");
  Serial.println(">> " + str);

  if (str == "@i1" || str == "@m1") {
    digitalWrite(led1, 1);
  }
  else if (str == "@i0" || str == "@m0") {
    digitalWrite(led1, 0);
  }
  else if (str == "@j1" || str == "@n1") {
    digitalWrite(led2, 1);
  }
  else if (str == "@j0" || str == "@n0") {
    digitalWrite(led2, 0);
  }

  else if (str == "@k1" || str == "off") {
    digitalWrite(led1, 1);
    digitalWrite(led2, 1);
  }
  else if (str == "@k0" || str == "on") {
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
  }

  else if (str == "@l0") {
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
  }
  //-------------
  else if (str == "@uu") {
    digitalWrite(led1, 0);
  }
  else if (str == "@dd") {
    digitalWrite(led1, 0);
  }
  else if (str == "@ll") {
    digitalWrite(led1, 0);
  }
  else if (str == "@rr") {
    digitalWrite(led1, 0);
  }
  else if (str == "@oo") {
    digitalWrite(led1, 1);
  }
  //----------
  else if (str == "@up") {
    digitalWrite(led2, 0);
  }
  else if (str == "@dw") {
    digitalWrite(led2, 0);
  }
  else if (str == "@lf") {
    digitalWrite(led2, 0);
  }
  else if (str == "@rg") {
    digitalWrite(led2, 0);
  }
  else if (str == "@st") {
    digitalWrite(led2, 1);
  }
  //-----------
  else if (str == "@l1") {
    digitalWrite(led1, 0);
    digitalWrite(led2, 1);
  }
  else if (str.substring(0, 2) == "@x") {
    if (str.substring(2, str.length()).toInt() <= 50) {
      digitalWrite(led1, 0);
      digitalWrite(led2, 1);
    }
    else {
      digitalWrite(led1, 1);
      digitalWrite(led2, 0);
    }
  }
  else if (str.substring(0, 2) == "@x") {
    if (str.substring(2, str.length()).toInt() <= 50) {
      digitalWrite(led1, 0);
      digitalWrite(led2, 1);
    }
    else {
      digitalWrite(led1, 1);
      digitalWrite(led2, 0);
    }
  }
  else if (str.substring(0, 2) == "@y") {
    if (str.substring(2, str.length()).toInt() %2 == 0) {
      digitalWrite(led1, 0);
      digitalWrite(led2, 1);
    }
    else {
      digitalWrite(led1, 1);
      digitalWrite(led2, 0);
    }
  }


}
void fnc() {
  Serial.println("Example");
  server.send (200, "<!DOCTYPE HTML>");
}

void html() {
  server.send (200, "<!DOCTYPE HTML>");
}

//input this link on browser
//  http://192.168.4.1/on
//  http://192.168.4.1/off


#include<ESP8266WiFi.h>
WiFiServer myServer(80);

void setup(){
  Serial.begin(115200);
  
  WiFi.begin("Mh Mi2N","87654321");
  Serial.println();
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println(WiFi.localIP());
  myServer.begin();
}
void loop(){
  WiFiClient client=myServer.available();
  if(!client){
    return;
  }
  String str=client.readStringUntil('\n');
  str=str.substring(5,str.length()-10);
  Serial.println(str);

  client.println("<!DOCTYPE HTML>"); 
}

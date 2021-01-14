#include <ESP8266WiFi.h>
#define LED D4

const String ssid = "Mahadi Hassan";
const String password = "mithun1st";
unsigned char status_led = 0;

int count=0;

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  // Connect to WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  Serial.print("wait ");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(". ");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started at...");
  Serial.println(WiFi.localIP());

}

void loop() {

  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Read the first line of the request
  String req = client.readStringUntil('\n');
  req = req.substring(5, req.length() - 10);
  Serial.println("\t\t>>" + req + "<");

  // Match the request
  if (req == "ledon") {
    status_led = 0;
    count++;
    digitalWrite(LED, LOW);
    Serial.println("LED OFF");
  }
  else if (req == "ledoff") {
    status_led = 1;
    count++;
    digitalWrite(LED, HIGH);
    Serial.println("LED ON");
  }

  // Return the response
  
  //----------------------------------
  client.println("<!DOCTYPE HTML>");
  client.println("<HTML>");
  client.println("<H1 style='color:blue;FONT-SIZE: 50px;'> LED CONTROL Develop By Mithun </H1>");
  client.println("<br />");

  if (status_led == 1)
    client.println("<H2> LED ON "+String(count)+"</H2>");
  else
    client.println("<H2> LED OFF "+String(count)+"</H2>");



  client.println("<a href=\"/ledon\"\"> <button style='FONT-SIZE: 50px; HEIGHT: 200px;WIDTH: 300px; 126px; Margin-right: 10px; TOP: 200px;'> LED ON </button> </a>");
  client.println("<a href=\"/ledoff\"\"> <button style='FONT-SIZE: 50px; HEIGHT: 200px; WIDTH: 300px; 126px; Margin-left: 100px; TOP: 200px;'> LED OFF </button> </a>");
  client.println("</html>");
  ////////----------

}

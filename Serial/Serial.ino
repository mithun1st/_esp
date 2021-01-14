const int led=D0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  String s="";
  while(Serial.available()){
    s+=(char)Serial.read();
    delay(5);
  }
  if(s=="on"){
    digitalWrite(led,1);
  }
  else if(s=="off"){
    digitalWrite(led,0);
  }
 
  delay(100);  
}

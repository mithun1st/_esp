

void setup() {

  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(A0, INPUT);

}

void loop() {
  int d = map (analogRead(A0), 0, 1024, 50, 200);
  digitalWrite(D0, 1);
  delay(d);
  digitalWrite(D0, 0);
  delay(d);

  digitalWrite(D1, 1);
  delay(d);
  digitalWrite(D4, 1);
  delay(d);

  digitalWrite(D4, 1);
  delay(d);
  digitalWrite(D0, 0);
  delay(d);
  digitalWrite(D1, 1);
  delay(d);
  digitalWrite(D1, 0);
  delay(d);
  digitalWrite(D4, 1);
  delay(d);
  digitalWrite(D4, 0);
  delay(d);

}

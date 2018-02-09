void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  int toneval = sensorValue * 4;
  Serial.print(sensorValue);
  Serial.print(" - ");
  Serial.println(toneval);
  tone(8, toneval, 1000);
  delay(2000);
}

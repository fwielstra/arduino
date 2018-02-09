int brightness = 0;

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  int value = (255. / 1023.) * sensorValue;
  Serial.print(sensorValue);
  Serial.print(" - ");
  Serial.println(value);
  analogWrite(9, value);
  delay(1);
}

// put your main code here, to run repeatedly:
int brightness = 0;
int fadeAmount = 5;

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  analogWrite(9, brightness);

  int state = digitalRead(2);
  
  if (state != 0) {
    brightness = brightness + fadeAmount;
  }

  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  delay(30);
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT);
}

const int BUTTON = 2;

void loop() {
  int state = digitalRead(BUTTON);
  Serial.println(state);
  digitalWrite(LED_BUILTIN, state == 0 ? LOW : HIGH);
  delay(1);
}

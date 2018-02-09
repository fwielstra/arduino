#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

String buffer;

const String border =
  "+------------------+"
  "|                  |"
  "|                  |"
  "+------------------+";
 
void blink() {
  lcd.noBacklight();
  delay(250);
  lcd.backlight();
  delay(250);
}

void setup() {
  Serial.begin(9600);
  lcd.begin(20, 4);
  lcd.noBacklight();
  delay(500);
  lcd.backlight();
  delay(500);
}

void print(String str) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(str.substring(0, 20));
  lcd.setCursor(0, 1);
  lcd.print(str.substring(20, 40));
  lcd.setCursor(0, 2);
  lcd.print(str.substring(40, 60));
  lcd.setCursor(0, 3);
  lcd.print(str.substring(60, 80));
}

void printDelayed(String str, int del) {
  delay(del);
  print(str);
}

void printGradually(String str, int del) {
  lcd.clear();
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == ' ') {
      continue; 
    }
    Serial.print(str.length() % 20);
    Serial.print(" ");
    Serial.println(floor(i / 4));
    lcd.setCursor(i % 20, floor(i / 20));
    lcd.print(str[i]);
    delay(del);
  }
}

void loop()
{
  buffer = border;
  printGradually(border, 50);

  String send = "SEND";
  for (int i = 0; i < send.length(); i++) {
    lcd.setCursor(i + 8, 1);
    lcd.print(send[i]);
    delay(250);
  }

  String noodz = "NUDES!";
  for (int i = 0; i < noodz.length(); i++) {
    lcd.setCursor(i + 7, 2);
    lcd.print(noodz[i]);
    delay(250);
  }

  delay(750);
 
  for (int i = 0; i < 5; i++) {
    blink();
  }
}


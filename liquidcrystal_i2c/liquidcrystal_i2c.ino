#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address


void setup()
{
  Serial.begin(9600);
  lcd.begin(20, 4);
// ------- Quick 3 blinks of backlight  -------------
  for(int i = 0; i< 3; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight(); // finish with backlight on  

//-------- Write characters on the display ------------------
// NOTE: Cursor Position: (CHAR, LINE) start at 0  
  lcd.setCursor(4,1);
  lcd.print("Y halo thar!");
  delay(2000);  

// Wait and then tell user they can start the Serial Monitor and type in characters to
// Display. (Set Serial Monitor option to "No Line Ending")
  lcd.clear();
  lcd.setCursor(0,0); //Start at character 0 on line 0
  lcd.print("Use Serial Mon");
  lcd.setCursor(0,1);
  lcd.print("Type to display");  


}/*--(end setup )---*/

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

void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  {
    // when characters arrive over the serial port...
    if (Serial.available()) {
      // wait a bit for the entire message to arrive
      delay(100);
      // clear the screen
      // read all the available characters
      while (Serial.available() > 0) {
        // display each character to the LCD
        String str = Serial.readString();
        print(str);
        Serial.println(str);
      }
    }
  }
}


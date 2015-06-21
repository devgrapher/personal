#include <SoftwareSerial.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display

SoftwareSerial mySerial(11,12); // RX, TX

void setup()  
{
  Serial.begin(9600);
  // set the data rate for the SoftwareSerial port
  mySerial.begin(2400);

  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
}

void loop() // run over and over
{
  String line;
  if (mySerial.available()) {
    line += mySerial.read();
  } 
  if (line.length()) {
    lcd.clear();
    lcd.print(line);
    Serial.print(line);
  }
  delay(500);
}

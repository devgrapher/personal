
/* 
 MotoPropto_LCD_TEST.pde 
 The program allows you to test the control 
 of an LCD. 
 The LCD of the shield, is shown in  
 the seconds after the program 
 
 uses the following pin 
 Pin +5 V -> Power Supply 
 Pin GND -> Power supply 
 Pin 6 - > LCD RS 
 pin 7 -> LCD Enable 
 Pin 8 -> LCD D4 
 pin 9 -> LCD D5 
 pin 10 -> LCD D6 
 pin 11 -> LCD D7 
 
 Created on 26/11/2011 
 by Hadrian Gandolfo <http://www. adrirobot.it> 
 This example code is in the public domain. 
 */

// Include the library code: 
#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(6, 7, 8, 9, 10, 11);

void setup() {
  // Set LCD 16 characters by 2 line 
  lcd.begin(16, 2);

  lcd.setCursor(0,0);    // Write first line 
  lcd.print("www.adrirobot.it");
  lcd.setCursor (4,1);   // Write second line of 
  lcd.print("LCD TEST");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print(""); // Delete row
}

void  loop ()
{
  lcd.setCursor (0,1);       // move the cursor 
  lcd.print (millis () / 1000); // show the seconds of the program 
}

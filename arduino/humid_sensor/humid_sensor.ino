#include <LiquidCrystal.h>
int sensorPin = A0;
int sensorValue = 0;
double kMaxSensorValue = 950.0;
LiquidCrystal lcd(12,11, 10, 8, 9, 7);
//LiquidCrystal lcd(6,7,8,9,10,11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  delay(1000);
  Serial.print("sensor = ");
  Serial.println(sensorValue);
  
  lcd.clear();
  lcd.print("Moisture : ");
  lcd.setCursor(11, 0);
  lcd.print(sensorValue);
  
  int humidity = (sensorValue / kMaxSensorValue) * 100;
  lcd.setCursor(0, 1);
  lcd.print(humidity);
  lcd.print("%");
}

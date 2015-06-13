#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display
SoftwareSerial mySerial(11,12); // RX, TX

const int moter1_ctrl = 2;
const int moter1 = 3;
const int moter2_ctrl = 4;
const int moter2 = 5;

const int kCodeUp = 56;
const int kCodeDown = 50;
const int kCodeLeft = 52;
const int kCodeRight = 54;
const int kCodeGrab = 67;
const int kCodeRelease = 68;
const int kRotateL = 69;
const int kRotateR = 70;
const int kCodeBtnUp = 48;

int op_m1_run = LOW;
int op_m2_run = LOW;
int op_m1_direct = HIGH;
int op_m2_direct = HIGH;
   
int last_cmd = 0;

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print("Remote Car");
  
  pinMode(moter1, OUTPUT);
  pinMode(moter1_ctrl, OUTPUT);
  pinMode(moter2, OUTPUT);
  pinMode(moter2_ctrl, OUTPUT);
  digitalWrite(moter1_ctrl, HIGH);
  digitalWrite(moter2_ctrl, HIGH);
}

String formatMotorStatus(String name, int run, int direct) {
  String str;
  str = name + ":";
  str += run == HIGH ? " ON " : " OFF";
  str += direct == HIGH ? " FWD" : " BWD";
  return str;
}

void runCommand(int cmd) {
  switch (cmd) {
  case kCodeUp:
    op_m1_run = HIGH;
    op_m1_direct = HIGH;
    break;
  case kCodeDown:
    op_m1_run = HIGH;
    op_m1_direct = LOW;
    break;
  case kCodeLeft:
    op_m2_run = HIGH;
    op_m2_direct = HIGH;
    break;
  case kCodeRight:
    op_m2_run = HIGH;
    op_m2_direct = LOW;
    break;
  case kCodeGrab:
    break;
  case kCodeRelease:
    break;
  case kRotateL:
    break;
  case kRotateR:
    break;
  case kCodeBtnUp:
    op_m1_run = LOW;
    op_m2_run = LOW;
    break;
  }
  
  digitalWrite(moter1, op_m1_run);
  digitalWrite(moter2, op_m2_run);
  digitalWrite(moter1_ctrl, op_m1_direct);
  digitalWrite(moter2_ctrl, op_m2_direct);
}

void display() {
  lcd.clear();
  lcd.print(formatMotorStatus("M1", op_m1_run, op_m1_direct));
  lcd.setCursor(0, 1);
  lcd.print(formatMotorStatus("M2", op_m2_run, op_m2_direct));
}

void commandLoop(const String& line) {
  int start = 0;
  int end = 2;
  while (end <= line.length()) {
    // Split into each command
    char buf[4] = {0,};
    line.substring(start, end).toCharArray(buf, 4);
    int cmd = atoi(buf);
    
    // Avoid command duplicated
    if (cmd != last_cmd) {
      Serial.print(cmd);
      runCommand(cmd);
      display();
    }
    
    last_cmd = cmd;
    start += 2;
    end += 2;
  }
}

void loop() { 
  String line;
  if (!mySerial.available()) {
    return;
  }

  line += mySerial.read();
  commandLoop(line);
  
  delay(50);
}

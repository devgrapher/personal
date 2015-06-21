#include <SoftwareSerial.h>

SoftwareSerial mySerial(4,5); // RX, TX

const int kDPinActivity = 2;
const int kDPinLight = 13;
const int kAPinBright = 9;

const int kBrightnessSensorBase = 1015;

void setup() {
  pinMode(kDPinLight, OUTPUT);
  pinMode(kDPinActivity, INPUT);
  pinMode(kAPinBright, INPUT);
  
  digitalWrite(kDPinLight, HIGH); // Trun off
  
  Serial.begin(9600);
  Serial.println("Start");
  mySerial.begin(9600);
  mySerial.println("Start");
}

bool needLight(int activity, int brightness) {
  // the lower the value is, the brighter.
  if (brightness < kBrightnessSensorBase) {
    // during the day
    return false;
  }
  if (activity) {
    return true;
  }
  return false;
}

void processCmd(String cmd) {
  if (cmd.equals("light on")) {
    digitalWrite(kDPinLight, LOW); // Turn on
    Serial.println("1");
  } else if (cmd.equals("light off")) {
    digitalWrite(kDPinLight, HIGH); // Turn off
    Serial.println("2");
  } else {

  }
}

// the loop function runs over and over again forever
void loop() {
  int activity = digitalRead(kDPinActivity);
  //Serial.print("activity: ");
  //Serial.println(activity);
  
  int brightness = analogRead(kAPinBright);
  //Serial.print("bright: ");
  //Serial.println(brightness);
  
  if (needLight(activity, brightness)) {
    Serial.println("turn on the light");
    digitalWrite(kDPinLight, LOW); // Turn on
  }
  
  String cmd = "";
  while (mySerial.available()) {
    char c = mySerial.read();
    cmd.concat(c);
    delay(10);
  }
  if (cmd.length() > 0) {
    processCmd(cmd);
    Serial.println(cmd);
  }
  
  if (Serial.available())
    mySerial.write(Serial.read());
}

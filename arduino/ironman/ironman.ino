const int kDPinActivity = 2;
const int kDPinLight = 13;
const int kAPinBright = 5;

const int kBrightnessSensorBase = 1010;

void setup() {
  pinMode(kDPinLight, OUTPUT);
  pinMode(kDPinActivity, INPUT);
  pinMode(kAPinBright, INPUT);
  
  digitalWrite(kDPinLight, HIGH); // Trun off
  
  Serial.begin(9600);
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

// the loop function runs over and over again forever
void loop() {
  int activity = digitalRead(kDPinActivity);
  Serial.print("activity: ");
  Serial.println(activity);
  
  int brightness = analogRead(kAPinBright);
  Serial.print("bright: ");
  Serial.println(brightness);
  
  if (needLight(activity, brightness)) {
    Serial.println("turn on the light");
    digitalWrite(kDPinLight, LOW); // Turn on
  }
  
  delay(500);
}

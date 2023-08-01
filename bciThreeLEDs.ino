char attentionData;
int RedLEDPin = 4;
int YellowLEDPin = 5;
int GreenLEDPin = 6;

void setup() {
pinMode(RedLEDPin, OUTPUT);
pinMode(YellowLEDPin, OUTPUT);
pinMode(GreenLEDPin, OUTPUT);
Serial.begin(115200);
}

void loop() {

while (Serial.available() > 0){
  attentionData = Serial.read();
}
// If attention data lower than 30 Red LED is on
if (attentionData > 0 && attentionData < 30){
  digitalWrite(RedLEDPin, HIGH);
  digitalWrite(YellowLEDPin, LOW);
}
// If attention data is between 30 and 60 Yellow LED is on
if (attentionData >= 30 && attentionData < 60){
  digitalWrite(YellowLEDPin, HIGH);
  digitalWrite(RedLEDPin, LOW);
}
// If attention data greater than 60 All LEDs blink in every 10th of a second
if (attentionData >=60 && attentionData <= 100){
  digitalWrite(RedLEDPin, HIGH);
  digitalWrite(YellowLEDPin, HIGH);
  digitalWrite(GreenLEDPin, HIGH);
  delay(100);
  digitalWrite(RedLEDPin, LOW);
  digitalWrite(YellowLEDPin, LOW);
  digitalWrite(GreenLEDPin, LOW);
  delay(100);
}
}

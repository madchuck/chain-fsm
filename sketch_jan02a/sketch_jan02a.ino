

int brightness = 0;
int fadeAmt = 5;

void setup() {
  // Initialize the digital pin as an output
  pinMode(9, OUTPUT);
}

void loop() {
  analogWrite(9, brightness);
  brightness += fadeAmt;
  if (brightness > 255) {
    brightness = 255;
    fadeAmt = -fadeAmt;
  }
  if (brightness < 0) {
    brightness = 0;
    fadeAmt = -fadeAmt;
  }
  delay(50);
}

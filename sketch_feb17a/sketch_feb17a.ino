const int SELECTOR_PINS = 2;
const int SENSOR_PINS = 2;
const int SENSORS = 4;
int sensorPins[SENSOR_PINS] = {A0, A1};
int selectorPins[SELECTOR_PINS] = {2, 3};
int sensorValues[SELECTOR_PINS * SENSOR_PINS]; // variable to store the values from the sensors

void setup() {
  for (int i = 0; i < SELECTOR_PINS; i++) {
    pinMode(selectorPins[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  int offset = 0;
  for (int sel = 0; sel < SELECTOR_PINS; sel++) {
    // Enable Selector pin
    digitalWrite(selectorPins[sel], HIGH);
    delay(10);
    for (int apin = 0; apin < SENSOR_PINS; apin++) {
      // Read the sensor value
      offset = sel*SENSOR_PINS + apin;
      if (offset > SENSORS) break;
      sensorValues[offset] = analogRead(sensorPins[apin]);
    }
    // Disable Selector pin
    digitalWrite(selectorPins[sel], LOW);
    if (offset > SENSORS) break;
  }
  Serial.print("Sensor values [");
  for(int i = 0; i < SENSORS; i++) {
    Serial.print(sensorValues[i]);
    if (i < SENSORS - 1) Serial.print(", ");
  }
  Serial.println("]");
  delay(1000);
}


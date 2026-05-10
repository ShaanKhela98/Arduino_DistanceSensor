/*
  Arduino Distance Sensor LED Bar

  Uses an ultrasonic distance sensor to measure object distance and lights
  a row of LEDs based on proximity. As an object gets closer, more LEDs turn on.

  Hardware:
  - Arduino Uno or compatible board
  - HC-SR04 ultrasonic distance sensor
  - 7 LEDs
  - 7 current-limiting resistors, typically 220 ohm
  - Breadboard and jumper wires
*/

const byte TRIG_PIN = 11;
const byte ECHO_PIN = 12;

const byte LED_PINS[] = {2, 3, 4, 5, 6, 7, 8};
const byte LED_COUNT = sizeof(LED_PINS) / sizeof(LED_PINS[0]);

// Distance thresholds in centimeters.
// LED 1 turns on at 5 cm, LED 7 turns on at 25 cm.
const int DISTANCE_THRESHOLDS_CM[] = {5, 7, 10, 15, 17, 20, 25};

const unsigned long SERIAL_BAUD_RATE = 9600;
const unsigned long SENSOR_TIMEOUT_MICROSECONDS = 30000;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  for (byte i = 0; i < LED_COUNT; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }

  Serial.begin(SERIAL_BAUD_RATE);
}

void loop() {
  int distanceCm = readDistanceCm();

  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  updateLedBar(distanceCm);
  delay(100);
}

int readDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, SENSOR_TIMEOUT_MICROSECONDS);

  if (duration == 0) {
    return -1; // No reading detected within timeout window.
  }

  // HC-SR04 formula: distance in cm = duration / 58.
  return duration / 58;
}

void updateLedBar(int distanceCm) {
  for (byte i = 0; i < LED_COUNT; i++) {
    bool shouldTurnOn = distanceCm > 0 && distanceCm <= DISTANCE_THRESHOLDS_CM[i];
    digitalWrite(LED_PINS[i], shouldTurnOn ? HIGH : LOW);
  }
}

/*
  Arduino Distance Sensor LED Meter
  ---------------------------------
  This project uses an HC-SR04 ultrasonic sensor and seven LEDs
  to create a distance-based LED indicator.

  Pin Setup:
  - Trig: Pin 11
  - Echo: Pin 12
  - LEDs: Pins 2 through 8

  Behavior:
  As an object gets closer to the ultrasonic sensor,
  more LEDs turn on based on distance thresholds.
*/

// Ultrasonic sensor pins
const int trigPin = 11;
const int echoPin = 12;

// LED pins
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;
const int led6 = 7;
const int led7 = 8;

// Distance variables
long duration = 0;
int distance = 0;

void setup() {
  // Configure ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Configure LED pins
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);

  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Send ultrasonic trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo pulse duration
  duration = pulseIn(echoPin, HIGH);

  // Convert pulse duration to distance in centimeters
  distance = (duration / 2) / 28.5;

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // LED threshold logic
  digitalWrite(led1, distance <= 5 ? HIGH : LOW);
  digitalWrite(led2, distance <= 7 ? HIGH : LOW);
  digitalWrite(led3, distance <= 10 ? HIGH : LOW);
  digitalWrite(led4, distance <= 15 ? HIGH : LOW);
  digitalWrite(led5, distance <= 17 ? HIGH : LOW);
  digitalWrite(led6, distance <= 20 ? HIGH : LOW);
  digitalWrite(led7, distance <= 25 ? HIGH : LOW);

  delay(100);
}

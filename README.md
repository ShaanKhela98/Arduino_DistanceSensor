# Arduino Distance Sensor LED Meter

A beginner-friendly Arduino project that uses an HC-SR04 ultrasonic distance sensor and seven LEDs to create a simple distance-based LED meter. As an object gets closer to the sensor, more LEDs turn on based on the measured distance.

## Project Overview

This project measures distance using an ultrasonic sensor. The Arduino sends a trigger pulse to the sensor, reads the echo response, calculates the distance, and turns LEDs on or off depending on how close an object is.

This is useful for learning:

- Arduino input and output control
- Ultrasonic distance sensing
- LED threshold logic
- Basic embedded systems wiring
- Serial Monitor debugging

## Hardware Used

| Component | Quantity | Purpose |
|---|---:|---|
| Arduino Uno or compatible board | 1 | Main microcontroller |
| HC-SR04 Ultrasonic Sensor | 1 | Measures object distance |
| LEDs | 7 | Visual distance indicator |
| Resistors, 220Ω recommended | 7 | Protects each LED |
| Breadboard | 1 | Builds the circuit without soldering |
| Jumper wires | As needed | Connects components |

## Pin Configuration

### Ultrasonic Sensor Pins

| HC-SR04 Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| Trig | 11 |
| Echo | 12 |

### LED Pins

| LED | Arduino Pin | Turns On When Distance Is |
|---|---:|---|
| LED1 | 2 | 5 cm or less |
| LED2 | 3 | 7 cm or less |
| LED3 | 4 | 10 cm or less |
| LED4 | 5 | 15 cm or less |
| LED5 | 6 | 17 cm or less |
| LED6 | 7 | 20 cm or less |
| LED7 | 8 | 25 cm or less |

## Wiring Notes

Each LED should be connected with a current-limiting resistor. A common setup is:

```text
Arduino Digital Pin -> Resistor -> LED Anode (+)
LED Cathode (-) -> GND
```

For the ultrasonic sensor:

```text
VCC  -> Arduino 5V
GND  -> Arduino GND
Trig -> Arduino Pin 11
Echo -> Arduino Pin 12
```

## How It Works

1. The Arduino sends a short pulse from pin 11 to the HC-SR04 trigger pin.
2. The ultrasonic sensor emits a sound wave.
3. The echo pin receives the reflected sound wave.
4. The Arduino calculates the distance using the pulse duration.
5. LEDs turn on based on the distance threshold.

The closer an object is to the sensor, the more LEDs activate.

## Distance Threshold Logic

The project uses distance ranges to control the LEDs:

```text
Distance <= 25 cm: LED7 turns on
Distance <= 20 cm: LED6 turns on
Distance <= 17 cm: LED5 turns on
Distance <= 15 cm: LED4 turns on
Distance <= 10 cm: LED3 turns on
Distance <= 7 cm:  LED2 turns on
Distance <= 5 cm:  LED1 turns on
```

This creates a simple LED bar-style distance indicator.

## Images

![Arduino Distance Sensor Image 1](https://user-images.githubusercontent.com/39349742/215953313-0e350e30-26fa-4c5d-9d5e-9a7d3a6d631d.png)

![Arduino Distance Sensor Image 2](https://user-images.githubusercontent.com/39349742/215957645-a16e7712-3eb4-43ec-ae3b-abefb7800bfd.png)

![Arduino Distance Sensor Image 3](https://user-images.githubusercontent.com/39349742/215957726-e2bd2448-d9be-4422-a839-3576c81ffc38.png)

## How to Run

1. Open `Ard_distanceSensor.ino` in the Arduino IDE.
2. Connect the Arduino board to your computer.
3. Select the correct board and COM port.
4. Upload the sketch.
5. Open the Serial Monitor at `9600` baud.
6. Move an object closer to or farther from the sensor and watch the LEDs respond.

## Code Summary

The Arduino sketch:

- Initializes the ultrasonic sensor on pins 11 and 12
- Initializes seven LEDs on pins 2 through 8
- Reads distance values from the HC-SR04 sensor
- Prints distance values to the Serial Monitor
- Turns LEDs on and off based on distance thresholds

## Future Improvements

- Add an LCD or OLED screen to display distance values
- Add a buzzer for close-range alerts
- Add RGB LEDs for color-coded distance feedback
- Create a 3D-printed enclosure
- Add calibration settings for different environments
- Convert the project into an obstacle detection system

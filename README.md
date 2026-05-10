# Arduino Distance Sensor LED Bar

An Arduino project that uses an ultrasonic distance sensor to measure nearby objects and display proximity using a 7-LED bar indicator. As an object moves closer to the sensor, more LEDs turn on to provide a simple visual distance warning system.

## Project Overview

This project demonstrates basic embedded systems concepts using Arduino, including digital input/output, ultrasonic sensing, serial monitoring, and threshold-based control logic. It is a good starter project for learning how hardware sensors can drive real-time visual feedback.

## Features

- Measures distance using an ultrasonic sensor
- Displays proximity through 7 LEDs
- Prints live distance readings to the Serial Monitor
- Uses clean threshold-based logic for each LED
- Organized and commented Arduino sketch for easier maintenance

## Hardware Used

| Component | Quantity | Notes |
|---|---:|---|
| Arduino Uno or compatible board | 1 | Main microcontroller |
| HC-SR04 ultrasonic distance sensor | 1 | Measures distance |
| LEDs | 7 | Used as the proximity indicator |
| 220Ω resistors | 7 | One resistor per LED recommended |
| Breadboard | 1 | For prototyping |
| Jumper wires | As needed | For circuit connections |

## Pin Configuration

| Device | Arduino Pin |
|---|---:|
| Ultrasonic Trigger | 11 |
| Ultrasonic Echo | 12 |
| LED 1 | 2 |
| LED 2 | 3 |
| LED 3 | 4 |
| LED 4 | 5 |
| LED 5 | 6 |
| LED 6 | 7 |
| LED 7 | 8 |

## LED Distance Thresholds

| LED | Turns On When Distance Is |
|---|---:|
| LED 1 | ≤ 5 cm |
| LED 2 | ≤ 7 cm |
| LED 3 | ≤ 10 cm |
| LED 4 | ≤ 15 cm |
| LED 5 | ≤ 17 cm |
| LED 6 | ≤ 20 cm |
| LED 7 | ≤ 25 cm |

## Repository Structure

```text
Arduino-DistanceSensor/
├── README.md
├── LICENSE
├── .gitignore
├── src/
│   └── distance_sensor_led_bar.ino
├── hardware/
│   └── components.md
├── docs/
│   └── wiring-notes.md
└── media/
    └── README.md
```

## How It Works

The ultrasonic sensor sends a short trigger pulse and waits for the echo signal to return. The Arduino calculates the distance based on how long the echo signal takes. The program then compares that distance against preset thresholds and turns LEDs on or off based on the measured proximity.

## Getting Started

1. Connect the ultrasonic sensor and LEDs using the pin configuration above.
2. Open `src/distance_sensor_led_bar.ino` in the Arduino IDE.
3. Select your Arduino board and port.
4. Upload the sketch.
5. Open the Serial Monitor at `9600 baud` to view live distance readings.

## Possible Improvements

- Add a buzzer for an audible proximity alert
- Add an LCD or OLED display for live distance output
- Replace fixed thresholds with configurable values
- Add smoothing/averaging to reduce sensor noise
- Create a 3D-printed enclosure for a finished prototype

## Original Project Images

The original README contained project images hosted externally. Add local screenshots, wiring diagrams, or demo GIFs to the `media/` folder for a more complete GitHub presentation.

## License

This project is licensed under the MIT License. See `LICENSE` for details.

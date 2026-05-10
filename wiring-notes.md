# Wiring Notes

## Ultrasonic Sensor

| HC-SR04 Pin | Arduino Connection |
|---|---|
| VCC | 5V |
| GND | GND |
| TRIG | Pin 11 |
| ECHO | Pin 12 |

## LEDs

Connect each LED anode to its assigned Arduino digital pin through a resistor. Connect each LED cathode to ground.

| LED | Arduino Pin |
|---|---:|
| LED 1 | 2 |
| LED 2 | 3 |
| LED 3 | 4 |
| LED 4 | 5 |
| LED 5 | 6 |
| LED 6 | 7 |
| LED 7 | 8 |

## Tip

After uploading the sketch, open the Serial Monitor at 9600 baud to confirm that the sensor is returning distance values.

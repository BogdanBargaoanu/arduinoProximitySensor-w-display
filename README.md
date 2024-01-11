# Proximity Sensor Project

This GitHub repository contains an Arduino project that utilizes a proximity sensor to measure distances and provides visual and auditory feedback. The project includes code written in C++ for Arduino and uses the Adafruit GFX and Adafruit SSD1306 libraries to interface with an OLED display.

[![License: MIT](https://img.shields.io/badge/License-MIT-g.svg)](https://opensource.org/licenses/MIT)
</p>


## Components Used
- Arduino Board
- Ultrasonic Proximity Sensor
- OLED Display (128x64 pixels)
- RGB LEDs (Red, Green, Blue)
- Buzzer

## Wiring
Make sure to connect the components according to the following pin configuration:

- Ultrasonic Sensor:
  - Trigger Pin: 3
  - Echo Pin: 2

- RGB LEDs:
  - Red Pin: 8
  - Green Pin: 12
  - Blue Pin: 13

- Buzzer:
  - Buzzer Pin: 6

- OLED Display:
  - SDA: A4
  - SCL: A5
  - Reset Pin: 4

## How it Works
The Arduino measures the distance using the ultrasonic sensor and provides feedback through the RGB LEDs, buzzer, and OLED display. The RGB LEDs change color based on the proximity, the buzzer produces different sounds, and the OLED display shows the measured distance along with a graphical representation.

## Installation
1. Clone this repository to your local machine.
```bash
git clone https://github.com/BogdanBargaoanu/arduinoProximitySensor-w-display.git
```
2. Open the Arduino IDE and load the sketch (`ProximitySensor.ino`).
3. Make sure to install the required libraries (`Adafruit_GFX` and `Adafruit_SSD1306`) in the Arduino IDE.

## Usage
1. Connect the components following the wiring instructions.
2. Upload the sketch to your Arduino board.
3. Power up the system, and observe the feedback on the RGB LEDs, buzzer, and OLED display.

Feel free to modify the code to adapt it to your specific requirements or to enhance its functionality. If you encounter any issues or have suggestions, please create an issue in the repository.

Happy coding!

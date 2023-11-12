# Garbage Monitoring Module

This Arduino code implements a Garbage Monitoring Module using an Ultrasonic Sensor (HC_SR04), an LCD Display (16x2), and a Buzzer. The module is designed to monitor the level of garbage in a container and provide visual and audible feedback based on the fill level.

## Components Used

- **Ultrasonic Sensor (HC_SR04):**
  - VCC - 5V
  - Trig - 9
  - Echo - 10
  - Gnd - Gnd

- **LCD Display (16x2):**
  - VSS - Gnd
  - VDD - 5V
  - VO - 6
  - RS - 12
  - RW - Gnd
  - E - 11
  - D4 - 5
  - D5 - 4
  - D6 - 3
  - D7 - 2
  - A - 5V
  - K - Gnd

- **Buzzer:**
  - Positive - Pin 8
  - Negative - Gnd

## Wiring Configuration

Make sure to connect the components as per the specified pin configurations in the code, the schematics is also attached.

## Code Explanation

The Arduino code uses the Ultrasonic Sensor to measure the distance to the surface of the garbage in the container. The LCD Display shows the congestion level as a percentage, and a Buzzer is activated if the garbage level is full.

The congestion level is determined based on the calculated percentage of distance. If the percentage is less than or equal to 25 or the distance exceeds 300 units, the Buzzer sounds, and the LCD displays "GARBAGE IS FULL." Otherwise, the LCD displays the congestion level in percentage.

If the congestion level is greater than or equal to 100%, it suggests a blockage, and the LCD displays "Retry"

## Setup

1. Connect the components as specified in the comments in the code.
2. Upload the code to your Arduino board.
3. Power on the system.



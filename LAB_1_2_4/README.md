### Project Specification
The system will have two inputs and three outputs. The inputs are switches called SW1 and SW2, which are connected port pin PF4 and PF0 respectively. Three outputs (PF3, PF2, PF1) are connected to one multi-color LED. The circuit diagram used in Lab 4 is shown in Figure 4.1. The color of the LED is determined by the 3-bit value written to the outputs. The specifications are summarized in the following table:

| Switch Input                                 | LED Output                     |
|----------------------------------------------|--------------------------------|
| Both switches SW1 and SW2 are pressed        | The LED should be blue         |
| Just SW1 switch is pressed                   | The LED should be red          |
| Just SW2 switch is pressed                   | The LED should be green        |
| Neither SW1 nor SW2 is pressed               | The LED should be off          |

### Implementation Details
The lab was intended to be implemented with internal LEDs and switch. However, I wanted to take it to another level by implementing it on an external breadboard with switches and LEDs.

I have 2 switches connected to the microcontroller through the GPIO PD10 and PD11 pins. The external LEDs were connected to the microcontroller using GPIO pins PA1, PA2 and PA3. When a read from the switches is performed, the value of `switch_state_1` and `switch_state_2` will update based on their current state. Based on those values, the program will write to the PA1, PA2 and/or PA3 pins their correct values to light up the LED.

Note:

1. Small delay is added to make sure the switches gets a chance to stabilize before the next read.
2. The values SET and RESET for all pins are included in case one or more stays on even after other buttons are pressed.
3. You will see that my LEDs are not connected through any resistors. This is intentional (albeit not the right thing to do) as I wanted to get this project done fairly fast. If anyone wants to use a resistor, here's how they should calculate it:

```
Output voltage of GPIO ports for this microcntroller is 3.3V. 
The LED's capacity is up to 2V. 
These LEDs can take up to 20mA of current. 
Therefore, accoding to Ohm's law, the resistor we should be using is:
R = V / I
  = 2 / 0.020
  = 100Ω
```

### Output
The following Video shows the output and how the LEDs light up based on certain inputs:

[LAB 2-4 implementations](https://i.imgur.com/BGfj16N.mp4)
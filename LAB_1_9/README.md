### Project Specification
Implement a system that generates a 10hz LED pulse upon switch press and records the result in an array. The course uses the internal switch and LED for the project. However, in order to take it a step further, I introduced external switches and LED. When either switch or both are pressed, the LED will start blinking at 10hz. Here are the requirements:
1. Make the LED flash at 10 Hz.
2. Make the LED flash only when switch 1, 2 or both are pressed.
3. Record the value of switch actions in an array. For example, if switch 1 is pressed, record the following in the array: `[1, 1, 1]` (when LED is on) and `[1, 1, 0]` (when LED is off). The array template for recording is: `[Switch/pin, Switch State, LED On/Off]`.

### Implementation
At first, let's convert the value of 10hz to miliseconds:

```
1hz = 1 cycle per 1 second
=> 10hz = 10 cycle per 1 second

1 cycle = (LED Toggle On + LED Toggle Off)
=> Each action (LED Toggle) should take 0.5 cycle

10 cycle takes 1 second
=> 10 cycle takes 1000 milisecond
=> 0.5 cycle will take 50 milisecond (0.05 seconds)
```

So, we have to make sure the LED turns on for 50 milisecond and then turns off for 50 milisecond, while either switch is pressed, in order to generate a 10hz pulse using the LED.

We connected our external LED with the PC1, switch 1 (`sw1`) to PE7 and switch 2 (`sw2`) to PE9. In idle state, the program waits for a switch press and doesn't record any data. When `sw1` is pressed, it updates `sw1`'s value to 1, records the pin number, switch state and LED value. At the beginning, the LED value will be 1 since it's turning on, then after 50 miliseconds, the LED will turn off, therefore, the LED value will change to 0. So on the first half-cycle, the array should record the value `[7, 1, 1]`, then on the next half cycle, the array will record the value `[7, 1, 0]`. The same will happen when `sw2` is pressed, but the array will record `[9, 1, 1]` and `[9, 1, 0]` instead, as `sw2`'s pin number is 9.

### Output
[This video](https://i.imgur.com/rIslDMp.mp4) shows that when either `sw1` or `sw2` is pressed, the LED starts flashing at 10hz. When no button is pressed, it stays in an idle state. Below is a screenshot of the data it captured. You will see that the array alternated between `[7, 1, 1]` and `[7, 1, 0]` during `sw1` was pressed and the array recorded `[9, 1, 1]` and `[9, 1, 0]` while `sw2` was pressed.

[Array data screenshot](https://i.imgur.com/2VdNk4J.png)
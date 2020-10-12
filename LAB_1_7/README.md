### Project Specification
In this lab you will create seven subroutines. Solving a complex problem by breaking it into simpler subtasks is an effective approach to design. There is one input called the Atrial sensor (AS), and two outputs Ready and Ventricular trigger (VT). AS input is connected to button. In a real pacemaker, electrodes (wires) are attached to the heart and electronics are used to sense the activity of the heart. In this lab, a switch will be used to emulate the operation of the atrial sensor. When the button is pressed (AS=0) it means the atria has begun to contract. When the button is released, it means the atria have completed contraction. The Ready output is connected to Green LED (PD12). The LED will be green when Ready is high. The Ready signal is used for debugging, and not part of an actual pacemaker. In a real pacemaker, electrodes (wires) are attached to the heart, and electrical pulses are generated that stimulate the heart, causing it to beat. In this lab, the VT output is connected to Red LED (PD14), such that the LED will be red when VT is high. A 250 ms pulse will cause the ventricules to contract.

The Ready signal is initially high. On the falling edge of the AS, you should make Ready low. You will then wait 10 ms. This wait is necessary to eliminate bouncing in the switch. Next you wait for the rising edge of AS, which means the atria are done contracting. You will then wait 250 ms, and then output a 250ms pulse on VT. In particular, your system should repeat these 9 steps over and over:
- Make the Ready signal go high
- Wait for AS to be 0, switch to be pressed
- Make the Ready signal go low
- Wait 10ms
- Wait for AS to be 1, switch to be released
- Wait 250ms
- Make the VT signal go high
- Wait 250ms
- Make the VT signal go low

### Implementation Details
Since the project deals with 2 LEDs and 1 switch, we have to turn the GPIO D and A ports respectively as the LEDs are connected to PD12 and PD14 respectively and the button is connected to PA0 pin. The first part of main (right before the infinite loop) takes care of initializing these GPIO ports the right way.

Once the pins are initialized, the `SetReady()` function is called, which lights up the Green LED. After that, the `WaitForASLow()` function is called which doesn't do anything until a button press is triggered. When the button is pressed, it turns the Green LED off using the `ClearReady()` function and then waits 10ms for the button to stop bouncing. Then, the function calls the `WaitForASHigh()` function, which waits until the button is unpressed. Once the button is unpressed, It waits for 250ms and then turns the Red LED on for 250ms usinig the `SetVT()` function. After that, it turns the Red LED off using the `ClearVT()` function and then returns to the calling `WaitForASLow()` function. This functions sees that the button is not pressed, therefore it breaks from the loop and returns to `main()`. `main()` restarts the loop and it keeps going over and over again the same process. 

The set/clear of Ready and VT are done using the `HAL_GPIO_WritePin()` function and the button press is read using the `HAL_GPIO_ReadPin()` function.

### Output
The following video shows how the machine works. The Green LED stays on when nothing is happening. It turns off the moment the button is pressed and kept pressed. Once the button is unpressed, the Red LED lights up briefly and then the Green LED comes back up again waiting for the next signal (i.e. button press).

[Lab 1_7 implementation](https://i.imgur.com/qZabvA1.mp4)
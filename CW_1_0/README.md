### Project Specification
Create an SOS system that does the following:
- Stays idle in low power consumption state
- When a user button is pressed, it starts to flash an SOS signal
- The SOS signal is as follows: blink Green LED 3 short times, followed by 3 long times and again 3 short times
- Keep flashing the SOS LED until the reset button is pressed
- Once the reset button is pressed, the LED should go back to idle low power consumption state

### Implementation Details
The original course work used a TI board, which has two switches to control the action. However, since this board has only one button, the turning off of SOS part is taken care by the reset button. The reset button also, automatically, puts the board in a low power consumption mode, so we don't have to worry about that either. 

The program starts the board in its usual manner and enters into an infinite loop waiting for button push. When the button is push, the `StartSOS()` function is called which, in turn, calls the `BlinkShort()` and `BlinkLong()` functions in a way as to imitate the SOS signal. Delays are strategically added to both imitate SOS and wait between two signals. This continues to flash the SOS until the reset button is pressed and the board goes to the initial state.

### Output
The following video shows how the project works. If we press the user button, the LED starts to flash in the SOS rhythm. Once the reset button is pushed, it stops blinking.

[Course Work 0 Implementation](https://i.imgur.com/6GM4JmF.mp4)
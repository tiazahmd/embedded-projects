### Project Specification
A heartbeat system is a brief pulse lets a user know if an operation has been performed successfully or not. Often times, when you install a smart doorbell or smart lock that doesn't have a display. There is no way for the system to display if something has been done right or not. At those times, the system will use a pulse of light or sound (beeping noise) to notify the user if certain function performed correctly. The goal of this project is to implement something similar. The programmer will place this heartbeat function in strategic positions in their code to notify the user if an operation has completed successfully or if it generated an error.

### Implementation Details
The original lab intended this to be a minimally intrusive macro - meaning this will go to a certain address and manually turn a bit on or off. This will result in low CPU cycles (less overhead) involved with function calling, execution and return. However, since I'm trying to use HAL for everything in this repository, I made it using a modular approach instead of using macro. 

*Note: If you are interested in how to do this more manually, I have a project where I implemented a [morse code system](https://github.com/tiazahmd/LED_Morse) where I created the initiation and blinking functions using a more manual method. You can take inspiration from that to implement the heartbeat system in a bare metal way.*

The `EnableHeartBeat()` function initiates the correct ports and pins. The reason I made it as a separate function is so that every time the heartbeat operation is called, it doesn't go through the same initiation process, costing more CPU cycles.

The `HeartBeat(uint8_t state)` function takes in a parameter `state`, which can either be `SUCCESS` or `ERROR`. If it is `SUCCESS`, it will blink the Green LED twice to imitate a pulse. On the other hand, if it's an `ERROR`, it will blink the RED LED twice. 

### Output
The following video shows the output how green and red LEDs are pulsing:

[LAB 1_6 implementations](https://i.imgur.com/lEbwSnu.mp4)
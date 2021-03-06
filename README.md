### Introduction
This repository is the implementation of all projects from [UT Austin's Shape the World](https://www.edx.org/course/embedded-systems-shape-the-world-microcontroller-i) course. The course uses a different microcontroller (TI TM4C123G) and the books and materials I'm using uses an STM32 Nucleo F411RE microcontroller. However, all the projects on this repo are implemented using an STM32 F407G-DISC1 microcontroller. This allowed me to learn 2 vendors and 3 microcontrollers at the same time. 

### Objectives
Using 3 different microcontroller to learn is allowing me to find the same information from 3 different data sheets. As a result, I'm learning what features may or may not be available, reasons for why one microcontroller may choose to have one and the other wouldn't, what are some of the subtle differences between TI and STM etc. So, as you can see, the objective of this repo is to make things a bit more challenging by using the Tiva Launchpad to learn, Nucleo board to practice and Discovery board to implement the projects. Often times you'll find that I try to push the boundaries of the project a bit further by doing a bit more. For example, Lab 4 uses the internal LEDs and switches for the project. But I wanted to make it a bit more challenging for me by using external LEDs and switches.

### Folder Structure
Each folder contains the implemented lab details. The `/lab_x_x_x/Core` files will include headers and the source file that drives the microcontroller. The `README.md` files inside these lab folders contains the project specification and how I implemented them. 

### Folder Naming Convention
The folders use the following naming convention: `<Type of work>_<Course Part>_<Lab Number>_<Lab Number>`. So, for example, in the first shape the world course (this course is broken down in 2 parts on EdX), there are 8 labs. However, I found lab 2 and 4 to be closely related, so I implemented both of them together. So, for this lab:
- Type: LAB
- Course Part : 1
- Lab Number  : 2
- Lab Number  : 4
Therefore, the name of the folder for this lab is `LAB_1_2_4`. For Lab 5, the folder name is `LAB_1_5`. For course works, use `CW` for `<Type of work>`. For example, `CW_1_0`.

### Labs
Below is the detailed list and brief description of projects implemented (the rest of the list will be updated as I make progress):
1. **LAB_1_2_4_8:** Implement a system that reads from 2 input switch (switch A and B) and controls 3 LEDs (LED X, Y and Z) based on the switch behavior. If A is pressed, X lights up; if B is pressed, Y lights up; and if A and B are both pressed simultaneously, Z lights up. Edit: I just realized that Lab 8 basically does the same thing I did for Lab 2 and 4. Therefore, I'm combining that with this lab. *(Complete)*
2. **LAB_1_5:** C Project - Write a function that accepts two input parameters (length and width) and calculates the area of a rectangular room with this length and width. The length and width are in meters and the returned area should be in square meters. Calculate the area only if both the length and width are between 3 and 20 inclusively. Return a result of zero if the length is less than 3, the width is less than 3, the length is greater than 20 or the width is greater than 20. *(Complete)*
3. **LAB_1_6:** Implement a heartbeat function that produces a pulse to notify the user if an operation executed successfully or not. If there is an error, there will be a red pulse. If the operation executed successfully, there will be a green pulse. *(Complete)*
4. **LAB_1_7:** Implement a pacemaker prototype where the machine will wait (stay in ready state, i.e. Green LED will stay on) for a signal (i.e. button press) and while the signal is high (i.e. button is in pressed state) is there, it will do nothing. But the moment the signal is lost (i.e. button is unpressed) it will emit a small pulse (i.e. flash the Red LED for 250ms) and then go back to the ready state. *(Complete)*
5. **LAB_1_9:** Implement a system that generates a 10hz LED pulse upon switch press and records the result in an array. If either switch 1, switch 2 or both are pressed, it will start emitting the 10hz pulse using the external LED and will start recording data in an array. *(Complete)* 

### Course Works
Course works are various in-class works that the course have to teach critical concepts. For example, in order to teach how USART works, the course may introduce a project that they work on from beginning to end in order to demonstrate how each component work. I'm following along those course works as well and porting them to STM32. Below is the list of course works that the course go through and I implemented(the rest of the list will be updated as I make progress):
1. **CW_1_7_1:** Implement an SOS system that starts flashing the LED on a SOS pattern once a button is pressed and whenever the another button is pressed, it stops flashing. *(Complete)*
2. **CW_1_10_1:** Design a system with one binary input and one binary output. The system should read the input every second. The output should be 1 if the number of received input bits has been odd, and should be 0 if the number of input bits has been even. *(Complete)*
3. **CW_1_10_2:** Design a traffic light controller for the intersection of two equally busy one-way streets. The goal is to maximize traffic flow, minimize waiting time at a red light, and avoid accidents. *(Complete)*
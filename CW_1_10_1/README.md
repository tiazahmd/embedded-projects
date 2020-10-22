### Project Specification
Design a system with one binary input and one binary output. The system should read the input every second. The output should be 1 if the number of received input bits has been odd, and should be 0 if the number of input bits has been even. The goal is to use `struct`s to create a Finite State Machine (FSM) and then use that FSM process to implement the solution.

### Implementation
We used the `FiniteStateMachine` struct to hold data for different steps. We declared the `FSM` struct globally so that the `OddsDetector()` and `PrintOutput()` functions can use them. 

The `OddsDetector()` function takes in the binary digits (bits) and then determines if an odd or even number of bits have been passed on. It also preserves the previous state in the `previous_state` variable and updates the current state based on the output. 

The `PrintOutput()` function prints the previous state, current state and the output (0 or 1 based on even or odd).

### Output
Here's the output for our test cases:

```bash
$ gcc main.c -o main
$ ./main

------------------------------------
     Finite State Machine Tests     
------------------------------------

------------------------------------
Test no: 1
The previous state was: EVEN
The current state is EVEN
The output is: 0
------------------------------------

------------------------------------
Test no: 2
The previous state was: EVEN
The current state is ODD
The output is: 1
------------------------------------

------------------------------------
Test no: 3
The previous state was: ODD
The current state is EVEN
The output is: 0
------------------------------------

------------------------------------
Test no: 4
The previous state was: EVEN
The current state is ODD
The output is: 1
------------------------------------

------------------------------------
Test no: 5
The previous state was: ODD
The current state is ODD
The output is: 1
------------------------------------
```
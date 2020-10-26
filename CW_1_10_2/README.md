### Project Specification
Design a traffic light controller for the intersection of two equally busy one-way streets. The goal is to maximize traffic flow, minimize waiting time at a red light, and avoid accidents. Below is a screenshot of what we're trying to achieve:

![Traffic Light](https://raw.githubusercontent.com/tiazahmd/embedded-projects/master/CW_1_10_2/Fg06_11_TrafficLight.jpg)

### Solution
Since I didn't have a motion sensor at the time of this project, I used two buttons to mimic the behavior of a motion sensor. If button 1 or 2 is pressed, it meant either North or East sensor has been triggered. There are 6 key functions that are key to solving this problem and uses an Finite State Machine (FSM) called `TrafficFSM`. They are:

```C
greenToRed() / redToGreen()         /* These functions are exactly as advertised. They
                                       either make the Green light to go Red, or make
                                       the Red light go Green. There are small delays
                                       added to make sure the Yellow stays on for the
                                       right amoung of time before changing etc. These
                                       delays are not exactly according to the one the
                                       course mentioned, for fast testing purpose. */

goN() / goE()                       /* These two functions, at first, checks if
                                       the North/East lights are already in desired
                                       state. If not, they change the FSM variables, 
                                       calls the waitE() or waitN() function and then
                                       calls the redToGreen() function. */

waitN() / waitE()                   /* These two functions activates the wait functionality,
                                       which basically is making the East/North light to
                                       go Red before switching the other one to Green. This
                                       avoids any potential collision and makes sure that
                                       both Green lights aren't, at any point, turned on. */

typedef struct {
	uint8_t north_sensor;
	uint8_t east_sensor;
	uint8_t north_red_light;
	uint8_t north_yellow_light;
	uint8_t north_green_light;
	uint8_t east_red_light;
	uint8_t east_yellow_light;
	uint8_t east_green_light;
} TrafficFSM;
```

The application initiates at a North == Green and East == Red state. It initializes all FSM states that way and makes sure the traffic lights are turned on correctly by default. Whenever the East motion sensor is triggered (i.e. the East motion sensor mimicking button is pressed), the program calls `goE()` function. That function checks if the East lights are on the "Green" state or not and since it's not, it makes sure correct changes to the state of the FSM is made, calls the `waitN()` function so that North's Green light goes from Green to Red and then calls the `redToGreen()` function to make sure the East Green lights are activated. 

It stays this way until the North motion sensor (i.e. the North button) sends a signal saying there is a car coming. When that happens, the `goN()` function is called, that calls the `waitE()` function and then turns the North signal from Red to Green using the `redToGreen()` function.

The `TrafficFSM` structure called `system_block` keeps a tab on which states the system is in. For example, if East's sensor is set off, `system_block.east_sensor` will equal to `1`. Otherwise, it will stay `0`.

### Output
The output of the program can be seen in the following video. You'll notice that the button press (i.e. motion sensor set off) forces the light to change in different situations. Sometimes they won't change if a button is pressed because the state for that motion sensor is already set. For example, if the North green light is on, setting off the North motion sensor will not have any change.

[Traffic Light Output](https://i.imgur.com/OFMu6oO.mp4)
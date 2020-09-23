### Project Specification
Write a function that accepts two input parameters (length and width) and calculates the area of rectangular room with this length and width. The length and width are in meters and the returned area should be in square meters. Calculate the area only if both the length and width are between 3 and 20 inclusively. Return a result of zero if the length is less than 3, the width is less than 3, the length is greater than 20 or the width is greater than 20.

### Implementation Details
I'm assuming the function should take in integer values only and since it's a multiplication, it will return an integer as well. Therefore, the function declaration is `int area(int length, int width);`. I'm also creating another function to check if the values are within 3 and 20 inclusive: `bool isInRange(int length, int width);`.

### Output
I tried it with 2 legitimate cases and 3 out of range cases. Here are there outputs:

```Bash
$ ./main 
Enter the length in meters: 6
Enter the width in meters: 4
The area is 24 square meters.

$ ./main 
Enter the length in meters: 3
Enter the width in meters: 20
The area is 60 square meters.

$ ./main 
Enter the length in meters: 2
Enter the width in meters: 10
The area is 0 square meters.

$ ./main 
Enter the length in meters: 4
Enter the width in meters: 22
The area is 0 square meters.

$ ./main 
Enter the length in meters: 2
Enter the width in meters: 22
The area is 0 square meters.
```
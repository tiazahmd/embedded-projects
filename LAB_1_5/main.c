#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int area(int length, int width);
bool isInRange(int length, int width);

int main(void)
{
    int result, length, width;

    printf("Enter the length in meters: ");
    scanf("%d", &length);

    printf("Enter the width in meters: ");
    scanf("%d", &width);

    if (isInRange(length, width)) {
        result = area(length, width);
    } else {
        result = 0;
    }

    printf("The area is %d square meters.\n", result);

    return EXIT_SUCCESS;
}

int area(int length, int width)
{
    return length * width;
}

bool isInRange(int length, int width)
{
    if (length < 3 || width < 3 || length > 20 || width > 20)
        return false;

    return true;
}

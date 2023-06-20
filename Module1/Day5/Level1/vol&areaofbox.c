#include <stdio.h>

// Structure to represent a box
struct Box {
    float length;
    float width;
    float height;
};

float calculateVolume(struct Box* boxPtr) {
    return (*boxPtr).length * (*boxPtr).width * (*boxPtr).height;
}
float calculateSurfaceArea(struct Box* boxPtr) {
    return 2 * (boxPtr->length * boxPtr->width + boxPtr->length * boxPtr->height + boxPtr->width * boxPtr->height);
}

int main() {
    struct Box myBox;
    struct Box* boxPtr = &myBox;
    printf("Enter the length, width, and height of the box: ");
    scanf("%f %f %f", &(myBox.length), &(myBox.width), &(myBox.height));
    float volume = calculateVolume(boxPtr);
    float surfaceArea = calculateSurfaceArea(boxPtr);
    printf("Volume : %.2f\n", volume);
    printf("Total Surface Area : %.2f\n", surfaceArea);
    return 0;
}

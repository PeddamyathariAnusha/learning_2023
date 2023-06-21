#include <stdio.h>
#include <math.h>

struct Point {
    float x;
    float y;
};
float calculateDistance(struct Point p1, struct Point p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    struct Point point1, point2;
    printf(" Enter the coordinates of point1 of x: ");
    scanf("%f", &point1.x);
    printf("Enter the coordinates of point1 of y: ");
    scanf("%f", &point1.y);
    printf("Enter the coordinates of point2 of x: ");
    scanf("%f", &point2.x);
    printf("Enter the coordinates of point2 of y: ");
    scanf("%f", &point2.y);
    float distance = calculateDistance(point1, point2);
    printf("Distance between the points: %.2f\n", distance);
    return 0;
}

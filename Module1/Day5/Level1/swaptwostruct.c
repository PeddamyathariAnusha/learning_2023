#include <stdio.h>

struct Point {
    int x;
    int y;
};

void swapPoints(struct Point *pnt1, struct Point *pnt2);
int main() {
    struct Point pnt1, pnt2;

    printf("Enter the coordinates of Point 1(x and y):\n");
    scanf("%d %d", &pnt1.x, &pnt1.y);
    printf("Enter the coordinates of Point 2(x and y):\n");
    scanf("%d %d", &pnt2.x, &pnt2.y);

    printf("\nBefore swapping:\n");
    printf("Point 1: (%d, %d)\n", pnt1.x, pnt1.y);
    printf("Point 2: (%d, %d)\n", pnt2.x, pnt2.y);
    swapPoints(&pnt1, &pnt2);
    printf("After swapping:\n");
    printf("Point 1: (%d, %d)\n", pnt1.x, pnt1.y);
    printf("Point 2: (%d, %d)\n", pnt2.x, pnt2.y);

    return 0;
}

void swapPoints(struct Point *pnt1, struct Point *pnt2) {
    struct Point temp;
    temp = *pnt1;
    *pnt1 = *pnt2;
    *pnt2 = temp;
}

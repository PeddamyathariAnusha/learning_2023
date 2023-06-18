#include <stdio.h>

int main() {
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dd, mm, yy;
    int daysElapsed = 0;
    printf("Enter the day (dd): ");
    scanf("%d", &dd);
    printf("Enter the month (mm): ");
    scanf("%d", &mm);
    printf("Enter the year (yyyy): ");
    scanf("%d", &yy);

    if ((yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0)) {
        monthDays[1] = 29; // Update February days to 29
    }

    for (int i = 0; i < mm - 1; i++) {
        daysElapsed += monthDays[i]; //days elapsed
    }

    daysElapsed += dd;
    printf("Number of days elapsed: %d\n", daysElapsed);
    return 0;
}
#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time getTimeDifference(struct Time start, struct Time end);

int main() {
    struct Time startTime, endTime, difference;
    printf("Enter the start time (hrs mins secs):  ");
    scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);
    printf("Enter the end time(hrs mins secs):  ");
    scanf("%d %d %d", &endTime.hours, &endTime.minutes, &endTime.seconds);
    difference = getTimeDifference(startTime, endTime);
    printf("\nTime difference: %d hours, %d minutes, %d seconds\n", difference.hours, difference.minutes, difference.seconds);
    return 0;
}

struct Time getTimeDifference(struct Time start, struct Time end) {
    struct Time diff;
    int startInSeconds = start.hours * 3600 + start.minutes * 60 + start.seconds;
    int endInSeconds = end.hours * 3600 + end.minutes * 60 + end.seconds;
    int differenceInSeconds = endInSeconds - startInSeconds;
    diff.hours = differenceInSeconds / 3600;
    differenceInSeconds %= 3600;
    diff.minutes = differenceInSeconds / 60;
    differenceInSeconds %= 60;
    diff.seconds = differenceInSeconds;
    return diff;
}

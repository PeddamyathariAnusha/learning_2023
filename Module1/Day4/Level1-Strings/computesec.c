#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long computeTotalSeconds(const char* timeStr) {
    char* token = strtok((char*)timeStr, ":");
    unsigned long hours = strtoul(token, NULL, 10);
    token = strtok(NULL, ":");
    unsigned long minutes = strtoul(token, NULL, 10);
    token = strtok(NULL, ":");
    unsigned long seconds = strtoul(token, NULL, 10);
    unsigned long totalSeconds = (hours * 3600) + (minutes * 60) + seconds;
    return totalSeconds;
}

int main() {
    char timeStr[10];
    printf("Enter the time in hh:mm:ss format: ");
    scanf("%s", timeStr);
    unsigned long totalSeconds = computeTotalSeconds(timeStr);
    printf("Total seconds: %lu\n", totalSeconds);

    return 0;
}
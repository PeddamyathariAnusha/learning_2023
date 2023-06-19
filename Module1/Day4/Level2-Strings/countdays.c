#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int calculateDays(int day, int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDays = day;
    for (int i = 0; i < month - 1; i++) {
        totalDays += daysInMonth[i];
    }
    if (isLeapYear(year) && month > 2) {
        totalDays++;
    }
    return totalDays;
}

int main() {
    char date[12];
    printf("Enter the date in DD/MM/YYYY format: ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = '\0';  // Remove new line
    char *token;
    int day, month, year;    
    // Split the string into different tokens using "/"
    token = strtok(date, "/");
    day = atoi(token);    
    token = strtok(NULL, "/");
    month = atoi(token);    
    token = strtok(NULL, "/");
    year = atoi(token);    
    // Calculate the number of days
    int elapsedDays = calculateDays(day, month, year);
    printf("No. of days elapsed: %d\n", elapsedDays);
    return 0;
}
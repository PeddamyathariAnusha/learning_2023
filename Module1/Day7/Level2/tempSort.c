#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SENSOR_NAME 10
#define MAX_TIMESTAMP 9
#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 100

typedef struct {
    int entryNo;
    char sensorNo[MAX_SENSOR_NAME];
    float temperature;
    int humidity;
    int light;
    char timestamp[MAX_TIMESTAMP];
} LogEntry;

LogEntry logEntries[MAX_ENTRIES];
int numEntries = 0;

void readLogFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file: %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof(line), file);
    while (fgets(line, sizeof(line), file)) {
        LogEntry entry;
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,\n]", &entry.entryNo, entry.sensorNo, &entry.temperature,
               &entry.humidity, &entry.light, entry.timestamp);
        logEntries[numEntries++] = entry;
    }

    fclose(file);
}

void sortDataByTemperature(LogEntry logEntries[], int numEntries) {
    for (int i = 0; i < numEntries - 1; i++) {
        for (int j = 0; j < numEntries - i - 1; j++) {
            if (logEntries[j].temperature < logEntries[j + 1].temperature) {
                LogEntry temp = logEntries[j];
                logEntries[j] = logEntries[j + 1];
                logEntries[j + 1] = temp;
            }
        }
    }
}

void displayLogData() {
    printf("EntryNo | SensorNo | Temperature | Humidity | Light | Timestamp \n");
    printf("----------------------------------------------------------------\n");
    for (int i = 0; i < numEntries; i++) {
        LogEntry entry = logEntries[i];
         printf("%-7d | %-8s | %-11.2f | %-8d | %-5d | %-s\n", entry.entryNo, entry.sensorNo,
               entry.temperature, entry.humidity, entry.light, entry.timestamp);
    }
    printf("-----------------------------------------------------------------\n");
}
int main() {
    readLogFile("data.csv");
    sortDataByTemperature(logEntries, numEntries);
    displayLogData();
    printf("Data sorted successfully.\n");
    return 0;
}

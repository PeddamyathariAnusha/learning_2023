#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_SENSOR_NAME 10
#define MAX_TIMESTAMP 9

typedef struct {
    int entryNo;
    char sensorNo[MAX_SENSOR_NAME];
    float temperature;
    int humidity;
    int light;
    char timestamp[MAX_TIMESTAMP];
} LogEntry;

void extractLogData(const char *filename, LogEntry logEntries[], int *numEntries) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    
    char line[100];
    fgets(line, sizeof(line), file); // Skip the header line
    
    *numEntries = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        LogEntry entry;
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,\n]",
               &entry.entryNo, entry.sensorNo, &entry.temperature, &entry.humidity, &entry.light, entry.timestamp);
        
        logEntries[*numEntries] = entry;
        (*numEntries)++;
    }
    
    fclose(file);
}

void displayLogData(const LogEntry logEntries[], int numEntries) {
    printf("EntryNo SensorNo Temperature  Humidity  Light  Timestamp\n");

    for (int i = 0; i < numEntries; i++) {
        LogEntry entry = logEntries[i];
        printf("%-8d %-9s %-12.1f %-9d %-6d %s\n",
               entry.entryNo, entry.sensorNo, entry.temperature, entry.humidity, entry.light, entry.timestamp);
    }
}
int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;
    
    extractLogData("data.csv", logEntries, &numEntries);
    
    displayLogData(logEntries, numEntries);
    
    return 0;
}

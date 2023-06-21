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

void updateEntryByEntryNo(int entryNo, const LogEntry* updatedEntry) {
    for (int i = 0; i < numEntries; i++) {
        if (logEntries[i].entryNo == entryNo) {
            logEntries[i] = *updatedEntry;
            break;
        }
    }
}

void writeLogFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fprintf(file, "EntryNo,sensorNo,Temperature,Humidity,Light,Timestamp\n");
    for (int i = 0; i < numEntries; i++) {
        LogEntry entry = logEntries[i];
        fprintf(file, "%d,%s,%.1f,%d,%d,%s\n",
                entry.entryNo, entry.sensorNo, entry.temperature, entry.humidity, entry.light, entry.timestamp);
    }

    fclose(file);
}

int main() {
    readLogFile("data.csv");
    LogEntry updatedEntry = {2, "S4", 25, 98, 60, "10:32:10"};
    updateEntryByEntryNo(2, &updatedEntry);
    writeLogFile("data.csv");
    printf("Entry updated successfully.\n");
    return 0;
}

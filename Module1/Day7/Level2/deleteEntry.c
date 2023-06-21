#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_ENTRIES 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[9];
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
        sscanf(line, "%d,%[^,],%f,%d,%d,%s",
               &logEntries[numEntries].entryNo, logEntries[numEntries].sensorNo, &logEntries[numEntries].temperature,
               &logEntries[numEntries].humidity, &logEntries[numEntries].light, logEntries[numEntries].timestamp);
        numEntries++;
    }

    fclose(file);
}

void deleteEntryByEntryNo(int entryNo) {
    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (logEntries[i].entryNo == entryNo) {
            found = 1;
            for (int j = i; j < numEntries - 1; j++) {
                logEntries[j] = logEntries[j + 1];
            }
            numEntries--;
            break;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
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
        fprintf(file, "%d,%s,%.1f,%d,%d,%s\n",
                logEntries[i].entryNo, logEntries[i].sensorNo, logEntries[i].temperature,
                logEntries[i].humidity, logEntries[i].light, logEntries[i].timestamp);
    }

    fclose(file);
}

int main() {
    readLogFile("data.csv");
    deleteEntryByEntryNo(2);
    writeLogFile("data.csv");
    printf("Entry deleted successfully.\n");
    return 0;
}

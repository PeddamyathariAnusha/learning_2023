#include <stdio.h>
#include <string.h>

struct SensorData {
    char sensorID[10];
    float temperature;
    int humidity;
    int lightIntensity;
};

typedef struct SensorData sensorData;

void displaySensorData(sensorData*);
void initSensorData(sensorData*, char*, float, int, int);

int main() {
    sensorData sensorArray[100];
    int numSensors = 0;
    initSensorData(&sensorArray[numSensors], "S1", 36.5, 100, 50);
    numSensors++;
    printf("Sensor Info:\n");
    for (int i = 0; i < numSensors; i++) {
        displaySensorData(&sensorArray[i]);
        printf("\n");
    }
    return 0;
}
void initSensorData(sensorData* ptr, char* id, float temp, int hum, int light) {
    strcpy(ptr->sensorID, id);
    ptr->temperature = temp;
    ptr->humidity = hum;
    ptr->lightIntensity = light;
}
void displaySensorData(sensorData* ptr) {
    printf("Sensor ID: %s\n", ptr->sensorID);
    printf("Temperature: %.1f C\n", ptr->temperature);
    printf("Humidity: %d\n", ptr->humidity);
    printf("Light Intensity: %d%%\n", ptr->lightIntensity);
}
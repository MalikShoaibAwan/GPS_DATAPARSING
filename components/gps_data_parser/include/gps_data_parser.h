#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <esp_system.h>
#include <freertos/FreeRTOS.h>


typedef struct {
    char type[7];
    char time[11];
    char latitude[11];
    char lattitute_dir[2];
    char longitude[12];
    char longitude_dir[2];
    char fixQuality[2];
    char numSatellites[3];
    char hdop[4];
    char altitude[6];
    char unit_of_altitude[2];
    char geoidalSeparation[6];
    char unit_of_geoidalSeparation[2];
    char ageOfDifferentialData[3];
    char correction_station_data[6];
    unsigned int differentialRefID;
} GPSData;

int Validate_Checksum(const char* packet);
int Parse_Gps_Data(const char* packet, GPSData* gpsData);
void Gps_Parsed_Data(const char* packet, GPSData* gps);
void Show_GPS_Data(GPSData gps);

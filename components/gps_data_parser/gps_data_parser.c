#include"gps_data_parser.h"
unsigned int expected_checksum;

int Validate_Checksum(const char* packet) {
	 unsigned int expected_checksum;
     unsigned int checksum = 0;
     int i;

     // Check if the packet starts with '$'
     if (packet[0] != '$') {
         return 0; // Invalid packet format
     }

     // Calculate the expected checksum
     for (i = 1; packet[i] != '\0' && packet[i] != '*'; i++) {
         checksum ^= packet[i];
     }

     // Convert the expected checksum from hexadecimal to integer
     sscanf(packet + i + 1, "%2X", &expected_checksum);

     // Compare the calculated checksum with the expected checksum
     if (checksum == (expected_checksum & 0xFF)) {
         return 1; // Valid checksum
     }

     return 0; // Invalid checksum
 }

int Parse_Gps_Data(const char* packet, GPSData* gpsData) {
    int checksum_valid = Validate_Checksum(packet);
    if (checksum_valid == 0) {
        return 0; // Invalid GPS packet
    }

    // Make a copy of the packet to avoid modifying the original
    char packet_copy[1024];
    strncpy(packet_copy, packet, sizeof(packet_copy));

    // Split the packet into fields using strtok
    char* field = strtok(packet_copy, ",");
    int field_index = 0;
    while (field != 0) {
        switch (field_index) {
            case 0:
                strncpy(gpsData->type, field + 1, sizeof(gpsData->type) - 1);
                break;
            case 1:
                strncpy(gpsData->time, field, sizeof(gpsData->time) - 1);
                break;
            case 2:
                strncpy(gpsData->latitude, field, sizeof(gpsData->latitude) - 1);
                break;
            case 3:
                strncpy(gpsData->lattitute_dir,
                        field,
                        sizeof(gpsData->lattitute_dir) - 1);
                break;
            case 4:
                strncpy(gpsData->longitude, field, sizeof(gpsData->longitude) - 1);
                break;
            case 5:
                strncpy(gpsData->longitude_dir,
                        field,
                        sizeof(gpsData->longitude_dir) - 1);
                break;
            case 6:
                strncpy(gpsData->fixQuality, field, sizeof(gpsData->fixQuality) - 1);
                break;
            case 7:
                strncpy(gpsData->numSatellites,
                        field,
                        sizeof(gpsData->numSatellites) - 1);
                break;
            case 8:
                strncpy(gpsData->hdop, field, sizeof(gpsData->hdop) - 1);
                break;
            case 9:
                strncpy(gpsData->altitude, field, sizeof(gpsData->altitude) - 1);
                break;
            case 10:
                strncpy(gpsData->unit_of_altitude,
                        field,
                        sizeof(gpsData->unit_of_altitude) - 1);
                break;
            case 11:
                strncpy(gpsData->geoidalSeparation,
                        field,
                        sizeof(gpsData->geoidalSeparation) - 1);
                break;
            case 12:
                strncpy(gpsData->unit_of_geoidalSeparation,
                        field,
                        sizeof(gpsData->unit_of_geoidalSeparation) - 1);
                break;
            case 13:
                strncpy(gpsData->ageOfDifferentialData,
                        field,
                        sizeof(gpsData->ageOfDifferentialData) - 1);
                break;
            case 14:
                strncpy(gpsData->correction_station_data,
                 field,
                strlen(field) - strlen(strrchr(field + strlen(field) - strlen("XX")-strlen("X"), '\0')) -
               strlen("XX") - 1);
                break;
        }
        field = strtok(0, ",");
        field_index++;
        gpsData->differentialRefID = expected_checksum;
    }
    int len = strlen(packet);

    sscanf(packet + len - 2, "%2X", &expected_checksum);
    gpsData->differentialRefID = expected_checksum;

    return 1; // Valid GPS packet
}

void Gps_Parsed_Data(const char* packet, GPSData* gps) {   //gps_data_parsing
    GPSData *gpsData;
    gpsData=gps;
    memset(gpsData, 0, sizeof(GPSData));

    if (Validate_Checksum(packet)) {
        if (Parse_Gps_Data(packet, gpsData)) {
        	 printf("Valid GPS packet.\n");
        } else {
            printf("Invalid GPS packet.\n");
        }
    } else {
        printf("Invalid GPS packet.\n");
    }

}
void Show_GPS_Data(GPSData gpsData){

				printf("Type: %s\n", gpsData.type);
	            printf("Time: %s\n", gpsData.time);
	            printf("Latitude: %s %c\n", gpsData.latitude, gpsData.lattitute_dir[0]);
	            printf("Longitude: %s %c\n", gpsData.longitude, gpsData.longitude_dir[0]);
	            printf("Fix Quality: %s\n", gpsData.fixQuality);
	            printf("Number of Satellites: %s\n", gpsData.numSatellites);
	            printf("HDOP: %s\n", gpsData.hdop);
	            printf("Altitude: %s %c\n", gpsData.altitude, gpsData.unit_of_altitude[0]);
	            printf("Geoidal Separation: %s %c\n", gpsData.geoidalSeparation, gpsData.unit_of_geoidalSeparation[0]);
	            printf("Age of Differential Data: %s\n", gpsData.ageOfDifferentialData);
	            printf("Correction Station Data: %s\n", gpsData.correction_station_data);
	            printf("Differential Reference ID (Hex): %X\n", gpsData.differentialRefID);

}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <esp_system.h>
#include <nvs_flash.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include"gps_data_parser.h"

// Rest of your code

int app_main() {
	GPSData gpsData;
    const char* packet = "$GPGGA,115739.00,4158.8441367,N,09147.4416929,W,4,13,0.9,255.747,M,-32.00,M,01,0000*6E";
    //I have tested code on following examples.
    //"$GPGGA,202530.00,5109.0262,N,11401.8407,W,5,40,0.5,1097.36,M,-17.00,M,18,TSTR*61";
    //"$GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E";
    //"$GPGGA,092750.000,5321.6802,N,00630.3372,W,1,8,1.03,61.7,M,55.2,M,,*76";

    Gps_Parsed_Data(packet, &gpsData);
    Show_GPS_Data(gpsData);
    return 0;
}

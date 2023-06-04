# GPS_DATAPARSING
This is a GPS parsing project, built in ESP IDF stable version. Project contain the folder <component> which contain the library <gps_data_parser> made for this project. library has 2 files <.c> and <.h>. gps_data_parser.c contain 3 functions:
  1- checksum validation
  2- Parse_Gps_Data
  3- show_gps_Data
In main.c, this library is included as "gps_parser.h" so all functionality gets import.
In main.c, I give string as input, inorder to use it with GPS module you will have to write code to take input from module. This code assumes that you have already taken the input in array.
**How to Run**
  This code is setup for given input string, also some 
  

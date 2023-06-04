# GPS_DATAPARSING
This is a GPS parsing project, built in ESP IDF stable version. Project contain the folder <component> which contain the library <gps_data_parser> made for this project. library has 2 files <.c> and <.h>. gps_data_parser.c contain 4 functions:
  1- checksum validation:   It calculate the checksum and compare with expected (present in data after *) and return 1 on match and 0 on unmatch. 
  2- Parse_Gps_Data:        It break the string in tokens 
  3- Gps_Parsed_Data:       This function is just to get message weather data was valid or not.
  4- show_gps_Data:         It prints the parsed GPS data with mapping
  
**In case of data corruption** In this case, there will be message "Invalid data"
  
In main.c, this library is included as "gps_parser.h" so all functionality gets import.
In main.c, I give string as input, inorder to use it with GPS module you will have to write code to take input from module. This code assumes that you have already taken the input in array.
**How to Run**
  Download the zip file
  Extract it and copy to your ESP workspace
  click build, code should get build without any error
  This code is setup for given input string, also some tested examples are included.
  

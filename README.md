# esp32_master_service
PROGRAM FLASHING
1. Edit flash program
open My_room.ino and edit those line:
  char* ssid = "your wifi ssid";
  char* password = "your wifi password";
2. Flash esp32/8266 with My_room.ino, open Serial Monitor and press Reset button, waiting to get IP server
3. Open SmartHome.html as Chrome or any browser, input IP server and you can send command to server.
Incase the esp dont responding, you can access to: http://IP/switch_01 and http://IP/switch_02 to try again.

PIN CONNECTION
 Ouput pin was setting to 4 pin D5, D6, D7, D8 can use, you can do more by write your own setting:

 "pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);"
  
 However, you should be modify SmartHome.html to be access more than 2 channel (it's my default)

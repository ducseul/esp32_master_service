#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

//Our Wi-Fi ssdid and password
char* ssid = "abcde";
char* password = "123456788";
String switch_01 = "OFF";
String switch_02 = "OFF";


ESP8266WebServer server; //server variable

void setup() {
  initializePin(); //call function

  //Making Connection With netword
  WiFi.begin(ssid, password);
  
  Serial.begin(115200);
  Serial.print("Searching Connection");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.print(WiFi.localIP());
  
  serverSection();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}

void initializePin(){
  
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);

  digitalWrite(D5, LOW);
  digitalWrite(D6, LOW);
  digitalWrite(D7, LOW);
  digitalWrite(D8, LOW);
}

void serverSection(){
  server.on("/", []() {
    server.send(200, "text/html", "<!DOCTYPE html><html><meta charset='UTF-8'><head></head><body><h2>Ducseul's smart home</h2><h3><a href='/switch_01'>Cong tac 1</a></h3><br><h3><a href='/switch_02'>Cong tac 2</a></h3><br></body></html>");
  });

  server.on("/switch_01", switch_01_state);
  server.on("/switch_02", switch_02_state);

  server.on("/status", all_state);
  
  server.begin();
}

void switch_01_state(){
  if(switch_01 == "OFF"){
    switch_01 = "ON";
    digitalWrite(D5, HIGH);
    server.send(200, "text/html", switch_01 + "<script>history.go(-1);</script>");
  }else{
    switch_01 = "OFF";
    digitalWrite(D5, LOW);
    server.send(200, "text/html", switch_01 + "<script>history.go(-1);</script>");
  }
}

void switch_02_state(){
  if(switch_02 == "OFF"){
    switch_02 = "ON";
    digitalWrite(D6, HIGH);
    server.send(200, "text/html", switch_02 + "<script>history.go(-1);</script>");
  }else{
    switch_02 = "OFF";
    digitalWrite(D6, LOW);
    server.send(200, "text/html", switch_02 + "<script>history.go(-1);</script>");
  }
}

void all_state(){
  
  server.send(200, "text/html", "{'rl':'"+switch_01+"','ml':'"+switch_02+"'}");

}

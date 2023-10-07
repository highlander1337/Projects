#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


/* WiFi SSID  & Password*/
const char* ssid = "NodeMCU";
const char* password = "NodeMCU";

ESP8266WebServer server(80);

void setup(){
  Serial.begin(9600);
  delay(100);
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP(); // usually 192.168.4.1
  Serial.print("Access Point IP: ");
  Serial.println(myIP);

  server.on("/", handle_OnConnect);
  server.on("/connect", handle_connect); // connect to MPU6050
  server.on("/disconnect", handle_disconnect); // disconnect to MPU6050
  server.on("/start", handle_start); // start to collect data from MPU6050 using a new token
  server.on("/stop", handle_stop); // stop to collect data from MPU6050
  server.on("/restart", handle_restart); // restart to collect data using same token as previous
  server.onNotFound(handle_NotFound);

  server.begin();
  //Serial.println("HTTP Server Starded");

}

void loop(){
  server.handleClient();
}

void handle_OnConnect(){
  
}

void handle_disconnect(){
  
}

void handle_start(){
  int data1 = 0;
  int data2 = 0;
  int data3 = 0;
  int token = 0;
  server.send(200, "text/html", updateWebpage(data1, data2, data3, token); // (200 - everything works fine, type of content we want to send, function to geneterate a dynamic web page onto the browser)
}

void handle_stop(){
  
}

void handle_restart(){
  
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not Found");
}

String updateWebpage(data1, data2, data3, token){
  String ptr = "<!DOCTYPE html> <html>\n"; // webpage start
  
  ptr+= ""; // next line,
  
  ptr+= "</html>"; // webpage end
}

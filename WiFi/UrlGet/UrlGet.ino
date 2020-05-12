#include "SoftwareSerial.h"

#define RXPIN 6
#define TXPIN 7

String host = "www.google.com";

String ssid = "xxxxxxxx";
String password =  "xxxxxxxxxx";

SoftwareSerial esp(RXPIN, TXPIN);


void join() {

  Serial.println("Reseting WiFi");
  esp.println("AT+RST");
  if(esp.find("ready")) {
    Serial.println("Module Reset OK");
  }
  //Let the WiFi come up if it's configured
  Serial.print("Waiting for WiFi to start-up");
  for(int i=0; i<20; i++) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");


  Serial.println("Setting Station Mode");
  esp.println("AT+CWMODE=1");
  if(esp.find("OK")) {
    Serial.println("Station Mode Set to 1");
  }
  
  Serial.println("Joining WiFi");
  String join = "AT+CWJAP=\"" + ssid + "\",\"" + password + "\"";
  esp.println(join);
  if(esp.find("WIFI GOT IP")) {
    Serial.println("Joined OK");
  }
}


void getUrl()
{
  esp.println("Seting connection multiplex off");
  esp.println("AT+CIPMUX=0");
  if(esp.find("OK")) {
    Serial.println("Mux Set to 0");
  }

  Serial.println("Connecting to host " + host);
  esp.println("AT+CIPSTART=\"TCP\",\""+ host + "\",80");
  if(esp.find("OK")) {
    Serial.println("Connected to " + host);
  }
  esp.println("AT+CIPSEND=28");
  if(esp.find("OK")) {
    Serial.println("OK to send");
  }
  delay(1000);
  esp.println("GET /index.html HTTP/1.1");
  esp.println("");
  if(esp.find("SEND OK")) {
    Serial.println("Sent request OK");
  }
  esp.find("+IPD,");

  int c = 0;
  Serial.print("Got '");
  while(true) {
    c = esp.read();
    if((char)c == ':') {
      break;
    }
    if(c != -1) {
      Serial.print((char)c);
    }
  }
  Serial.println("' bytes");

  for(int i=0; i<20000; i++) {
    c = esp.read();
    if(c != -1) {
      Serial.print((char)c);
    }
  }
  Serial.println("");
  
  Serial.println("Closing connection");
  esp.println("AT+CIPCLOSE");
  
}


void setup() {
  Serial.begin(9600);
  esp.begin(9600);
    esp.setTimeout(10000);
  Serial.println("Starting setup code");
}


void loop() {
  Serial.println("Starting Loop");

  join();
  getUrl();
  
  Serial.print("Sleeping ");
  for(int i=0; i<20; i++) {
    delay(500);
    Serial.print("z");
  }
  Serial.println("");
}
  

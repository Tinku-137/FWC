

//----------------------Skeleton Code--------------------//
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//    Can be client or even host   //
#ifndef STASSID
#define STASSID "Galaxy"  // Replace with your network credentials
#define STAPSK  "12345678"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;


void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}

//-------------------------------------------------------//
int Q,R,S,Y;
void setup(){
  OTAsetup();

  //-------------------//
  // Custom setup code //
  //-------------------//
	pinMode(2, INPUT);	
	pinMode(3, INPUT);	
	pinMode(4, INPUT);	
	pinMode(5, OUTPUT);	

}

void loop() {
  OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
  //-------------------//
  	Q = digitalRead(2);
  	R = digitalRead(3);
  	S = digitalRead(4);
	Y= (!Q&&!R&&S)||(!Q&&R&&!S)||(Q&&!R&&!S)||(Q&&R&&S);
	digitalWrite(5, Y);
	delay(1000);
}



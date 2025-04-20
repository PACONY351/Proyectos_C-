
#include<Ubidots.h>

const char* UBIDOTS_TOKEN = "";
const char* WIFI_SSID = "";
const char* WIFI_PASS = "";

Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);


int var_poten;



void setup() {

  Serial.begin(115200);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  var_poter = 0;
}

void loop() {
  
  var_poter = analogRead(A0);
  Serial.println(var_poten);

  ubidots.add("var_poten", var_poten);
}

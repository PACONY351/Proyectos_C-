
// Librerias- Ubidots
#include<Ubidots.h>

// Declaracion de constantes char tipo puntero con token y red Wifi 
const char* UBIDOTS_TOKEN = "BBUS-NtBXDgeRZAniKmWWYyy508FERbab5i";
const char* WIFI_SSID = "IZZI-C84D";
const char* WIFI_PASS = "50955127C84D";

// Creacion del objeto Ubidots con parametros 
Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);

// Variables
int var_poten;



void setup() {

  // Velocidad del Serial
  Serial.begin(115200);
  // Iniciar la conexion a la red Wifi
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  var_poten = 0;
}

void loop() {
  
  var_poten = analogRead(A0);
  Serial.println(var_poten);

  ubidots.add("var_poten", var_poten);

  bool bufferSet = false;
  bufferSet = ubidots.send();

  if(bufferSet){
    Serial.println("Values sent by the divice");
  }
  delay(1000);
}

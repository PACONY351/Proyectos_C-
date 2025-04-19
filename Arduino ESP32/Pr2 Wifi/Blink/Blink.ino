#include <ESP8266WiFi.h>
#include <Ticker.h>

// Definir pines a variables
#define ledWifi 2

// Parametros de conexion
String ssid = "IZZI-C84D";
String password = "50955127C84D";

// Declarar procesos
Ticker tic_WifiLed;

byte cont = 0;
byte max_intentos = 50;

// Funciones
void parpadeoLedWifi(){
  byte estado = digitalRead(ledWifi);
  digitalWrite(ledWifi, !estado);
}


void setup() {
  
  // Declarar tipo de pines
  pinMode(ledWifi,OUTPUT);
  
  // Inicia Serial
  Serial.begin(115200);
  Serial.println("\n");

  // Iniciar procesos con funciones
  tic_WifiLed.attach(0.2,parpadeoLedWifi);

  // Conexión WIFI
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED and cont < max_intentos) { //Cuenta hasta 50
    cont++;
    delay(500);
    Serial.print(".");
  }

  if (cont < max_intentos) {  //Si se conectó
    Serial.println("\n**********************************************");
    Serial.println("Conectado a la red WiFi: ");
    Serial.println(WiFi.SSID());
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("macAdress: ");
    Serial.println(WiFi.macAddress());
    Serial.println("**********************************************");
  }
  else { //No se conectó
    Serial.println("--------------------------------------------------");
    Serial.println("Error de conexion");
    Serial.println("--------------------------------------------------");
  }

  // Fin de los procesos con funciones
  tic_WifiLed.detach();
  digitalWrite(ledWifi,HIGH);
}

void loop() {
}

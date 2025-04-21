// Librerías
#include <Ubidots.h>
#include <Servo.h>

// Clave y red
#define UBIDOTS_TOKEN "BBUS-NtBXDgeRZAniKmWWYyy508FERbab5i"
#define DEVICE_LABEL "ejc-main-esp8266"
#define WIFI_SSID "IZZI-C84D"
#define WIFI_PASS "50955127C84D"

// Pines
#define LAB_LED "led"
#define LAB_SER "serv"
#define LAB_TEMP "temp"
#define LAB_HUME "hume"

#define TRIG_PIN 14    // D5
#define ECHO_PIN 12    // D6
#define PIN_LED 0      // D3
#define PIN_SER 5      // D1

// Objetos
Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);
Servo mot;

// Variables globales
float temp = 0;
int hume = 0;
int serv = 0;
int led = 0;
long duracion = 0;

// Temporizador
unsigned long lastUbidots = 0;
const unsigned long intervalo = 5000;

void setup() {
  Serial.begin(115200);

  // Conexión WiFi
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  Serial.println("Conectado a WiFi");

  // Pines
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  mot.attach(PIN_SER);
  mot.write(0);  // Posición inicial
}

void loop() {
  // Leer temperatura desde LM35 (A0)
  int lectura = analogRead(A0);
  float voltaje = lectura * (3.3 / 1023.0); // si A0 usa 3.3V
  temp = voltaje * 100.0;

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println(" °C");

  // Leer distancia desde HC-SR04
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duracion = pulseIn(ECHO_PIN, HIGH);
  hume = duracion * 0.0343 / 2;  

  Serial.print("Distancia: ");
  Serial.print(hume);
  Serial.println(" cm");

  // Evita sobrecargar: solo cada 5 segundos hacemos get/send
  if (millis() - lastUbidots > intervalo) {
    lastUbidots = millis();

    // Leer valores desde Ubidots
    serv = ubidots.get(DEVICE_LABEL, LAB_SER);
    if (serv != ERROR_VALUE) {
      Serial.println("Servo: " + String(serv));
      mot.write(serv);
    } else {
      Serial.println("Error de lectura SERVO");
    }

    led = ubidots.get(DEVICE_LABEL, LAB_LED);
    if (led != ERROR_VALUE) {
      Serial.println("LED: " + String(led));
      digitalWrite(PIN_LED, led);
    } else {
      Serial.println("Error de lectura LED");
    }

    // Enviar datos a Ubidots
    ubidots.add(LAB_TEMP, temp);
    ubidots.add(LAB_HUME, hume);
    ubidots.add(LAB_LED, led);
    ubidots.add(LAB_SER, serv);

    bool bufferSet = ubidots.send(DEVICE_LABEL);
    if (bufferSet) {
      Serial.println("Datos enviados a Ubidots");
    }

    // Mostrar memoria libre
    Serial.print("Memoria libre: ");
    Serial.println(ESP.getFreeHeap());
  }

  delay(200);  // Espera pequeña entre loops
}

#include <UbidotsESPMQTT.h>
#include <Servo.h>

// === CONFIGURACIONES === //
#define UBIDOTS_TOKEN "BBUS-NtBXDgeRZAniKmWWYyy508FERbab5i"
#define DEVICE_LABEL "ejc-main-esp8266"
#define WIFI_SSID "IZZI-C84D"
#define WIFI_PASS "50955127C84D"

// === ETIQUETAS UBIDOTS === //
#define LAB_LED "led"
#define LAB_SER "serv"
#define LAB_TEMP "temp"
#define LAB_HUME "hume"

// === PINES FÍSICOS === //
#define TRIG_PIN 14   // D5
#define ECHO_PIN 12   // D6
#define PIN_LED 0     // D3
#define PIN_SER 5     // D1

// === OBJETOS === //
Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);
Servo mot;

// === VARIABLES === //
float temp = 0;
int hume = 0;
int serv = 0, prev_serv = -1;
int led = 0, prev_led = -1;
unsigned long lastSend = 0;
const unsigned long sendInterval = 5000;

void setup() {
  Serial.begin(115200);

  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  Serial.println("WiFi conectado");

  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  mot.attach(PIN_SER);
  mot.write(0);
}

void loop() {
  leerTemperatura();
  leerDistancia();

  if (millis() - lastSend >= sendInterval) {
    lastSend = millis();
    leerUbidots();
    enviarUbidots();
  }
}

// === FUNCIONES === //

void leerTemperatura() {
  int lectura = analogRead(A0);
  float voltaje = lectura * (3.3 / 1023.0);  // ESP8266 usa 3.3V
  temp = voltaje * 100.0;

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.println(" °C");
}

void leerDistancia() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duracion = pulseIn(ECHO_PIN, HIGH, 30000);  // timeout 30ms
  if (duracion == 0) {
    hume = -1;  // Sin lectura
  } else {
    hume = duracion * 0.0343 / 2;
  }

  Serial.print("Distancia: ");
  Serial.print(hume);
  Serial.println(" cm");
}

void leerUbidots() {
  serv = ubidots.get(DEVICE_LABEL, LAB_SER);
  if (serv != ERROR_VALUE && serv != prev_serv) {
    Serial.println("Servo actualizado: " + String(serv));
    mot.write(serv);
    prev_serv = serv;
  }

  led = ubidots.get(DEVICE_LABEL, LAB_LED);
  if (led != ERROR_VALUE && led != prev_led) {
    Serial.println("LED actualizado: " + String(led));
    digitalWrite(PIN_LED, led);
    prev_led = led;
  }
}

void enviarUbidots() {
  ubidots.add(LAB_TEMP, temp);
  ubidots.add(LAB_HUME, hume);
  ubidots.add(LAB_LED, led);
  ubidots.add(LAB_SER, serv);

  bool success = ubidots.send(DEVICE_LABEL);
  Serial.println(success ? "✅ Datos enviados" : "❌ Error al enviar");
  Serial.print("Memoria libre: ");
  Serial.println(ESP.getFreeHeap());
}

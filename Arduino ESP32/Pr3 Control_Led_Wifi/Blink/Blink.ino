#include <ESP8266WiFi.h>
#include <Ticker.h>

// Definir pines a variables
#define ledWifi 2
#define ledWeb 12

// Parametros de conexion
String ssid = "IZZI-C84D";
String password = "50955127C84D";

// Crear servidor
WiFiServer server(80); //objeto de la clase WiFi
int estado = 0; //axiliar del estado del servidor

// Declarar procesos
Ticker tic_WifiLed;


// Funciones
void parpadeoLedWifi(){
  byte estado = digitalRead(ledWifi);
  digitalWrite(ledWifi, !estado);
}


void setup() {
  
  // Declarar tipo de pines
  pinMode(ledWifi,OUTPUT);
  pinMode(ledWeb,OUTPUT);
  
  // Inicia Serial
  Serial.begin(115200);
  Serial.println("\n");

  // Iniciar procesos con funciones
  tic_WifiLed.attach(0.2,parpadeoLedWifi);

  // Conexión WIFI
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { //siempre estara tratando de conectar a internet
    delay(500);
    Serial.print(".");
  }

    Serial.println("\n**********************************************");
    Serial.println("Conectado a la red WiFi: ");
    Serial.println(WiFi.SSID());
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("macAdress: ");
    Serial.println(WiFi.macAddress());
    Serial.println("**********************************************");


  // Fin de los procesos con funciones
  tic_WifiLed.detach();
  digitalWrite(ledWifi,HIGH);

  // Inicializando el servidor
  server.begin(); //begin() levanta el servidor
  digitalWrite(ledWeb, 0);
}

void loop() {

  // Crear objeto WiFiClient tipo client
  WiFiClient client = server.available(); //buscara en el servidor un cliente disponible
  
  // Condicion para brincar el loop
  if(!client){
    return; // brinca loop 
  }
  
  // Ciclo para esperar el cliente
  Serial.println("Nuevo cliente...");
  while(!client.available()){ //esperando cliente disponible
    delay(1);
  }
  
  String peticion = client.readStringUntil('\r'); //lee la peticion del cliente
  Serial.println(peticion);
  client.flush(); //limpia la peticion del cliente

  if(peticion.indexOf('LED=ON') != -1)
    estado = 1;
  if(peticion.indexOf('LED=OFF') != -1)
    estado = 0;

  digitalWrite(ledWeb, estado);

  client.println("HTTP/1.1 200 OK");
  client.println("");
  client.println("");
  client.println("");
  client.println("");

  // Inicia la pagina

  client.println("<!DOCTYPE html>");
  client.println("<html lang='en'>");
  client.println("<head>");
  client.println("<meta charset='utf-8'>");
  client.println("<meta name='viewport' content='width=device-width, initial-scale=1'>");
  client.println("<title>Bootstrap LED</title>");
  client.println("<link href='https://cdn.jsdelivr.net/npm/bootstrap@5.3.5/dist/css/bootstrap.min.css' rel='stylesheet' integrity='sha384-SgOJa3DmI69IUzQ2PVdRZhwQ+dy64/BUtbMJw1MZ8t5HZApcHrRKUc4W0kG879m7' crossorigin='anonymous'>");
  client.println("</head>");
  client.println("<body>");
  client.println("<div class='container'>");
  client.println("<div class='row d-flex justify-content-center align-items-center vh-100'>");
  client.println("<div class='col-4'>");
  client.println("<div class='card' style='width: 18rem;'>");
  client.println("<img src='https://static.vecteezy.com/system/resources/thumbnails/026/797/983/small_2x/led-bulbs-transparent-png.png' class='card-img-top' alt='LED'>");
  client.println("<div class='card-body'>");
  client.println("<h5 class='card-title'>LED</h5>");
  client.println("<p class='card-text'>Este LED está siendo controlado a partir de un ESP8266 WiFi.</p>");
  client.println("<div class='row'>");
  client.println("<div class='col-6'>");
  client.println("<a href='/LED=ON' class='btn btn-primary m-2'>Prender</a>");
  client.println("</div>");
  client.println("<div class='col-6'>");
  client.println("<a href='/LED=OFF' class='btn btn-danger m-2'>Apagar</a>");
  client.println("</div>");
  client.println("</div>"); // row
  client.println("</div>"); // card-body
  client.println("</div>"); // card
  client.println("</div>"); // col-4
  client.println("</div>"); // row
  client.println("</div>"); // container
  client.println("<script src='https://cdn.jsdelivr.net/npm/bootstrap@5.3.5/dist/js/bootstrap.bundle.min.js' integrity='sha384-k6d4wzSIapyDyv1kpU366/PK5hCdSbCRGRCMv+eplOQJWyd1fbcAu9OCUj5zNLiq' crossorigin='anonymous'></script>");
  client.println("</body>");
  client.println("</html>");


  // Termina la pagina

  delay(10);
  Serial.println("Peticion finalizada");
  Serial.println("");

}
  

#include "webServerManager.h"

//Gestion des routes:
void initRootUrls() {
  Serial.println("Initialisation des routes URLs");
  server.on(URL_INDEX, handleRootIndex);
  server.on(URL_VERSION, handleRootVersion);
  server.on(URL_GET_API_VERSION, handleRootApiVersion);
  server.onNotFound(handleNotFound);

  
}

void setup() {
  
  // on ouvre le port pour afficher des informations sur la console
  Serial.begin(SERIAL_MONITOR_BAUD);
  // on se connecte au wifi
  WiFi.begin(ssid, password);
  // on établie la connection wifi
  Serial.println("");
  Serial.println("En attente de connexion");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Affichage des informations du serveur
  displayServerInformation();

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }
  //on initialise les root URL
  initRootUrls();
  // On démarre le serveur
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

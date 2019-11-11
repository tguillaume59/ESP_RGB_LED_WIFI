#include "webServerManager.h"

//Variable de serveur port http (80):
ESP8266WebServer server(80);

//Affiche une page web donnant le numéro de version:
void handleRootVersion() {
  //Serial.println("handleRootVersion");
  server.send(HTTP_SUCCESS, PLAIN_TEXT , "Version 1.0");
}

//Affichage de la page d'accueil:
void handleRootIndex() {
  //Serial.println("handleRootIndex");
  server.send(HTTP_SUCCESS, PLAIN_TEXT, "hello from esp8266!");
}

//Affichage de la version de l'API:
void handleRootApiVersion() {
  //Serial.println("handleRootApiVersion");
  if (server.method() == HTTP_GET) {
    String tParamsValue = server.arg(PRM_VERSION);

    if (PRM_VERSION_VALUE_EXPECTED == tParamsValue) {
      server.send(HTTP_SUCCESS, JSON, "{\"message\": \"Vous êtes sur la version " + mVersion + " du serveur.\", \"version_number\":\"" + mVersion + "\", \"modele\":\"" + mModele + "\"}");
    } else {
      server.send(HTTP_FORBIDDEN, JSON, "{\"error\":\"Api key non reconnue.\"}");
    }
  } else {
    String rMessageErreur = "{\"error\":\"Methode http demandée (";
    rMessageErreur += server.method();
    rMessageErreur += ") non disponible.\"}";
    server.send(HTTP_METHOD_NOT_ALLOW, JSON, rMessageErreur);
  }
}

//Gestion message d'erreur
void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) +
               "\n";
  }
  server.send(HTTP_NOT_FOUND, PLAIN_TEXT, message);
}

void displayServerInformation() {
  Serial.println("");
  Serial.print("Connected to");
  Serial.println(ssid);
  Serial.print("IP adress : ");
  Serial.println(WiFi.localIP());
}

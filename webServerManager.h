#ifndef WEB_SERVER_MANAGER_H_
#define WEB_SERVER_MANAGER_H_

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#define SERIAL_MONITOR_BAUD 115200

extern ESP8266WebServer server;

const String ssid = "[SSID_A_COMPLETER]";
const String password = "[PASSWORD_A_COMPLETER]";
//Url racine:
const String URL_INDEX = "/";
//Paramètres de réponse:
const String PLAIN_TEXT = "text/plain";
const String JSON = "application/json";

//Codes d'erreurs:
const int HTTP_SUCCESS = 200;
const int HTTP_BAD_REQUEST = 400;
const int HTTP_FORBIDDEN = 403;
const int HTTP_NOT_FOUND = 404;
const int HTTP_METHOD_NOT_ALLOW = 405;

const String URL_VERSION = "/version";
const String URL_GET_API_VERSION = "/api/version";

const String PRM_VERSION = "version_api_key";
const String PRM_VERSION_VALUE_EXPECTED = "klciPbrfzH9JHJuI3Iq9dhFEu";
const String mVersion = "1.0";
const String mModele = "Node MCU ESP8266";

void handleRootVersion();
void handleRootIndex();
void handleRootApiVersion();
void handleNotFound();
void displayServerInformation();

#endif

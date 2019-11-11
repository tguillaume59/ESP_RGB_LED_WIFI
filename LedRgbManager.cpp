#include "LedRgbManager.h"

void LedRgbManager :: initManager(){
  Serial.println("LedRgbManager -> initManager");
  pinMode(D1, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D8, OUTPUT);
}

void LedRgbManager :: handleColorLedRgb() {

  Serial.println("LedRgbManager -> handleColorLedRgb");
  
  if (server.method() == HTTP_POST) {
    String tAPiKey = server.arg(PRM_EMBEDDED_LED_RGB_API_KEY);
    if (PRM_EMBEDDED_LED_RGB_API_KEY_VALUE_EXPECTED == tAPiKey) {

      // arguments
      String argRed = server.arg(PRM_EMBEDDED_LED_RGB_RED);
      String argGreen = server.arg(PRM_EMBEDDED_LED_RGB_GREEN);
      String argBlue = server.arg(PRM_EMBEDDED_LED_RGB_BLUE);

      // converti la couleur des arguments
      int red = getRedFromArgs(argRed);
      int green = getGreenFromArgs(argGreen);
      int blue = getBlueFromArgs(argBlue);
      
      // applique la couleur demandée
      setRGBColor(red, green, blue);
      
      server.send(HTTP_SUCCESS, JSON, "{\"status\" : \"ok\"}"); //"{ \"red\" :" + red + ", \"green\" : " + green + ", \"blue\" : " + blue + "}");
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

void LedRgbManager :: setRGBColor(int red, int green, int blue){
  char tampon[100];
  sprintf(tampon,"LedRgbManager -> setRGBColor Red = %d , Green = %d , Blue = %d",red, green, blue);
  Serial.println(tampon);
  digitalWrite(D1, !red); 
  digitalWrite(D5, !green); 
  digitalWrite(D8, !blue); 
}

int LedRgbManager :: getRedFromArgs(String argument){
  return argument.toInt();
}
int LedRgbManager :: getGreenFromArgs(String argument){
  return argument.toInt();
}

int LedRgbManager :: getBlueFromArgs(String argument){
  return argument.toInt();
}

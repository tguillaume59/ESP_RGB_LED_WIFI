#ifndef LED_RGB_MANAGER_H
#define LED_RGB_MANAGER_H
#include "webServerManager.h"

const String PRM_EMBEDDED_LED_RGB_API_KEY = "embedded_led_rgb_api_key";
const String PRM_EMBEDDED_LED_RGB_API_KEY_VALUE_EXPECTED = "iYCFjYE4tTnpiJJ6psf4axjTN";
const String PRM_EMBEDDED_LED_RGB_RED = "red";
const String PRM_EMBEDDED_LED_RGB_GREEN = "green";
const String PRM_EMBEDDED_LED_RGB_BLUE = "blue";
const String URL_POST_COLOR_LIGHT = "/api/led_rgb";

class LedRgbManager{

  private : 

  int getRedFromArgs(String argument);
  int getGreenFromArgs(String argument);
  int getBlueFromArgs(String argument);

  public : 

  void initManager();
  void handleColorLedRgb();
  void setRGBColor(int red, int green, int blue);
  
};
#endif

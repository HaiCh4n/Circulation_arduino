#include "lights.h"
#include "config.h"

void setCarLights(bool red, bool yellow, bool green) {
  digitalWrite(carRed,    red    ? HIGH : LOW);
  digitalWrite(carYellow, yellow ? HIGH : LOW);
  digitalWrite(carGreen,  green  ? HIGH : LOW);
}

void setPedLights(bool red, bool green){
  digitalWrite(pedRed,   red   ? HIGH : LOW);
  digitalWrite(pedGreen, green ? HIGH : LOW);
}

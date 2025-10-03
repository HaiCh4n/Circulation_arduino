#include "button.h"

bool buttonPressed(int pin) {
  // Debounce cạnh nhấn (HIGH -> LOW) đơn giản
  static int lastStable = HIGH;
  static int lastRead   = HIGH;
  static unsigned long lastChange = 0;
  const unsigned long DEBOUNCE_MS = 25;

  int reading = digitalRead(pin); // INPUT_PULLUP: bấm = LOW

  if (reading != lastRead) {
    lastRead = reading;
    lastChange = millis();
  }

  if (millis() - lastChange > DEBOUNCE_MS) {
    if (reading != lastStable) {
      lastStable = reading;
      if (lastStable == LOW) {   // phát hiện cạnh nhấn
        return true;
      }
    }
  }
  return false;
}

bool smartWait(unsigned long ms, int pin) {
  unsigned long start = millis();
  bool pressed = false;
  while (millis() - start < ms) {
    if (buttonPressed(pin)) pressed = true;   // ghi nhận đã bấm ít nhất 1 lần
    delay(5); // thở nhẹ cho CPU và vẫn nhạy
  }
  return pressed;
}

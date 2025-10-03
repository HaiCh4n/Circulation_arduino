#pragma once
#include <Arduino.h>

// Trả về true nếu phát hiện NHẤN (INPUT_PULLUP: bấm = LOW) với debounce
bool buttonPressed(int pin);

// Chờ ms mili-giây nhưng vẫn "nghe" nút pin; 
// nếu trong thời gian chờ có bấm lần nào → trả về true
bool smartWait(unsigned long ms, int pin);

#pragma once

// Pins
const int carRed    = 2;
const int carYellow = 3;
const int carGreen  = 4;
const int pedGreen  = 5;
const int pedRed    = 6;
const int Nut       = 7;   // nút bấm: 1 chân về pin 7, chân còn lại về GND (INPUT_PULLUP)

// Durations (milliseconds)
const unsigned long T_GREEN  = 8000;  // xe xanh 8s
const unsigned long T_YELLOW = 2000;  // xe vàng 2s
const unsigned long T_RED    = 10000; // xe đỏ 10s

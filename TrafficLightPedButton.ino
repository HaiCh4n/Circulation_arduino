#include "config.h"
#include "lights.h"
#include "button.h"

bool requestPed = false; // đã có yêu cầu qua đường chưa?

void setup() {
  pinMode(carRed,    OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen,  OUTPUT);
  pinMode(pedGreen,  OUTPUT);
  pinMode(pedRed,    OUTPUT);

  pinMode(Nut, INPUT_PULLUP);   // kéo lên nội bộ: thả = HIGH, bấm = LOW

  // Trạng thái mặc định: xe XANH, người ĐỎ (đỏ bật, xanh tắt)
  setCarLights(false, false, true);
  setPedLights(true, false);
}

void loop() {
  // --- Pha XANH: xe xanh 8s, người mặc định ĐỎ ---
  setCarLights(false, false, true);
  setPedLights(true, false);
  if (smartWait(T_GREEN, Nut)) requestPed = true;  // ghi nhận nút nếu có

  // --- Pha VÀNG: 2s, người vẫn ĐỎ ---
  setCarLights(false, true, false);
  setPedLights(true, false);
  if (smartWait(T_YELLOW, Nut)) requestPed = true;

  // --- Pha ĐỎ: 10s ---
  setCarLights(true, false, false);
  if (requestPed) {
    // đã bấm trước đó -> người đi bộ XANH bật, ĐỎ tắt trong suốt pha đỏ
    setPedLights(false, true);
  } else {
    // chưa bấm -> người giữ mặc định (ĐỎ bật)
    setPedLights(true, false);
  }
  smartWait(T_RED, Nut);

  // Hết đỏ: xóa yêu cầu, trả người về mặc định (ĐỎ bật, XANH tắt)
  requestPed = false;
  setPedLights(true, false);

  // lặp lại: về xanh ở đầu vòng sau
}

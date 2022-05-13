#include <Keyboard.h>
#include <Keyboard_sv_SE.h>

void setup() {
  Keyboard.begin(KeyboardLayout_sv_SE);
  delay(1000);
  
  // Open run
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.write('r');
  Keyboard.releaseAll();
  delay(500);

  // Edit the registry
  String s = "reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\" /v Shell /t REG_SZ /d \"\"\"\"C:/Program Files (x86)/Microsoft/Edge/Application/msedge.exe\"\"\" --no-default-browser-check --kiosk https://www.geogebra.org/classic\" /f";
  for (char c : s)
  {
    Keyboard.write(c != '\\' ? c : KEY_ACUTE_ACC);
    delay(30);
  }
  
  // Execute
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000);

  // Authorise using credentials
  Keyboard.press(KEY_LEFT_ARROW);
  Keyboard.release(KEY_LEFT_ARROW);
  Keyboard.press(KEY_RETURN);
  Keyboard.release(KEY_RETURN);
}

void loop() {}

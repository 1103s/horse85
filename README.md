# horse85

This repo contains data for various horse85 shenanigans.

**horese.ino** - A HID attack that changes the default windows device sound to
something better. The effects of horse.ino can be undone by editing
the registry and copping the value of:
 ```
 HKEY_CURRENT_USER\AppEvents\Schemes\Apps.Default\DeviceDisconnect.Default`
 ```
to:
```
HKEY_CURRENT_USER\AppEvents\Schemes\Apps.Default\DeviceDisconnect.Current`
```
This is based off of code from [here](https://github.com/sridharas04/windows_usb_scream_prank).

**element.ino**  - A HID attack that plays some bops and updates your computer.
There are no persistent effects.
This is based off of code from [here](https://github.com/CedArctic/DigiSpark-Scripts).

_idk whatever newpatch comes up with....._

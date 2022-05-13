# GeoGebrify
A prank script for making a Windows machine boot directly to GeoGebra.

After all, computers are just fancy calculators.

The program is built for the Makey Makey, but will most likely work with any ATMEGA USB device that supports keyboard functionality.

## How to use it
Download this file, and open it in the Arduino IDE. Connect your device, and select the board type and COM port in the IDE. Do the necessary modifications, and upload the code.

Simply connect the device to any logged in Windows computer to use this program. Please note that it will only work if the logged in user has administrative privileges.

Optionally, reboot the computer to see the effect immediately.

## How it works
When a Windows computer boots, it starts the shell program. By default this is `explorer.exe`, and it handles basic things like the taskbar, desktop and start menu.
This, however, can be changed in the registry. This script sends the keystrokes for the following registry command.
```
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon" /v Shell /t REG_SZ /d """"C:\Program Files (x86)\Microsoft\Edge\Application\msedge.exe""" --no-default-browser-check --kiosk https://www.geogebra.org/classic" /f
```
This changes to key `HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon\Shell` to Microsoft Edge, which is the only browser that we can reliably use, since it is preinstalled.
Furthermore, it uses two options: `--kiosk` and `--no-default-browser-check`. While the latter is self-explainatory, the first launches Edge in full screen, without toolbar, and in a way so that this fullscreen cannot be exited. 
Though, you can still create new tabs using <kbd>CTRL</kbd> + <kbd>T</kbd> and navigate between these using <kbd>CTRL</kbd> + <kbd>TAB</kbd>.

This script first starts run by hitting <kbd>WIN</kbd> + <kbd>R</kbd>.
Then it writes the command and hits <kbd>CTRL</kbd> + <kbd>SHIFT</kbd> + <kbd>Enter</kbd>. This runs the command as administrator.
To authorise this, the script clicks the `yes` button by sending a left arrow and then enter.

## Customising it
This script is built for a Norwegian keyboard. It must be keyboard layout specific, due to how sending keystrokes works. It is currently based on the Swedish keyboard, but replacing `\` with a grave accent.
To use a Swedish keyboard, simply remove the ternary for this substitution.

To use another, choose one of the following ones as a base.
- KeyboardLayout_da_DK: Denmark
- KeyboardLayout_de_DE: Germany
- KeyboardLayout_en_US: USA
- KeyboardLayout_es_ES: Spain
- KeyboardLayout_fr_FR: France
- KeyboardLayout_it_IT: Italy
- KeyboardLayout_sv_SE: Sweden

Then, you will have to hard-code replacements for any keys that do not match these layouts.

If the hardware you want to target is particularly slow, you might want to look at increasing the timings between the different executions.
Do not, however, make them to low, as it can cause the text to be written before run is ready. Too little delay between keystrokes in the string could cause the order to be wrong, or some keystrokes to be dropped.

Optionally, you can add a reboot at the end, by opening run again after a wait, and entering the following command followed by an enter. This will cause the effect to start immediately.
```
shutdown -t 0 -r
```

## How to get rid of it
Either if you fell victim to this prank, or ran it on yourself, this can easily be reversed by changing the registry value back to `explorer.exe`.
This can be done either through a command, or graphically in `regedit`.

This is a step-by-step guide for how to reset this from the edge shell environment.
- First, open task manager. Do this by hitting <kbd>CTRL</kbd> + <kbd>SHIFT</kbd> + <kbd>ESC</kbd>.
- Open run from within task manager by going to File > Run new task.
- Write the following command into run.
```
reg add "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon" /v Shell /t REG_SZ /d "explorer.exe" /f
```
- Select the checkbox for "Create this task with administrative privilegies." and hit <kbd>ENTER</kbd>
- The prank should now be reversed.
- Reboot to get the normal explorer shell back. This can be done by reopening run and executing the following, or by hitting the power button.
```
shutdown -t 0 -r
```

And remeber, never leave your computer unlocked and untattended.

It is good practise to always lock it before leaving it. Simply hit <kbd>WIN</kbd> + <kbd>L</kbd>.

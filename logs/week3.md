---
sort: 4
---

# Week3

## Logs from June 4 to June 11

- Flashed a vanilla debian image on SD card and booted the BBB from it.
- Used the script made by Robert nelson to update to the latest xenomai patched image. ```Linux beaglebone 4.14.108-ti-xenomai-r143 #1buster SMP PREEMPT Thu May 27 21:23:48 UTC 2021 armv7l GNU/Linux```
- Installed Xenomai libraries. (I have put all my steps and errors faced on slack chat) 
- Tried source compiling Bela, but failed. I have put up the issues on gsoc Slack.
- The BBAI arrived on 8th June 2021. 
- ssh-ed into the out-of-the-box image and updated and upgraded it, which is on the emmc. 
- Flashed latest Debian IOT buster image into a 32GB SD card and booted the BBAI from it.
- Figured out how to get internet connectivity on the beaglebones. (I had to use an old router as a wifi repeater and then hook up the 2 BB's via ethernet cable to the repeater router and thus I could ssh into the BB's via my LAN itself and also got them connected online.)
- Ran Robert Nelson's update script and got xenomai patched kernel running.
- Installed Xenomai Libraries on the BBAI and ran the latency test (which also worked). 
- Cloned the development Bela Repo. 

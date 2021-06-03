---
sort: 3
---

# Week2
## Logs from May 27 to June 3
- Bela Cape with Trill Sensors has shipped from London. (ETA Jun 2)
- Made a few improvements in the earlier Makefile Blog.
- Comparing the McSPI pins in both the Ref. Manuals of AM57x and AM33x. 
- Started going through core/PRU.cpp. 
- Listed all the libprussdrv functions currently in use. 
- Started looking for corresponding functions in rproc. 
- Everything is documented under the blog I maintain, under syntax-notes.md
- The BeagleBone Black arrived today morning. 
    - Booted it out-of-the box, and was unsuccessful to ssh into it via Linux Mint (Probably some driver issues.)
    - Successfully ssh-ed into it via Ubuntu DDE, and then explored the default out-of-the-box debian. 
    - Put the latest BELA image onto it via SD card. Failed to boot via SD card by following the normal method. 
    - Detailed steps can be found [here](../General.md) under the Setting up your BeagleBone section. 
- Flashed BELA image on SD card and booted BBB from it. Expanded it to use the entire 32GB. 
- Cloned the development fork of the BELA Repo onto the board and built it. 
<br> Encountered some warning messages and then fixed them and pushed them. The changes were made to RTAudio.cpp and Board_detect.cpp files. 
- Robert nelson suggested how to use his script update_kernel.sh, and then also said: `4_14 is pretty well tested.. 4_19/5_4 was just did for Bela a month ago, haven't really heard any feedback on pro/con's` <br> 
Then, when I asked about testing on the BBAI, reply was, "Nope, i haven't... it should boot.. wifi is probally broken.."

# General Overview of BeagleBoards
Before we dive into the world of [BeagleBoard](https://beagleboard.org/), we need to get a few jargon and basic concepts out of our way first!


Let's have a look at _when_ one should consider using the Beagle Boards. <br>
The Beagle boards are perfectly placed for the integration of high-level software and low-level electronics in any type of project. <br>
The major advantage over more traditional embedded systems, such as the Arduino, PIC, and AVR microcontrollers, is apparent when you leverage the Linux OS for your projects. For example, if you built a home automation system using the BeagleBone and you then decided that you wanted to make certain information available on the internet, you could simply install a web server.

## Setting up the BeagleBone

The BeagleBone Black was one of the first ever BeagleBoards I have had, and it was a bit of a hassle for me to set it up initially. Few things to keep in mind here. 
1. I was using _Linux Mint 20.1 x86_64 , DE: Cinnamon_. For some reason, wired network connections were not working for me, neither ethernet nor USB. I had to serially get into the BBB to see if it was actually working atall. I then switched to dual booted Ubuntu DDE wherein I was easily able to open the cloud-9 IDE and then went on to ssh into it via the terminal. 
2. The next challenge I found was that I was unable to actually boot it up from the external SD card. I was following the standard procedure: Power off board > Put in SD Card > Hold the USR button > Power on board > Flashing should start and take maximum upto 45 minutes. however, this lead to no luck as the board was still booting from the EMMC. Afterwards, my mentor helped me with finding [this link](https://learn.bela.io/using-bela/about-bela/troubleshooting-guide/#problems-booting-bela-from-the-sd-card) following which I erased the boot partition of onboard emmc and forced boot from external SD card. This worked fine and the board booted up from the BELA Image that I had flashed on the SD card. 
3. Next, I realized the reason why eMMC wasn't being flashed by the SD card, it was because I had missed a small step, where one has to edit the ``/boot/uEnv.txt`` file and uncomment the last line. After doing that, I was finally able to flash the eMMC with the latest debian image. 
4. I was also looking out for how I could utilize the entire space on my 32 GB SD Card, as bu default it was only using about 4 GB. So I followd these steps from [here](https://elinux.org/Beagleboard:Expanding_File_System_Partition_On_A_microSD):
    1. Follow most of the steps as it says, make sure you are **booted from the SD Card** and __not__ on board EMMC.
    2. One thing you may be asked is: 
```
    Created a new partition 1 of type 'Linux' and of size 29.7 GiB.
    Partition #1 contains a ext4 signature.
    Do you want to remove the signature? [Y]es/[N]o:N
        
```
    Where you have to type in N and press enter. 

    3. `reboot` after everything is done.
    4. Now don't forget ``resize2fs /dev//mmcblk0p1`` as root and you'll get a similar output: 

```
    resize2fs 1.43.4 (31-Jan-2017)
    Filesystem at /dev//mmcblk0p1 is mounted on /; on-line resizing required
    old_desc_blocks = 1, new_desc_blocks = 4
    The filesystem on /dev//mmcblk0p1 is now 7790720 (4k) blocks long.
```

    5. now you will see that you will be using the full SD card storage. 

## Keywords

Some keywords to remember:-
* **Preemption**: In computing, preemption is the act of temporary interruption of an executing task, with the intention of resuming that at a time later.

* **McASP** is an acronym for Multichannel Audio Serial Port, a communication peripheral found in Texas Instruments family of digital signal processors.  McASP functions as a general-purpose audio serial port.

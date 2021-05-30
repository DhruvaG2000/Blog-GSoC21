# Short notes for the BBAI
This includes everything from linux filestructure, the boot process, accessing the PRUs, and much more! You can find all the important links, references and resources for making your projects with the BBAI.  Hope you find this helpful!  
Most of my reference was the book _Exploring BeagleBone. Tools and Techniques for Building with Embedded Linux by Derek Molloy_, so be sure to check it out as well!

# Table of Contents
1. [Introduction](#Introduction)
    - [What is the BeagleBone® AI?](#bbai-intro)
2. [General Overview](General.md)
    - [Official Documentation Sources](#official-docs)
    - [Capes](#ca)
    - [LED Blink!](#onboardLEDS)
3. [Embedded Linux Systems](#Embedded-Linux-Systems)
    - [Bootloaders](#bootloaders)
    - [Kernel Space and User Space](#kernel-and-user-space)
4. [Practical Beagle Board Programming](#Board-Programming)
5. [Interfacing to the Beagle Board](#Interfacing)
    - [Interfacing to the Beagle Board I/Os](#ios)
    - [Interfacing to the Beagle Board buses](#buses)
    - [Real-Time Interfacing with the PRU-ICSS](#PRU)
    - [The Remote Processor Framework](#remoteproc)
6. [Bela](bela/main.md)
7. [References](#ref)
8. [Additional Help](#help)

**[My Project weekly logs can be found here](logs.md)**

## Introduction to beagleboard and the BeagleBone® AI <a name="Introduction"></a>
[The BeagleBoard](General.md) has been arround since 2008 and is a low-power open-source single-board computer produced by Texas Instruments in association with Digi-Key and Newark element14. It was designed with open source software development in mind.

### [What is **BeagleBone® AI**?](https://beagleboard.org/ai) <a name="bbai-intro"></a>
- BeagleBone® AI fills the gap between small SBCs and more powerful industrial computers.
- It has the the ***TI C66x digital-signal-processor (DSP) cores*** and ***embedded-vision-engine (EVE) cores*** that makes it easy to explore how artificial intelligence (AI) can be used in everyday life.

## General Overview of BeagleBoards <a name="Overview"></a>
Before we dive into the world of BeagleBoard, we need to get a few jargon and basic concepts out of our way first!
Let's have a look at when one should consider using the Beagle Boards. \
The Beagle boards are perfectly placed for the integration of _high-level_ software and _low-level_ electronics in any type of project.\
The major _advantage_ over more traditional embedded systems, such as the Arduino, PIC, and AVR microcontrollers, is apparent when you leverage the **Linux OS** for your projects.\
For example, if you built a home automation system using the BeagleBone and you then decided that you wanted to make certain information available on the internet, you could simply install a web server. Linux also provides you with device driver support for many USB peripherals and adapters, making it possible for you to connect cameras, Wi-Fi adapters, and other low-cost consumer periph-erals directly to your platform.

### BeagleBone Official Documentation <a name="official-docs"></a>
- The BeagleBoard.org website: This provides the main support for this platform, with software guides, community links, and downloads
- [Sitara AM5729 ARM Cortex-A15 Technical Reference Manual (TRM):](https://www.ti.com/lit/pdf/spruhz6) this document contains anything you could possibly want to know about the internal workings of the AM5729.
- [BeagleBone AI System Reference Manual:](https://github.com/beagleboard/beaglebone-ai/wiki/System-Reference-Manual) This is the core document that describes the BeagleBone Black hardware.

### Capes <a name="capes"></a>
Capes are daughter boards that can be attached to the P8/P9 expansion headers on the BeagleBone boards. You can connect up to four capes at any one time when the capes are compatible with each other. Here, we will mostly be focusing on the Robotics Cape and the Bela Cape (both of which will be coming up subsequently to support the BBAI).

### On-Board LEDs <a name="onboardLEDS"></a>
To understand how to control the hardware pins of the BB Boards, let's first start off by understanding how to control the bare minimum on-board LEDs. We have 4 in-built LEDs. But to control this, we need some pre-requisites:
* _Sysfs_ is a virtual file system that provides you with access to devices and drivers that would otherwise be accessible only within a restricted kernel space(refer [here](https://satacker.github.io/posts/beagle_notes/#kernel-space-and-user-space) to understand what is the kernel and user space).
* In the directory ``/sys/class/leds`` You can see the four (green!) LED sysfs mappings—`usr0`, `usr1`, `usr2`, and `usr3`.
* More on this on _Pg. 89 Chap 2:Beagle Software_ in the book _Exploring BeagleBone. Tools and Techniques for Building with Embedded Linux by Derek Molloy_ .  

## Embedded Linux Systems <a name="Embedded-Linux-Systems"></a>
Some good Documentation has been done here: https://satacker.github.io/posts/beagle_notes/, so do read it as well, incase I miss anything.

### Bootloaders <a name="bootloaders"></a>
The Beagle boards use an open source Linux bootloader, called Das U-Boot(“The” Universal Bootloader). (see _Pg 101 Chap3_ for further details on this) .

### Kernel Space and User Space <a name="kernel-and-user-space"></a>
This topic has already been covered under [beagle_notes](https://satacker.github.io/posts/beagle_notes/), So I will not go into much depth.

## Practical Beagle Board Programming <a name="Board-Programming"></a>
CHAP5: TODO

## Interfacing to the Beagle Board <a name="Interfacing"></a>
### Interfacing to the Beagle Board I/Os <a name="ios"></a>
CHAP5: TODO
### Interfacing to the Beagle Board Buses <a name="buses"></a>
CHAP6: TODO

### Real-Time Interfacing with the PRU-ICSS <a name="PRU"></a>

The Programmable Real-Time Unit and Industrial Communication Subsystem (PRU-ICSS) on the Beagle board’s AM57X SoC contains
- Two 32-bitload/store RISC CPU cores- _Programmable Real-Time Units_(PRU0and PRU1).
- 12-KiB program RAM and 8-KiB data RAM per PRU CPU.
- 21 Enhanced General-Purpose Inputs (EGPI) and 21 Enhanced General-Purpose Outputs(EGPO)
- **Interrupt controller (INTC)**: An interrupt controller can be used to notify each PRU that an event has occurred or to notify the host device of events.
- **Scratch pad (SPAD)**: This provides three banks of 30 × 32-bit registers that are shared between the two PRU cores.
- **UART0**: A UART device with a dedicated 192 MHz clock is available on the Beagle board headers.    
The Architecture: \
![image](https://user-images.githubusercontent.com/41233856/116785977-0b96c000-aaba-11eb-8bc7-692d863cfe4e.png) \
Courtesy of the Ti AM572x SRM.

### The Remote Processor Framework <a name="remoteproc"></a>
It allows a main processor that is running Linux to control the slave processors via OS device bindings.
Example:
```sh
$ echo 'stop' > state
$ cat state
> offline
$ echo 'am335x-pru0-fw' > firmware
$ echo 'start' > state
$ cat state
> running
```
In this example, PRU0 is controlled, and the firmware from the ``/lib/firmware/am335x-pru0-fw`` file is loaded into the PRU.
**note:** The PRU must be stopped before you can write new PRU programs.

The [remoteproc framework](https://www.kernel.org/doc/html/latest/staging/remoteproc.html) allows different platforms/architectures to control (power on, load firmware, power off) those remote processors while abstracting the hardware differences, so the entire driver doesn’t need to be duplicated

## References <a name="ref"></a>
- My proposal: Bela compatibility for the BBAI: [proposal](https://elinux.org/BeagleBoard/GSoC/2021_Proposal/bela_on_bbai)
- Official BBAI website: https://beagleboard.org/ai
- [GNU Make](gnu-make-tutorial.md)
- The PRU-ICSS Reference Guide: This document is the main reference for the PRU-ICSS hardware: tiny.cc/beagle1501
- The PRU-ICSS Getting Started Guide on Linux: tiny.cc/beagle1502
- The Processor Messaging Framework: tiny.cc/beagle1505
- BBAI Pins: https://docs.google.com/spreadsheets/d/1fE-AsDZvJ-bBwzNBj1_sPDrutvEvsmARqFwvbw_HkrE/edit#gid=227990209 & [my copy](https://docs.google.com/spreadsheets/d/1h-oUVhZXogOkKJkq73dM1JPOzcslBfcdpxTx4fZ-Cg0/edit?usp=sharing)
- Bela homepage: https://bela.io/
- Robot Control Library: https://beagleboard.org/static/librobotcontrol/index.html  
- [remoteproc framework](https://www.kernel.org/doc/html/latest/staging/remoteproc.html) and [BBB PRUSSv2](https://elinux.org/Ti_AM33XX_PRUSSv2)
- [prussdrv.c](https://github.com/beagleboard/am335x_pru_package/blob/master/pru_sw/app_loader/interface/prussdrv.c)

## Additional Help <a name="help"></a>
* [GNU Make](gnu-make-tutorial.md)


# Bela support for the BBAI

![intro](photos/ProjectReportCoverR1.svg)

This project proposes to provide restructuring and improvement of existing Bela Software Code to allow for compatibility and easier transition to newer Texas Instrument Sitara Processors (like the AM5729 in the BeagleBone AI).

## About
- _Student Name:_ Dhruva Gole
- _Mentors:_ ﻿[Giulio Moro](https://github.com/giuliomoro), Stephen Arnold and Robert Manzke
- _GSoC Entry link:_ [GSoC entry #5697403266531328](https://summerofcode.withgoogle.com/projects/#5697403266531328)
- _Wiki:_ [BB.org forum bela-support-for-bbai](https://forum.beagleboard.org/t/bela-support-for-bbai-later-ti-chips/29257/7)
- _Blog Link:_ [Bela Support for BBAI](https://dhruvag2000.github.io/Blog-GSoC21/) <br>
This project has been done as part of Google Summer of Code 2021 with the BeagleBoard.org Foundation. <br>
- _Youtube_: An Introductory video([click here to view](https://www.youtube.com/watch?v=aVLRUyPBBJk)) has been made to explain the project outline.<br>


## Introduction
As given on the [official website](https://learn.bela.io/get-started-guide/say-hello-to-bela/#what-is-bela), Bela is a hardware and software system for creating beautiful interaction with sensors and sound. Bela originally consisted of a Bela cape on top of a BeagleBone Black computer.
Bela has a lot of analog and digital inputs and outputs for hooking up sensors and controlling other devices, and most importantly Bela has _stereo audio i/o_  allowing you to interact with the world of sound. <br>
Both Bela systems use the same Bela software. It uses a customized Debian distribution which - most notably - uses a '''Xenomai kernel''' instead of a stock kernel. _Xenomai_ is _co-kernel_ for Linux which allows to achieve hard ___real-time performance___ on Linux machines (http://xenomai.org/). It thus takes advantage of features of the BeagleBone computers and can achieve extremely fast audio and sensor processing times. <br>
Although the proposal Title mentions support for AI, I will try to develop a standardized setup that allows an easy jump across all TI chips.

**Applications of Bela:**

Bela is ideal for creating anything interactive that uses sensors and sound. So far, Bela has been used to create:
- musical instruments and audio effects
- kinetic sculptures
- wearable devices
- interactive sound installations
and many more applications that are listed [https://learn.bela.io/get-started-guide/say-hello-to-bela/#what-is-bela here]

Why add support for BBAI/newer TI chips? <br>

The Beagle Black was launched over 7 years ago in 2013 and newer and better TI Sitara Processors have been launched ever since. It would be better to have a more standardized setup that allows an easier jump across TI chips. Soon, newer boards with different and more efficient chips like the AM5X and the TI C66x digital-signal-processor (DSP) cores in the BBAI are coming up that will need to be compatible with the Bela Software and Hardware.
<br>
Programming languages and tools to be used:

_C, C++, PRU, dtb, GNU Make, ARM Assembly_

## Achieved Milestones


1. Created a device tree overlay using [https://elinux.org/Beagleboard:BeagleBone_cape_interface_spec Cape Compatibility layer] to port [https://github.com/beagleboard/bb.org-overlays/blob/master/src/arm/BB-BONE-AUDI-02-00A0.dts BB-BONE-AUDI] overlay to the BBAI. <br>
The Overlay I wrote has been accepted by BeagleBone maintainer Robert Nelson, and you can find it to here: https://github.com/beagleboard/BeagleBoard-DeviceTrees/blob/v4.19.x-ti-overlays/src/arm/overlays/BBAI-AUDI-02-00A0.dts

2. Created a [BBAI-BELA-00A1 device tree overlay](https://github.com/DhruvaG2000/BeagleBoard-DeviceTrees/blob/v4.19.x-ti-overlays/src/arm/overlays/BBAI-BELA-00A1.dts) which helps in setting the right pinmux for BELA.

3. Adapted to the Bela PRU and ARM code and workflow to use the PRU using the [https://www.kernel.org/doc/Documentation/remoteproc.txt Remote Processor Framework] instead of the almost outdated UIO PRUSS.

4. Updated the Bela code to use the McASP, GPIO and McSPI on the AM5729 SoC of the BBAI

5. Installed a Xenomai patched kernel and ran the full Bela stack.

6. I also ported a debugger for PRU called [https://github.com/giuliomoro/prudebug/tree/master PRUDebug] to work on both the PRUSS on board the AM5792.

---
sort: 1
---

# Bela
Bela provides ultra-low latency, high quality audio, analog and digital I/O in a tiny self-contained package.  It also features an on-board IDE that launches right in the browser. </br>
Bela has
- 8 channels of 16-bit analog I/O,
- 16 digital I/O, stereo audio I/O, and
- 2 built-in speaker amplifiers.

Bela runs a custom audio processing environment based on the [Xenomai real-time Linux](https://source.denx.de/Xenomai/xenomai/-/wikis/home) extensions.


## Xenomai Kernel
Xenomai 3 is the new architecture of the Xenomai real-time framework,
which can run seamlessly side-by-side Linux as a co-kernel system, or
natively over mainline Linux kernels.
The _dual kernel core_ is codenamed __Cobalt__, the _native Linux_
implementation is called __Mercury__ .
* [cross-compiling](xenomai/cross-compile.md)
* Robert Nelson's Source for [xenomai kernel for the BBAI](https://github.com/RobertCNelson/ti-linux-kernel-dev/tree/ti-linux-xenomai-4.19.y).
* [script](https://github.com/RobertCNelson/boot-scripts/blob/master/tools/update_kernel.sh) on bbai that allows to install pre-built kernels. use parameter: ``--ti-xenomai-kernel ``, for xenomai kernel.
* [.deb images](https://rcn-ee.com/repos/debian/pool/main/l/linux-upstream/) (linux-headers-4.19.94-ti-xenomai-r60_1bullseye_armhf.deb
onwards... look like a list of xenomai kernels)
**[Remarks:](https://youtu.be/R89TOpdIR0w?t=509)**  
    - scheduler can preempt non-preemptable kernel operations.
    - audio-thread can be set at a higher priority than the kernel.
    - mode switches into kernel mode need to be avoided in the audio thread.

## PRU
The current Bela core code uses pasm to build the PRU assembly pru/pru_rtaudio.p. However both pasm and libprussdrv are now deprecated. They are replaced by [clpru](https://www.embeddedrelated.com/showarticle/603.php) [toolchain](https://beagleboard.org/static/prucookbook/#_compiling_with_clpru_and_lnkpru) and remoteproc driver respectively.

### CLPRU
* The compiler accepts C/C++ source code and assembly code.It produces object code
* The linker combines object files to create object file. The link step is optional,so you can compile and assemble many modules independently and link them later.
**Invoking the C/C++Compiler** <br>
```sh
 clpru [options] [filenames] [--run_linker [link_options] object files]]
 ```
Explanation:
* ``clpru``: Command that runs the compiler and the assembler
* ``options``: ref pg 18 of [this](https://www.ti.com/lit/ug/spruhv7c/spruhv7c.pdf?ts=1621601881422&ref_url=https%253A%252F%252Fduckduckgo.com%252F)

**Alternative to CLPRU** is gcc itself that is available upstream, and has PRU compiler as well built in in the latest release. If gcc works well then we can go ahead with gcc, or else will use clpru.

## References

* [Beaglebone PRU ADC](https://beagleboard.org/p/Greg-R/beaglebone-pru-adc-a42a71)
* https://www.embeddedrelated.com/showarticle/603.php
* https://beagleboard.org/static/prucookbook/#_compiling_with_clpru_and_lnkpru
* https://github.com/alexanderhiam/PRU-stuffs
* https://www.ti.com/lit/ug/spruhv7c/spruhv7c.pdf?ts=1621601881422&ref_url=https%253A%252F%252Fduckduckgo.com%252F

---
sort: 8
---

# Week7

## Logs from July 6 to July 13

- Tested commenting out the `CLOCK_BASE` lines from `pru_rtaudio_irq.p ` to check if the kernel was somehow automatically configuring the clock, but it did not work yet, atleast on the BELA image.

- Implemented and Tested the following functions using PruManagerUIO object in PRU.cpp which was done essentially to test if the code written so far in `PruManager.h`, `PruManager.cpp`, and class PruManagerUIO atleast works, to port the rest of `libprussdrv` functions can be written under it: <br> 
    - [X] `prussdrv_map_prumem()` under 2 seperate functions one for local memory and one for shared. <br>
    - [X] `prussdrv_init()` and <br>
    - [X] `prussdrv_open()` under `PruManagerUio::start()`<br> 
    - [X] `prussdrv_pru_disable()` under `PruManagerUio::stop()`<br>
	- At this point almost the entire prussdrv functions have been shifted to be used (via)prumanager object, and the code can be found on the latest tested and stable branch: [PruManager](https://github.com/giuliomoro/Bela-dhruva/commits/PruManager).

- I also tried _prudebug_ tool. I forked it from [here](https://github.com/giuliomoro/prudebug/tree/master) and made the necessary additions under `pdb` on the [branch bbai](https://github.com/DhruvaG2000/prudebug/blob/bbai). The program compiled fine, and I was also able to drop into the prudebug shell interface, however if I tried any commands like `RESET` or `HALT` then it would throw me out saying `Segmentation fault`. So it seems like it won't be that easy to really port
  prudebug to the BBAI v4.19-xenomai-r64.

- Tried compiling the BELA Repo on BBB v4.19 xenomai, and succeeded. However the programs won't run probably due to a faulty UIO configuration. Will consult mentor on how to solve this issue.

- Created first edition of Makefile that adapts to the new build procedure for the Bela PRU firmware.

- Fix error "Failed to open /dev/i2c-2 I2C Bus" while trying to run an example on BBAI by changing `codecI2cBus` in `include/bela_hw_settings.h` to i2c4

- Was able to port [prudebug to the BBAI](https://github.com/DhruvaG2000/BeagleBoard-exercises/tree/master/pru/prudebug). Each individual asm command being executed can be seen step by step now. I have tested this on a basic blink LED code. (However, maybe it is expected, but the LED doesn't do anything when you are in debug mode ie. does not flash when you single step)

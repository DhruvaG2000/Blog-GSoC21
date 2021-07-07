---
sort: 8
---

# Week7

## Logs from July 6 to July 13

- Tested commenting out the `CLOCK_BASE` lines from `pru_rtaudio_irq.p ` to check if the kernel was somehow automatically configuring the clock, but it did not work yet, atleast on the BELA image.

- Implemented and Tested the following functions using PruManagerUIO object in PRU.cpp which was done essentially to test if the code written so far in `PruManager.h`, `PruManager.cpp`, and class PruManagerUIO atleast works, to port the rest of `libprussdrv` functions can be written under it: <br> 
    - [X] `prussdrv_map_prumem()` under `PruManagerUio::map_pru_mem(unsigned int pru_ram_id, char** address)` <br>
    - [X] `prussdrv_init()` and <br>
    - [X] `prussdrv_open()` under `PruManagerUio::start()`<br> 
    - [X] `prussdrv_pru_disable()` under `PruManagerUio::stop()`<br>

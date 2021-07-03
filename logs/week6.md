---
sort: 7
---

# Week6

## Logs from June 28 to July 7

- Held weekly meet with mentor where we discussed the following: 
    - As discussed in the proposal, the initial workflow idea was to just compile the PRU firmware binary using clpru main.c . However we realised this may not necessarily work as the output file is generally a .out  file that then needs to be linked with the am57x...fw located in /lib/firmware . So then we looked into the Makefile used in Cloud 9 and realised they were using lnkpru on the binary generated from clpru . However, when we tried that we were facing certain errors that we could not immediately fix during the meet. Hence Giulio will help me debug those using his own AI. 
    - Giulio and I discussed the Bela Makefile and decided to integrate rproc in it. He pointed out certain places in the makefile where I should be adding if RPROC....  However this task is on lesser priority for now. 
    - First I have to make sure we  are able to write the correct asm code that will works on AI, and also figure out how to access PRU RAM using existing Mmap code that was sent to me yesterday.
    - We also went through the libprussdrv source files and didn't find much of AM335x specific stuff, which means that it probably will work on the BBAI as well if it is accessing everything via uio, which doesn't rely on device specific hexadecimal addresses. I will be testing that as well. 
    - I will also study the AM57x Tech. Ref. Manual to find out more info about using the clock base. (compare sysclkin1 from device tree file with what it corresponds to in the Manual.) 
    - Also in parallel to this I will write the Bela cape overlay.  
    - Giulio also helped me understand and clear out a few basic doubts I had in the Bela code like I was unable to understand what the PRU.cpp code really does, and how I will be converting all the libprussdrv functions, which funcs are needed, and which are not. I will be also updating the PRU.cpp code to replace some libprussdrv funcs like `prussdrv_exec_...()` and  `prussdrv_pru_disable()` with similar rproc implementation using something that will act like ``echo start>state``  and ``stop state``.

- Tested cloud 9 example `shared.pru1_1.c` and then accessed the PRU ram using Mmap approach where we looked into `/dev/mem` and verified that it works. 

- Tested cloud 9 examples ``blinkR30.pru2_0.c`` and ``blinkR30.pru1_0.c``. However, when I tried asm examples although I could compile them the PRU firmware could not boot the PRU after loading it there for some reason.

- My mentor debugged the earlier issues regarding "the compilation of assembly code, but it did not work on PRU" and has provided logs on the [Bela slack thread here](https://beagleboard.slack.com/archives/C0SLDS49M/p1625160291078200?thread_ts=1621443657.059500&cid=C0SLDS49M).

- Started writing PRU ``start``, ``stop`` and ``load firmware`` code in c++, tested if it works and pushed to repo under the branch `ai-onboard-testing`. The purpose of this branch isn't exactly to be merged with main branch but to just perform quick small tests on the AI and once proven then subsequently a cleaner and proper code will be written in another branch which can later be merged into the main branch. Currently thinking of making a header file for ``PruManager.h`` which will contains all the functions required to manage the PRU via rproc and UIO both.

- An OOP solutions has been discussed with my mentor on slack and exaplained in detail. I have started writing the PruManager header and source file which implements the existing methods of libprussdrv as well as newer RProc approach all under one roof.

- Implemented and Tested the PruManagerUIO::stop() function in PRU.cpp which was done essentially to test if the code written so far: `PruManager.h`, `PruManager.cpp`, and class PruManagerUIO atleast works, so then the rest of `libprussdrv` functions can be written under it.

- Summary of Weekly Meet with mentor on Monday Jul 5: (refer [slack](https://beagleboard.slack.com/archives/C0SLDS49M/p1625558118175700?thread_ts=1621443657.059500&cid=C0SLDS49M) )

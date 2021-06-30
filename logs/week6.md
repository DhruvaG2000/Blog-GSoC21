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

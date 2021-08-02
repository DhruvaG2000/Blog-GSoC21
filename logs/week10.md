---
sort: 11
---

# Week10

## Logs from July 30 to Aug 06

- Wrote "[Running the sinetone example on the BBAI](https://dhruvag2000.github.io/Blog-GSoC21/Bela/example_run.html)" blog.
- Replaced std::map to std::vector approach in PruManager RProc + Mmap part.
- accumulated all the files necessary for the PRU code compilation in one place on the PruManager branch.
- tested the PruManager branch with all the new changes and verified that it works
- Got GPIO working on BBAI + BELA
- Almost got SPI working, small issue faced was that the MOSI and MISO seem to be swapped in the BBB vs BBAI. Have to make those changes in the overlay and also the pru code.
- Got the SPI working as well.
- Next focus is on getting the McASP --> PRU interrupts which would probably be the last milestone for this GSoC.
- MOM with @giuliomoro dated Aug 2, 2021, time: 9:15PM IST to 11:15PM IST:
	- Tried to debug the `rtdm_pruss_irq` driver on the BBAI, but could not find an easy solution yet.
	- Mentor helped me understand the importance of various interrupts, like the PRU -> ARM and MCASP-> PRU interrupts. The main advantage of this approach is that it greatly optimizes CPU usage as it eliminates sleeping threads.
	- The task for next week will be mainly to read up how we can use the `resource_table` file to enable us to do McASP -> PRU interrupts with the help of RProc.
	- It can be said that more than 80% of what was aimed to be done during this GSoC has been achieved so far, and the most crucial of things that remain now is the McASP -> PRU interrupts, which is what I will not be focusing on, while my mentor will later on try to debug the `rtdm pruss iirq` driver.

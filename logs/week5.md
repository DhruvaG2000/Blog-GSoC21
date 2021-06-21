---
sort: 6
---

# Week5

## Logs from June 20 to June 27

- Debugged the new overlay, named [BBAI-AUDI-02-00A0.dts](https://github.com/beagleboard/BeagleBoard-DeviceTrees/blob/v4.19.x-ti-overlays/src/arm/overlays/BBAI-AUDI-02-00A0.dts) and got it working with the AI+Bela cape. It has been merged in the official BeagleBoard-DeviceTrees repo under overlays. This is where I complete all the objectives under my **Milestone 1** ie.
    1. [Introductory YouTube video](https://www.youtube.com/watch?v=kLXCrlQwXeI)
    2. Setting pinmux values appropriately and fix the dt overlay to get the correct clock.
    3. verifying that it works running with ALSA using the BBAI-AUDI-02-00A0.dts overlay.
- Had a weekly meet with mentors where we discussed the following:
    1. My next milestone will be to write the BBAI-BELA-00A1.dts overlay using the CCL.
    2. Simultaneously I will try to study the remote processor framework, and how I can integrate it into the PRU.cpp code. I will mainly lookout for how the memory handling is done using rproc, and explore if rpmesg will be of help to us there.
    3. Try to debug why the decided workflow with regard to the assembly codes isn't working as expected with giuliomoro on the Bela thread.
    4. Check if PRUDebug will work with the BBAI?
    5. The boot logs contain some lines like:
```
 [   68.212976] pruss_uio_shmem 4b200000.pruss_shmem: Allocating gdev
 [   68.275216] pruss_uio_shmem 4b200000.pruss_shmem: Allocating info
 [   68.300721] pruss_uio_shmem 4b200000.pruss_shmem: Requesting resource
 [   68.335290] pruss_uio_shmem 4b200000.pruss_shmem: Mapping resource
 [   68.375328] pruss_uio_shmem 4b200000.pruss_shmem: Registering with uio       driver
 [   68.416160] pruss_uio_shmem 4b200000.pruss_shmem: Saving platform data
 [   68.447651] pruss_uio_shmem 4b280000.pruss_shmem: Allocating gdev
 [   68.471298] pruss_uio_shmem 4b280000.pruss_shmem: Allocating info
 [   68.504399] pruss_uio_shmem 4b280000.pruss_shmem: Requesting resource
 [   68.517567] pruss_uio_shmem 4b280000.pruss_shmem: Mapping resource
 [   68.555376] pruss_uio_shmem 4b280000.pruss_shmem: Registering with uio       driver
 [   68.595980] pruss_uio_shmem 4b280000.pruss_shmem: Saving platform data
```
this probably indicates that there might be a way to still use libprussdrv's memory sharing part atleast, if incase rproc does not support that. Will have to check the user space library for the AI and if not, then how difficult would it be to port the am335 library to am57x? 
    6. Robert M. and giuliomoro also discussed a few things about how ctag could also be able to get support on the AI, which lead me to understand that `pru/pru_rtaudio_irq.p` is actually the asm code for the CTAG. For now though, I will be mainly touching the McASP base addresses inside the asm code and not much else.
    7. Mentors present in today's meet: Stephen Arnold, Giulio Moro, Robert M.

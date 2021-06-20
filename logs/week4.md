---
sort: 5
---

# Week4

## Logs from June 12 to June 19

- Followed instructions from Deepak Khatri's Blog on Cape compat. layer and installed it one the BBAI.
- Tried using alsa to test audio both on BBAI and Black but no audio devices were detected, will need the BB-AUDI-02 overlay probably. 
- On the BB Black, loaded the BB-AUDI-02 overlay from uEnv.txt and then rebooted. After this aplay worked and I got the audio output. 
- Tried the same on the BB AI, however the AI would simply not boot up. After this, tested if uEnv was properly loading the overlays and also if CCL was working or not using the given PWM overlay, and that worked.
- In Xenomai-patched kernels, there are 2 folder in /boot/dtbs and I am not sure exactly which one gets loaded and so where the CCL dtb goes I am not sure.
- Had a meet with Deepak Khatri to discuss CCL and a brief introduction as to how to write overlays for the BBAI. I will now attempt to port the older BB-BONE-AUDI overlay to the AI using the CCL.
- Wrote the first version of the overlay, where I basically just disabled all the required pins just to run a basic check if the overlay will load or not, and it did load alright. Faced challenges when it came to the pinmux part I was constantly getting the error ``FDT_ERR_NOTFOUND``. My mentor suggested I try fdtoverlay next for perhaps improved debugging. 
- So far I have gathered which pins are used by the audio cape and what pin mux configuration I need to use them in. I tested the old dts file made by giuliomoro by compiling it and loading it into ``/boot/dtb/4.19.94-ti-xenomai-r64`` and seems to work even on ``4.19.94-ti-xenomai-r64`` as I tested playing music and got positive results.


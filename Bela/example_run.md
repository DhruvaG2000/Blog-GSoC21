---
sort: 6
---

# Running the sinetone example on the BBAI

**As of 28 Jul 2021**
<br>
[![asciicast](https://asciinema.org/a/427571.svg)](https://asciinema.org/a/427571)
<br>
For the edits in the code part, kindly visit [this link](https://gist.github.com/DhruvaG2000/094dd06a010c0aa890a01e636af4ba3c) and follow the git `diff`'s.

## Pre-req:

- Make sure you are on `4.19.94-ti-xenomai-r64` and have all the libraries in place. ([refer here to do the same](https://dhruvag2000.github.io/Blog-GSoC21/xenomai/install.html))
- [Install the Cape compatibility Layer](https://dhruvag2000.github.io/Blog-GSoC21/Bela/overlay-instructions.html).
- Build, Install and load the BELA Cape overlay from [here](https://github.com/DhruvaG2000/BeagleBoard-DeviceTrees/blob/v4.19.x-ti-overlays/src/arm/overlays/BBAI-BELA-00A1.dts) and for instructions [follow this](https://dhruvag2000.github.io/Blog-GSoC21/Bela/overlay-instructions.html), just that instead of the AUDI overlay, you will be using the BELA overlay.
- It is assumed that you have `prudis` installed on your system from [here](https://github.com/giuliomoro/prudebug/tree/master).
- The [am335x_pru_package](https://github.com/beagleboard/am335x_pru_package) may also need to be installed on your BBAI.
- Highly recommend following this [Bela source-compile walkthrough](https://dhruvag2000.github.io/Blog-GSoC21/Bela/source-compile.html) first to make sure there won't be major dependency issues later on.

## Instructions

- Clone the Bela repo locally on your BBAI using (preferrably in `/root/.`)
```sh
git clone https://github.com/giuliomoro/Bela-dhruva Bela
```

- After this, *first and foremost* you will need to use the `devmem2` tool which can be found in [/resources/bin](https://github.com/giuliomoro/Bela-dhruva/tree/ai-testing/resources/bin). This helps configure the clock, without this step things can go _wrong_ later on. (This will soon be done automatically from the PRU code, but till then this will be necessary.)
```sh
sudo ./devmem2 0x4A005550 w 0x7000002
```

- As of 28 July, the pru code was not fully ready with conditional compiling, hence it was shifted temporarily to a branch named `build_pru` inside which you will find a `tempfolder`
```sh
git checkout build_pru
```
- Now copy this tempfolder where you want outside the Bela repo and then navigate into it. <br>
Now, follow the [README from here](https://github.com/giuliomoro/Bela-dhruva/tree/build_pru/tempfolder#readme) which you will also find inside the tempfolder.

- Once the PRU code is built, then you can come back to the Bela repo you had cloned earlier. <br>
Now, switch to the `ai-testing` branch using
```sh
git checkout ai-testing
```

- Finally, you should create a `projects` folder in `/root/Bela/.` and then copy your choice of example (here I show sinetone) to it. Then, use the command below to build and run the example.
```sh
make PROJECT=sinetone CL=-v run BELA_USE_DEFINE=BELA_USE_POLL firmwareBelaRProc=/home/debian/Bela-dhruva/tempfolder/template.pru1_1.out
```

- If all goes well, then you should see something like:

```sh
Not using McASP->PRU irq
Stopping the PRU
Loading firmware into the PRU1_1
Starting the PRU1_1
_________________Audio Thread!

```

and also be able to hear a sinetone of 440Hz on the AUDIO OUTPUT of the BELA Cape.

- To stop, simply do a `ctrl+C`.


## Contingencies

- run `ldconfig /usr/xenomai/lib/` if you get any `libcobalt` related error
- Is you get any i2d errors, then I suggest using pull up resistors on the I2C pins. (`P_19` and `9_20`)
- you may need to revert [this commit](https://github.com/giuliomoro/Bela-dhruva/commit/bf14f5172e25b0f3b1f9fc0b7ef573b8fa9d4786) `git revert bf14f5172e25b0f3b1f9fc0b7ef573b8fa9d4786`

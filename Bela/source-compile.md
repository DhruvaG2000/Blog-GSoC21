---
sort: 3
---

# Source Compiling Bela

## On the BeagleBone Black:

Make sure that you are root user and then clone the Bela repo in ``/root/.``

1. **Install am335x PRU package:** Become super user by typing ``sudo -i`` and then ``git clone https://github.com/beagleboard/am335x_pru_package`` and then cd into the cloned directory and then <br>
run
```sh
make && make install
```

2. **Download and install seasocks libraries:** <br>
Also make sure that you have latest version of cmake installed on your BBB.
```sh
git clone https://github.com/mattgodbolt/seasocks
cd seasocks/
ls
mkdir build
cd build/
cmake .. -DDEFLATE_SUPPORT=OFF -DUNITTESTS=OFF
make
make install
```
3. **Install libne10**
```sh
sudo apt update
sudo apt install libne10-dev
```

4. **Install alsa and some libasound2:**
```sh
sudo apt-get install alsa-utils libasound2-dev
```

5. **While you're still su:**
```sh
dpkg -i /root/Bela/resources/stretch/deb/libpd-xenomai-3-dev_0.11.0-Bela-1_armhf.deb
```

6. Finally, go to the `Bela` directory and run
```sh
make lib
```
and that shall build your core Bela Code. Now to test if things went fine you will have to make a folder `projects` inside the `/root/Bela` inside which you can copy any example that you like and then run
```sh
sudo make PROJECT=sinetone run CL=-v
```
In this case I am building the sinetone example.
The ideal output(with the BELA Cape on the BBB) would be that you hear a shrill sine tone from the output speakers(which are externally connected to the BELA cape) and the following console output:
```sh
Failed to stop bela_startup.service: Unit bela_startup.service not loaded.
No process to kill
Running /root/Bela/projects/sample-streamer/sample-streamer -v
Xenomai not explicitly inited
Xenomai is going to be inited by us
Bela_initAudio()
Starting with period size 16 ;analog enabled
DAC level 0.000000 dB; ADC level 0.000000 dB; headphone level -6.000000 dB
Detected hardware: Bela
Hardware specified by user:
Hardware specified in belaconfig:
Hardware to be used: Bela
Bela_getHwConfigPrivate()
fifoFactor: 1
core audioFrames: 16
Project name: sample-streamer
PRU memory mapped to ARM:
digital: 0xb60ad000 0xb60ad400
audio: 0xb60ae000 0xb60ae040 0xb60ae080 0xb60ae0c0
analog: 0xb609e000 0xb609e080 0xb609e100 0xb609e180
analog offset: 0xffff2000 0xffff2080 0xffff2100 0xffff2180
Bela_startAudio
startAudioInilne
Using embedded PRU code
_________________Audio Thread!
```

## Contingencies
1. ERROR so and so
```sh
root@beaglebone:~/Bela# sudo make PROJECT=exampleTempProject run CL=-v
Failed to stop bela_startup.service: Unit bela_startup.service not loaded.
No process to kill
Running /root/Bela/projects/exampleTempProject/exampleTempProject -v
/root/Bela/projects/exampleTempProject/exampleTempProject: error while loading shared libraries: libcobalt.so.2: cannot open shared object file: No such file or directory
make: *** [Makefile:588: runonly] Error 127
```
Then run this
```sh
ldconfig /usr/xenomai/lib/
```

2. **Sinetone example runs but without audio output** <br>
Make sure that you disable/comment out all other overlays in the `/boot/uEnv.txt` file and only have this one under Additional custom capes enabled:
```
###Additional custom capes
uboot_overlay_addr4=/lib/firmware/BB-BELA-00A1.dtbo
```
3. If you get the following error:
```#!/bin/sh
root@beaglebone:~/Bela# sudo make PROJECT=exampleTempProject run CL=-v
Failed to stop bela_startup.service: Unit bela_startup.service not loaded.
No process to kill
Running /root/Bela/projects/exampleTempProject/exampleTempProject -v
Xenomai not explicitly inited
Xenomai is going to be inited by us
Bela_initAudio()
Starting with period size 16 ;analog enabled
DAC level 0.000000 dB; ADC level 0.000000 dB; headphone level -6.000000 dB
Detected hardware: Bela
Hardware specified by user:
Hardware specified in belaconfig:
Hardware to be used: Bela
Bela_getHwConfigPrivate()
fifoFactor: 1
core audioFrames: 16
Project name: exampleTempProject
PRU memory mapped to ARM:
digital: 0xb620f000 0xb620f400
audio: 0xb6210000 0xb6210040 0xb6210080 0xb62100c0
analog: 0xb6200000 0xb6200080 0xb6200100 0xb6200180
analog offset: 0xffff2000 0xffff2080 0xffff2100 0xffff2180
Bela_startAudio
startAudioInilne
Failed to open the kernel driver: (2) No such file or directory.
Maybe try
  modprobe rtdm_pruss_irq
?
Error: unable to start PRU from
Error: unable to start real-time audio
Stopping audio...
Failed to join audio thread: (3) No such process
Bela_cleanupAudio()
make: *** [Makefile:588: runonly] Error 1
Trying modprobe rtdm_pruss_irq returns
modprobe: FATAL: Module rtdm_pruss_irq not found in directory /lib/modules/4.14.108-ti-xenomai-r143
```
then build with `BELA_USE_DEFINE=BELA_USE_POLL` for now. This will remove the dependency on the rtdm_pruss_irq  driver

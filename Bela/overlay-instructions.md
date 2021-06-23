---
sort: 4
---

# The AUDIO Overlay

## Installing compatibility layer on your BBAI

Prior to this, if you want to install the CCL on a xenomai patched kernel, I suggest you follow [Installing Xenomai Kernel and Libraries](https://dhruvag2000.github.io/Blog-GSoC21/xenomai/install.html) (only the first step should suffice in most cases) ie. 
```sh
sudo /opt/scripts/tools/update_kernel.sh --ti-xenomai-channel --lts-4_19
```

* Create a backup of the original DTB.
```sh
sudo cp /boot/dtbs/4.19.94-ti-xenomai-r64/am5729-beagleboneai.dtb am5729-beagleboneai.dtb.backup
```

* Installing the compatibility layer
    1. Clone the repository ``git clone https://github.com/beagleboard/BeagleBoard-DeviceTrees.git``
    2. Change directory, ``cd BeagleBoard-DeviceTrees``
    3. Compile code, ``make``
    4. Install the dtb file on your board ``sudo cp src/arm/am5729-beagleboneai.dtb /boot/dtbs/4.19.94-ti-xenomai-r64/.``
    5. Reboot your board, ``sudo reboot``.

* Installing the DT overlay
    1. From the same base directory as above, Compile overlays using `make`.
    2. Install the  BBAI-AUDI-02 DT overlay, `sudo cp src/arm/BBAI-AUDI-02-00A0.dtbo /lib/firmware/.`

* Loading the overlay
To load the overlays during boot you have to edit ``/boot/uEnv.txt``. 

```
enable_uboot_overlays=1

uboot_overlay_addr4=/lib/firmware/BBAI-AUDI-02-00A0.dtbo
```

Now reboot after this and if everything goes right, then the commands below should give similar outputs:
```sh
debian@beaglebone:~$ aplay -l
**** List of PLAYBACK Hardware Devices ****
card 0: AudioCapeAI [AudioCapeAI], device 0: davinci-mcasp.0-tlv320aic3x-hifi tlv320aic3x-hifi-0 [davinci-mcasp.0-tlv320aic3x-hifi tlv320aic3x-hifi-0]
  Subdevices: 1/1
    Subdevice #0: subdevice #0
    card 1: H58040000encode [HDMI 58040000.encoder], device 0: HDMI 58040000.encoder snd-soc-dummy-dai-0 [HDMI 58040000.encoder snd-soc-dummy-dai-0]
      Subdevices: 1/1
        Subdevice #0: subdevice #0

```
and if you play some audio file you would be able to hear the output at `J4_output` pins of the BELA Cape.


---
sort: 1
---

# Installing Xenomai Kernel and Libraries

This is a step-by-step guide on how to install the latest working xenomai kernel on your BeagleBone device and after that, how to download and use the xenomai libraries for your project.

1. On any standard release of the IOT debian image for the BeagleBone, you should be able to locate Robert Nelson's Script `update_kernel.sh`. Run the following on your BeagleBone:
```sh
sudo /opt/scripts/tools/update_kernel.sh --ti-xenomai-channel --lts-4_19
```
After this, reboot, and then type in the command
```sh
uname -a
```
In my case, the output was
```sh
Linux beaglebone 4.19.94-ti-xenomai-r64
```
Now you only really need to note the _4.19.94-ti-xenomai-r64_ part of the output, this confirms that you are now running a Xenomai Patched Kernel on your device, and can move on to the proceeding steps.

2. Now in your terminal, paste ```dmesg | grep -i xenomai``` and observe the output. In my case, this was
```sh
[    0.000000] Linux version 4.19.94-ti-xenomai-r64 (voodoo@rpi4b4g-06) (gcc version 8.3.0 (Debian 8.3.0-6)) #1buster SMP PREEMPT Sat May 22 01:02:28 UTC 2021
[    1.218506] [Xenomai] scheduling class idle registered.
[    1.218522] [Xenomai] scheduling class rt registered.
[    1.218679] I-pipe: head domain Xenomai registered.
[    1.223587] [Xenomai] Cobalt v3.1
[    1.691998] usb usb1: Manufacturer: Linux 4.19.94-ti-xenomai-r64 musb-hcd
[   79.501460] CPU: 0 PID: 986 Comm: systemd-udevd Not tainted 4.19.94-ti-xenomai-r64 #1buster
```
Here, note the line `[    1.110019] [Xenomai] Cobalt v3.1`. This step is very important, as if there's any version mis-match then you will face issues later.

3. Now head over to [stable release tarballs](https://xenomai.org/downloads/xenomai/stable/) and download the version that matches the Cobalt version we saw above. [xenomai-3.1](https://xenomai.org/downloads/xenomai/stable/xenomai-3.1.tar.bz2) worked for me.
Extract the suitable version in your home and then you will have to make a fresh clean build directory. Your overall tree should look something like this:
```
├── build
│   └── xenomai
└── xenomai-3.1
    ├── aclocal.m4
    ├── config
    ├── configure
    ├── configure.ac
    ├── debian
    ├── demo
    ├── doc
    ├── include
    ├── kernel
    ├── lib
    ├── Makefile.am
    ├── Makefile.in
    ├── README
    ├── scripts
    ├── testsuite
    └── utils
```
`cd` into the build/xenomai directory and type in
```sh
../../xenomai-3.1/configure --enable-smp
```
`--enable-smp` Turns on SMP support for Xenomai libraries. SMP support must be enabled in Xenomai libraries when the
client applications are running over a SMP-capable kernel. After this is done, make sure no errors were encountered and then run 
```sh
make && sudo make install
```
It will take some time for it to compile everything and once it's done reboot your device.

4. Testing your installation: <br>
Run `sudo /usr/xenomai/bin/latency` and if you get an output similar to this:
```sh
== Sampling period: 1000 us
== Test mode: periodic user-mode task
== All results in microseconds
warming up...
RTT|  00:00:01  (periodic user-mode task, 1000 us period, priority 99)
RTH|----lat min|----lat avg|----lat max|-overrun|---msw|---lat best|--lat worst
RTD|      4.458|      7.504|     49.833|       0|     0|      4.458|     49.833
RTD|      4.416|      5.915|     33.958|       0|     0|      4.416|     49.833
RTD|      4.374|      5.142|     31.166|       0|     0|      4.374|     49.833
^C---|-----------|-----------|-----------|--------|------|-------------------------
RTS|      4.374|      6.187|     49.833|       0|     0|    00:00:04/00:00:04
```
then Congrats! You have successfully installed the Xenomai libraries and Kernel on your BeagleBone!

## References

1. [Xenomai Wiki](https://source.denx.de/Xenomai/xenomai/-/wikis/Installing_Xenomai_3#library-install)

## Contingencies

- It is possible that your BBAI may not boot after upgrading to xenomai kernel, try to access the boot logs via UART, and monitor them closely, also try to *RESET* and not `power off - power on` neither reboot the board.

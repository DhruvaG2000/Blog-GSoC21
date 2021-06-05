 ---
 sort: 2
 ---

# Installing Xenomai Kernel and Libraries

This is a step-by-step guide on how to install the latest working xenomai kernel on your BeagleBone device and after that, how to download and use the xenomai libraries for your project. 

1. On any standard release of the IOT debian image for the BeagleBone, you should be able to locate Robert Nelson's Script `update_kernel.sh`. Run the following on your BeagleBone:
```sh
sudo /opt/scripts/tools/update_kernel.sh --bone-xenomai-kernel --stable
```
After this, reboot, and then type in the command 
```sh
uname -a
```
In my case, the output was
```sh
Linux beaglebone 4.14.108-ti-xenomai-r143 #1buster SMP PREEMPT Thu May 27 21:23:48 UTC 2021 armv7l GNU/Linux
```
Now you only really need to note the _4.14.108-ti-xenomai-r143_ part of the output, this confirms that you are now running a Xenomai Patched Kernel on your device, and can move on to the proceeding steps. 

2. Now in your terminal, paste ```dmesg | grep -i xenomai``` and observe the output. In my case, this was
```sh
[    0.000000] Linux version 4.14.108-ti-xenomai-r143 (voodoo@rpi4b4g-02) (gcc version 8.3.0 (Debian 8.3.0-6)) #1buster SMP PREEMPT Thu May 27 21:23:48 UTC 2021
[    1.104848] [Xenomai] scheduling class idle registered.
[    1.104863] [Xenomai] scheduling class rt registered.
[    1.105047] I-pipe: head domain Xenomai registered.
[    1.110019] [Xenomai] Cobalt v3.0.11
[    1.158174] CPU: 0 PID: 1 Comm: swapper/0 Not tainted 4.14.108-ti-xenomai-r143 #1buster
[    1.509155] usb usb1: Manufacturer: Linux 4.14.108-ti-xenomai-r143 musb-hcd
```


## References 
1. [Xenomai Wiki](https://source.denx.de/Xenomai/xenomai/-/wikis/Installing_Xenomai_3#library-install)

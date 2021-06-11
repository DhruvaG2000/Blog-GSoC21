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
cmake ..
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

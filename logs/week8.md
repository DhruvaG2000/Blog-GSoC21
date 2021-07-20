---
sort: 9
---

# Week8

## Logs from July 14 to July 21

- Passed the GSoC first evaluations.
- Add BBAI support to the `jump` instruction [version of prudebug](https://github.com/giuliomoro/prudebug/tree/master)
- Started working on debugging errors while running BELA examples on the BBAI.
Currently stuck with trying to recognize BELA Cape via `i2cdetect -y -r 4`. Tried changing the clock freq in `&bone_i2c_2` part of new overlay from `400000` to `100000`, also added _4.7Kohm_ pull up resistors on `P9_19` which is _SCLK_ and `P9_20` which is _SDA_ .
- Had a short meet with mentor where we clarified a few of the doubts I had in the comments of the PR review. Will meet again tomorrow ie. Tuesday for a full out debuggin session to fix the I2C issue that we are unable to detect the BELA cape. I attached a screenshot from LA where the `aplay` sends out some i2c data initially [here](https://beagleboard.slack.com/archives/C0SLDS49M/p1626717962393900?thread_ts=1621443657.059500&cid=C0SLDS49M).
	- Mentor also helped me understand that the `--prufile` in Makefile is the option where we can give the name of our own custom pru firmware file.
	- Also, discussed a few things about McASP, and I got to know that McASP basically sends out digital data in the form of I2S.

- An extended meet with the purpose of debuggind the i2c issue was held on July 20 Tue. The MOM are:
	- The new workflow's Makefile inside the tempfolder was a bit wrong, I have forgotten to add the `dd` line to it. I will fix that.
	- Created a file : `/root/.bela/belaconfig` and put the line `CL=-G 0 -N 0 --stop-button-pin -1 --disable-led -v` in it. This will help us ignore the gpios and other not-so important stuff for now.
	- We went through the AM57x Manual once again to find out the clock register, and `CM_IPU_MCASP1_CLKCTRL` at pg 873 of SPRUHZ6L can be explored (mostly configured in mode `0x2`, verify the same using mmap.)
	- Learned a bit more about McASP: There are many clocks in the mcasp. We need to enable the internal mcasp clock using the `.p` file, to understand how, I may need to go through the kernel source code, or else check if I can get any hints from mmap-ing the earlier mentioned register.
	- A few more doubts in the PR comments were addressed, and also it wasdecided to use `#ifdefs` in `pru_rtaudio....p` to distinguish between AI and BBB and accordingly configure the registers. This can be done by passing a `-D...` in [L#467](https://github.com/giuliomoro/Bela-dhruva/blob/multi-codec/Makefile#L467) which is `pasm -V2 -L -c -b "$<" > /dev/null` 

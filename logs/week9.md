---
sort: 10
---

# Week9

## Logs from July 22 to July 29

- Started mmap-ing to look for value of the McASP clock register to help config it from the pru.p file
- Pasted the output of mmap [here](https://gist.github.com/DhruvaG2000/3b2f1bf43e67335bd1ab097325b17c94). The output can be explained as follows:
	- the *7* is `"Selects SYS_CLK2"`
	- the *3* when _stopped_ is **0x3**: Module is disabled and cannot be accessed . When _running_, it is **0x0**: Module is fully functional, including OCP
	- the *2* when _running_ is  **0x2**: Module is explicitly enabled. Interface clock (if not used for functions) may be gated according to the clock domain state. Functional clocks are guaranteed to stay present. As long as in this configuration, power domain sleep transition cannot happen.
	- When _stopped_ it is 0 : **0x0:** Module is disabled by SW. Any OCP access to module results in an error, except if resulting from a module wakeup (asynchronous wakeup).
- Mentor also suggested to lookup `devmem2` in `resources/bin`  that I can use to quickly mmap and read or write specific addresses.
- New LA104 arrived today on 23 Jul 2021. I measured the `McASP AHCLKX` freq and found it to be 20MHz. This confirms what freq we should expect when we are finally testing the Bela examples.
- Tried using `devmem2` binary as was suggested, and was able to write word to the address `0x4a005550`.
- Went through the PR comments, and made the following changes:
	- Pass firmware from Makefile and then build the string programatically for the BBAI.
	- `start()` was previously using `char* path` as argument which has now been updated to use `std::string` as suggested by mentor.

- We may be close to a breakthrough in the project as we are now able to see an _increased intensity signal_ when I run the sinetone example and touch my fingers on the input pins. This means that the codec is generating that data. The only thing (MAJOR thing) that remains now is to debug why there isn't Audio output.
- The debug procedure I am following is:
	- Load BBAI-AUDI.. overlay, then
	- Play some audio file
	- > use resources/tools/mcasp-dump-tool (after correcting for AI the McASP address it contains and adding McASP register names to the printout) while that audio file is playing in the other terminal

	Observe the output of the above.

	- Compare that with audio allegedly running on BBAI-BELA. (ie. while running the sinetone example without the errors)
	- compare that also with when you have this
	```
+#define MCASP_SRCTL_X  MCASP_SRCTL11   // Ser. 11 is transmitter
+#define MCASP_SRCTL_R  MCASP_SRCTL10   // Ser. 10 is receiver
	```

- **BREAKTHROUGH ACHIEVED:** The issue was solved without needing to do the above procedure. I have updated the `git diff`'s and a brief procedure [here](https://gist.github.com/DhruvaG2000/094dd06a010c0aa890a01e636af4ba3c).
	- Tested `sinetone`, working OK.
	- Tested `passthrough`, working OK.
	- **IMPORTANT NOTE** Do a `sudo ./devmem2 0x4A005550 w 0x7000002` before trying anything (as of Jul 28 2021).

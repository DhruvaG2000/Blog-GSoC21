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

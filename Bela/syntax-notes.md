---
sort: 2
---

# The Bela Code
## Makefile
* [here line #L282-L288](https://github.com/giuliomoro/Bela-private-dhruva/blob/multi-codec/Makefile#L282-L288): ``BELA_USE_DEFINE`` is used as a argument to the CPP Code [here](https://github.com/giuliomoro/Bela-private-dhruva/blob/multi-codec/Makefile#L290) for ``DEFAULT_COMMON_FLAGS``.
My idea: We can pass the BBAI flag by `BELA_USE_DEFINE += BBAIFLAG` in the argument. So accordingly whenever it compiles any codes it will automatically pass on the bbai flag to detect the board. Also once the board arrives only will I be able to test if the BBAI overlay export stuff works or not. Depending on that only I will add that instructions to the makefile.
One more thing: I will need the McASP code to work for BBAI and backwards as well. This is where the board detection will be really useful.
So for now let's add the lines to the makefile that just detect the bbai and keep it's flag ready. 

* [line #L451-L459](https://github.com/giuliomoro/Bela-private-dhruva/blob/bbai-makefile/Makefile#L451-L459): **Rule for Bela core ASM files** 
* [line #L461-L476](https://github.com/giuliomoro/Bela-private-dhruva/blob/bbai-makefile/Makefile#L461-L476): **PRU asm part** ``pasm -V2 -L -c -b "$<"``. 

As discussed, I have to make the following changes here: 
Try with gcc, or else use the _clpru toolchain_.  

Also, add the disasm prudis to makefile as follows: ``prudis file.bin | sed 's/^\(.*\)$/" \1\\n"/' > included_assembly.h``

## Asm files

**pru_rtaudio.p** 
- If I replace the older addresses with the one’s for BBAi, will that not break BBB compatibility? How can we tackle this issue? <br>
_soln:_ you can use #ifdef to make them conditional at compile time. The Makefile could detect whether we are running on an AM335x or an AM572x and define a flag accordingly. This same flag can be used for conditional compilation of the libprussdrv vs rproc stuff in core/PRU.cpp. This could be the initial approach because it’s faster to get it done. Later in the project, we could move to a runtime flag if appropriate by passing a flag to the PRU at runtime for whether we are on am335x or am527x
and allow it to select the relevant addresses at runtime. [source](https://forum.beagleboard.org/t/bela-support-for-bbai-later-ti-chips/29257/6)

- We are using only MCASP1 on the BBAI, so you don’t really need MCASP2. Also, the define for MCASP1 on the AM335x is not needed, because we never use that. <br>
The MCSPI and GPIO addresses will also need to change between the two boards. 
The following Table compares the Hex addresses of these pins. 

| Pin name/ <br>Definition 	| BBB<br>Addr 	| BBAI<br>Addr 	| Comments/notes                                                                                              	|   	|
|--------------------------	|-------------	|--------------	|-------------------------------------------------------------------------------------------------------------	|---	|
| McASP0 CFG               	| 0x4803_C000 	| 0x4846_4000  	| most of following BBB offsets are same, so mostly changing the base address only should suffice.            	|   	|
| McSPI                    	|             	|              	| Didn't find where McSPI are used in the asm files, so didn't look it up for now                             	|   	|
| GPIO0                    	| 0x44E07000  	|              	| see [#L43-L49](https://github.com/giuliomoro/Bela-private-dhruva/blob/bbai-mcasp/pru/pru_rtaudio.p#L43-L49) 	|   	|
| GPIO1                    	| 0x4804C000  	|              	|                                                                                                             	|   	|



## CPP Files

**core/PRU.cpp** uses the following libprussdrv functions currently: 
1. ``prussdrv_map_prumem()     // Line 101``
2. ``prussdrv_init()           // Line 443``
3. ``prussdrv_open()          // Line 444``
4. ``prussdrv_exec_code()     // Line 864``
5. ``prussdrv_exec_program()  // Line 874``
6. ``prussdrv_pru_disable()   // Line 1686``
7. ``prussdrv_exit()          // Line 1694 ``


### RPROC
Before we start discussing the cpp files, let's have a brief overview of the User API of rproc, and we will mainly go through the functions specific to our application.

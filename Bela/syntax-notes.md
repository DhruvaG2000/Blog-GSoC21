# Self NOTES while studying the Bela Code

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

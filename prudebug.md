# PRU DEBUGGER for BBAI

To view the entire ascii recording, visit the link here: [![asciicast](https://asciinema.org/a/iWYYdN1lhp1fB27fv6ze2DMix.svg)](https://asciinema.org/a/iWYYdN1lhp1fB27fv6ze2DMix)

## Blink LED code

The code below is written in assembly.

```asm
.origin 0
.entrypoint START
START:
HALT
// set all PRU GPIOs channels to HIGH
MOV R30, 0xffffffff
// wait several cycles
MOV R1, 3
LOOP1:
SUB R1, R1, 1
QBNE LOOP1, R1, 0
// set all PRU GPIOs channels to LOW
MOV R30, 0
// wait several cycles
MOV R1, 3
LOOP2:
SUB R1, R1, 1
QBNE LOOP2, R1, 0
// go back from the beginning
QBA START
```

## Prudebug

1. First, load the above assembly code, (to build it you can refer [build_pru.sh](https://gist.github.com/DhruvaG2000/eccbb9ee60c014dafc366555230f326d)

2. To run the prudebugger, execute the command `sudo ./prudebug -m`

3. After this, you will enter the following shell-looking interface. <br>
Now type in 

`PRU 1`
This select _PRU 1 core 1_ on the BBAI.


4. Now, keep on running `ss` which means it will single step through each instruction in the asm code on the PRU and you should see your LED blink as you do.

## References:

* [PRU Cookbook](https://markayoder.github.io/PRUCookbook/04debug/debug.html#debug_prudebug)

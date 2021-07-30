# PRU-ICSS integrated Interrupt Controller

# Table of Contents
1. [Overview](#overview)
2. [Functional Description]()
3. [Events Flow]()
4. [interrupt controller registers]()
5. [Common Terms used](#comterms)


## PRU-ICSS Interrupt Controller Overview <a name="overview"></a>
The PRU-ICSS interrupt controller (`PRUSS_INTC`) maps interrupts coming from different parts of the device (mapped to PRU-ICSS1/PRU-ICSS2 via the device `IRQ_CROSSBAR`) to a reduced set of PRU-ICSS interrupt channels.
The `PRUSS_INTC` has the following features:
- Capturing up to 64 System Events (inputs).
- Supports up to 10 output interrupt channels.
- Generation of 10 Host Interrupts.
- 2 Host Interrupts for the PRUs
- 8 Host Interrupts exported from the PRU-ICSS for signaling the ARMSS interrupt controllers.

## Common Terms used <a name="comterms"></a>
- *PRU-ICSS:* Programmable Real-Time Unit Subsystem and Industrial Communication Subsystem.
- *Arm interrupts:* [Refer this tutorial](https://www.electronicshub.org/arm-interrupt-tutorial/)

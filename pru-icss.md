# PRU-ICSS integrated Interrupt Controller

# Table of Contents
1. [Overview](#overview)
2. [Functional Description]()
3. [Events Flow]()
4. [interrupt controller registers]()
5. [Common Terms used](#comterms)


## PRU-ICSS Interrupt Controller Overview <a name="overview"></a>
![int-overview](photos/int-overview.png)
The PRU-ICSS interrupt controller (`PRUSS_INTC`) maps interrupts coming from different parts of the device (mapped to PRU-ICSS1/PRU-ICSS2 via the device `IRQ_CROSSBAR`) to a reduced set of PRU-ICSS interrupt channels.
The `PRUSS_INTC` has the following features:
- Capturing up to 64 System Events (inputs).
- Supports up to 10 output interrupt channels.
- Generation of 10 Host Interrupts.
- 2 Host Interrupts for the PRUs
- 8 Host Interrupts exported from the PRU-ICSS for signaling the ARMSS interrupt controllers.

## Functional description
**30.1.6.2 PRU-ICSS Interrupt Controller Functional Description**
The PRU-ICSS incorporates an interrupt controller - `PRUSS_INTC` that supports up to _64_ system interrupts from different peripherals (including 32 interrupts from PRU-ICSS located interrupt sources). The `PRUSS_INTC` maps these system events to _10 channels inside_ the `PRUSS_INTC` (see Figure). <br>
Interrupts from these 10 channels are further mapped to 10 Host Interrupts.
• Any of the 64 system interrupts can be mapped to any of the 10 channels.
• Multiple interrupts can be mapped to a single channel.
• An interrupt should not be mapped to more than one channel.
• Any of the 10 channels can be mapped to any of the 10 host interrupts. It is recommended to map
channel “x” to host interrupt “x”, where x is from 0 to 9
• A channel should not be mapped to more than one host interrupt
• For channels mapping to the same host interrupt, lower number channels have higher priority.
• For interrupts on same channel, priority is determined by the hardware interrupt number. The lower the
interrupt number, the higher the priority.
• Host Interrupt 0 is connected to bit 30 in register 31 (R31) of PRU0 and PRU1.
• Host Interrupt 1 is connected to bit 31 in register 31 (R31) for PRU0 and PRU1.
• Host Interrupts 2 through 9 exported from PRU-ICSS and mapped to interrupt controllers in the device.

## Routing McASP0 interrupts to PRU INTC


## Common Terms used <a name="comterms"></a>
- *PRU-ICSS:* Programmable Real-Time Unit Subsystem and Industrial Communication Subsystem.
- *Arm interrupts:* [Refer this tutorial](https://www.electronicshub.org/arm-interrupt-tutorial/)

## References
1. [TI Forum: am3359-routing-mcasp0-interrupts-to-pru-intc](https://e2e.ti.com/support/processors-group/processors/f/processors-forum/598002/am3359-routing-mcasp0-interrupts-to-pru-intc)

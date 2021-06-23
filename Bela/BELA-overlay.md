---
sort: 5
---

# The BELA Cape overlay

The original dts can be found [here](https://github.com/BelaPlatform/bb.org-overlays/blob/master/src/arm/BB-BELA-00A1.dts). this file is also [locally](../src/bela-overlay/BB-BELA-00A1.dts) available in this repo.

The explanation of the existing overlay: (thanks to my mentor @giuliomoro who helped me understand all fragments as given below)

1. [fragment@0](https://github.com/BelaPlatform/bb.org-overlays/blob/master/src/arm/BB-BELA-00A1.dts#L19) is a way to disable any pins that are critical to Bela and may be owned by some sort of "universal" cape.

2. fragment@1 disables the HDMI controller that would be on i2c0 on BBB.

3. fragment@2 does most of the pinmuxing: for mcasp, mcspi, i2c1, i2c2, and some PRU GPIO pins. It also defines pinmuxing for the bela Digital I/O, all of which are set to GPIO, INPUT ENABLED, PULLDOWN. For PocketBeagle (where the base device tree contains a universal cape) these are  `Px_yz_bela  pins`, which is later on assigned as the default value to ``Px_yz_pinmux``.  For Bela (given how BBB/BBG don't normally have a cape universal enabled) these are in ``pinmux_bb_digitals``. The pin groups defined here are later on assigned to individual drivers.

4. fragment@3 sets the clock speed for _i2c1_. This is not strictly needed because _i2c1_ is not used by the Bela or BelaMini capes.

5. fragment@4 configures the McASP. This should be a subset of the BB-BONE-AUDI overlay. I believe this is actually largely ignored, because some of this initialisation is performed in the Bela PRU code. However, what's crucial here are the pinctrl  pins. WIth hack, we use this to also set the ``bela_pru_pins`` group (even though they have nothing to do with mcasp).

6. fragment@5 is the one enabling PRU with the ``uio_pruss driver`` (ti,pruss-v2). This should be a subset of some PRU overlay. I see ``bela_pru_pins`` are set here as well, which makes the hack in the previous fragment probably unnecessary.

7. fragment@6 disables uart2 which is enabled by default on BBG and would conflict with some i2c1 pins.

8. fragment@7 enables the SPI driver and associated pins

9. fragment@8 sets the pinmuxing for Bela digital I/O on PocketBeagle. I think the expectation is that this fragment fails to load on BBB.

10. fragment@9 sets the pinmuxing for Bela digital I/O on non-PocketBeagle. I think the expectation is that his fragment fails to load on PocketBeagle. Given how only one of 8 or 9 will succeed on any board, we make sure we have our pins set on any board with the same exact image.

11. fragment@10  enables i2c2, sets it clock frequency and pins

## BELA overlay using the CCL:

Under fragment2:
```
/* Pinmux for McASP0 (audio i/o) (BBB) */
mcasp0_ahclkx, 		P9_25 | MODE0 | OUTPUT_PULLDOWN
mcasp0_axr2, 			P9_28 | MODE2 | INPUT_PULLDOWN
mcasp0_fsx, 			P9_29 | MODE0 | INPUT_PULLDOWN
mcasp0_aclkx, 		P9_31 | MODE0 | INPUT_PULLDOWN
mcasp0_axr0, 			P9_30 | MODE0 | INPUT_PULLDOWN
(in BBAI: (similar to Audi overlay))
    P9_25_pinmux { pinctrl-0 = <&P9_25_mcasp_pin>; };  /* xref_clk0.mcasp1_ahclkx */
    P9_28_pinmux { pinctrl-0 = <&P9_28_mcasp_pin>; };  /* mcasp1_axr11.mcasp1_axr11 */
    P9_29_pinmux { pinctrl-0 = <&P9_29_mcasp_pin>; };  /* mcasp1_fsx.mcasp1_fsx, mcasp1_axr9.off */
    P9_30_pinmux { pinctrl-0 = <&P9_30_mcasp_pin>; };  /* mcasp1_axr10.mcasp1_axr10 */
    P9_31_pinmux { pinctrl-0 = <&P9_31_mcasp_pin>; };  /* mcasp1_aclkx.mcasp1_aclkx, mcasp1_axr8.off */

/* Pinmux for McSPI0 (analog i/o) */
spi0_sclk, 			P9_22 | MODE0 | INPUT_PULLUP
spi0_d0, 				P9_21 | MODE0 | INPUT_PULLUP
spi0_d1, 				P9_18 | MODE0 | OUTPUT_PULLUP
spi0_cs0, 			P9_17 | MODE0 | OUTPUT_PULLUP
```

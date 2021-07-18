---
sort: 9
---

# Week8

## Logs from July 14 to July 21

- Passed the GSoC first evaluations.
- Add BBAI support to the `jump` instruction [version of prudebug](https://github.com/giuliomoro/prudebug/tree/master)
- Started working on debugging errors while running BELA examples on the BBAI.
Currently stuck with trying to recognize BELA Cape via `i2cdetect -y -r 4`. Tried changing the clock freq in `&bone_i2c_2` part of new overlay from `400000` to `100000`, also added _4.7Kohm_ pull up resistors on `P9_19` which is _SCLK_ and `P9_20` which is _SDA_ .

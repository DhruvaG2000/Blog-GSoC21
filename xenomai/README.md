---
sort: 1
---

# The Xenomai Kernal

## What is Xenomai?

[Xenomai](https://source.denx.de/Xenomai/xenomai/-/wikis/home) is a Free Software project in which engineers from a wide
background collaborate to build a robust and resource-efficient
real-time core for Linux© following the dual kernel approach, for
applications with stringent latency requirements.

## What's Interrupt pipeline (I-pipe)?
The Cobalt real-time core depends on a patch to the mainline Linux
kernel, which introduces a separate, high-priority execution stage for
running out-of-band interrupt handlers immediately upon IRQ receipt,
which cannot be delayed by the regular kernel work.

{% include list.liquid all=true %}

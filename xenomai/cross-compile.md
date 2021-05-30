---
sort: 1
---

source: [here](https://source.denx.de/Xenomai/xenomai/-/wikis/Installing_Xenomai_3#user-content-cross-compilation)

**NOTE:** As of today, the Mercury core
needs no Xenomai-specific code in kernel space.

## Installing the Mercury core
For Mercury, you need no Xenomai-specific kernel support so far,
beyond what your host Linux kernel already provides. Your kernel
should at least provide high resolution timer support
(CONFIG_HIGH_RES_TIMERS), and likely complete preemption
(PREEMPT_RT) if your application requires short and bounded
latencies.


Kernels with __no real-time support__ can be used too, likely for _basic debugging tasks_, and/or running applications which do not have strict response time requirements.

Therefore, unlike with Cobalt, there is no additional steps for
preparing and/or configuring the kernel for Mercury.

### Configuring

If building the source obtained from the Xenomai GIT tree
(git.xenomai.org), the configure script and Makefiles must be
generated in the Xenomai source tree. The recommended way is to run
the automatic reconfiguration script shipped, from the top of the
source tree:
```sh
$ ./scripts/bootstrap
```
for futher detailed instructions [go here](https://source.denx.de/Xenomai/xenomai/-/wikis/Installing_Xenomai_3#user-content-configuring).

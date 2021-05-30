## Trying to compile xenomai.
following [this](https://source.denx.de/Xenomai/xenomai/-/wikis/Installing_Xenomai_3#user-content-cross-compilation)
```sh
dhruva@FX504GD ~/gsoc21/bela/xenoBuild                       [17:02:13]
> $ ../xenomai_dwld/xenomai-3.1/configure --with-core=cobalt --enable-smp --enable-pshared \
  --host=i686-linux CFLAGS="-m32 -O2" LDFLAGS="-m32"
checking whether we build for Cobalt or Mercury core... cobalt
checking build system type... x86_64-pc-linux-gnu
checking host system type... i686-pc-linux-gnu
checking for a BSD-compatible install... /usr/bin/install -c
checking for i686-linux-gcc... no
checking for gcc... gcc
checking whether the C compiler works... no
configure: error: in `/home/dhruva/gsoc21/bela/xenoBuild':
configure: error: C compiler cannot create executables
See `config.log' for more details
```

This is when I first did
```sh
> $ ./scripts/bootstrap --with=core=mercury --prefix=/home/dhruva/gsoc21/bela/xenomai_dwld/xenolibs 
```
```sh
dhruva@FX504GD ~/gsoc21/bela/xenoBuild                       [18:17:01]
> $ ../xenomai_dwld/xenomai-3.1/configure --with-core=mercury --enable-smp --enable-pshared
checking whether we build for Cobalt or Mercury core... mercury
checking build system type... x86_64-pc-linux-gnu
checking host system type... x86_64-pc-linux-gnu
checking for a BSD-compatible install... /usr/bin/install -c
checking for gcc... gcc
checking whether the C compiler works... yes
checking for C compiler default output file name... a.out
checking for suffix of executables...
checking whether we are cross compiling... no
checking for suffix of object files... o
checking whether we are using the GNU C compiler... yes
checking whether gcc accepts -g... yes
checking for gcc option to accept ISO C89... none needed
checking whether gcc understands -c and -o together... yes
checking how to run the C preprocessor... gcc -E
checking target system type... x86_64-pc-linux-gnu
checking for gcc... gcc
checking whether we are using the GNU C compiler... (cached) yes
checking whether gcc accepts -g... yes
checking for gcc option to accept ISO C89... (cached) none needed
checking whether gcc understands -c and -o together... (cached) yes
checking how to run the C preprocessor... gcc -E
checking for grep that handles long lines and -e... /usr/bin/grep
checking for BSD- or MS-compatible name lister (nm)... /usr/bin/nm -B
checking the name lister (/usr/bin/nm -B) interface... BSD nm
checking for gawk... no
checking for mawk... mawk
checking for a sed that does not truncate output... /usr/bin/sed
checking for egrep... /usr/bin/grep -E
checking for fgrep... /usr/bin/grep -F
checking how to print strings... printf
checking for ld used by gcc... /usr/bin/ld
checking if the linker (/usr/bin/ld) is GNU ld... yes
checking command to parse /usr/bin/nm -B output from gcc object... ok
checking for _ prefix in compiled symbols... no
checking whether build environment is sane... yes
checking for a thread-safe mkdir -p... /usr/bin/mkdir -p
checking whether make sets $(MAKE)... yes
checking whether make supports the include directive... yes (GNU style)
checking whether make supports nested variables... yes
checking whether UID '1000' is supported by ustar format... yes
checking whether GID '1000' is supported by ustar format... yes
checking how to create a ustar tar archive... gnutar
checking dependency style of gcc... gcc3
checking whether make supports nested variables... (cached) yes
checking whether to enable maintainer-specific portions of Makefiles... no
checking dependency style of gcc... gcc3
checking for flex... flex
checking lex output file root... lex.yy
checking lex library... none needed
checking whether yytext is a pointer... no
checking for target architecture... x86
checking whether ln -s works... yes
checking the maximum length of command line arguments... 1572864
checking how to convert x86_64-pc-linux-gnu file names to x86_64-pc-linux-gnu format... func_convert_file_noop
checking how to convert x86_64-pc-linux-gnu file names to toolchain format... func_convert_file_noop
checking for /usr/bin/ld option to reload object files... -r
checking for objdump... objdump
checking how to recognize dependent libraries... pass_all
checking for dlltool... no
checking how to associate runtime and link libraries... printf %s\n
checking for ar... ar
checking for archiver @FILE support... @
checking for strip... strip
checking for ranlib... ranlib
checking for sysroot... no
checking for a working dd... /usr/bin/dd
checking how to truncate binary pipes... /usr/bin/dd bs=4096 count=1
checking for mt... mt
checking if mt is a manifest tool... no
checking for ANSI C header files... yes
checking for sys/types.h... yes
checking for sys/stat.h... yes
checking for stdlib.h... yes
checking for string.h... yes
checking for memory.h... yes
checking for strings.h... yes
checking for inttypes.h... yes
checking for stdint.h... yes
checking for unistd.h... yes
checking for dlfcn.h... yes
checking for objdir... .libs
checking if gcc supports -fno-rtti -fno-exceptions... no
checking for gcc option to produce PIC... -fPIC -DPIC
checking if gcc PIC flag -fPIC -DPIC works... yes
checking if gcc static flag -static works... yes
checking if gcc supports -c -o file.o... yes
checking if gcc supports -c -o file.o... (cached) yes
checking whether the gcc linker (/usr/bin/ld -m elf_x86_64) supports shared libraries... yes
checking whether -lc should be explicitly linked in... no
checking dynamic linker characteristics... GNU/Linux ld.so
checking how to hardcode library paths into programs... immediate
checking whether stripping libraries is possible... yes
checking if libtool supports shared libraries... yes
checking whether to build shared libraries... yes
checking whether to build static libraries... yes
checking whether to enable debug mode... no
checking whether to enable the low resolution clock... no
checking whether we may use CLOCK_MONOTONIC_RAW... no
checking whether assertions should be enabled... no
checking whether asynchronous cancellation of threads is enabled... no
checking whether to enable the workaround for broken PI with condvars... no
checking whether to enable lazy scheduling parameter update... no
checking whether shared multi-processing should be supported... y
checking for process-local memory allocator... heapmem
checking whether the registry should be enabled... no
checking for SMP support... y
checking whether to enable sanity checks... y
checking whether to build documentation... checking for doxygen... no
checking for dot... NO
checking for LaTeX mode... batch
checking for asciidoc... no
checking for a2x... no
checking for w3m... no
checking valgrind/valgrind.h usability... no
checking valgrind/valgrind.h presence... no
checking for valgrind/valgrind.h... no
checking for Valgrind client API... no
checking obstack.h usability... yes
checking obstack.h presence... yes
checking for obstack.h... yes
checking mqueue.h usability... yes
checking mqueue.h presence... yes
checking for mqueue.h... yes
checking for pthread_mutexattr_setprotocol... yes
checking for pthread_mutexattr_getprotocol... yes
checking for pthread_mutexattr_getprioceiling... yes
checking for pthread_mutexattr_setprioceiling... yes
checking for pthread_mutexattr_setrobust_np... yes
checking for pthread_mutex_getprioceiling... yes
checking for pthread_mutex_setprioceiling... yes
checking for pthread_condattr_getclock... yes
checking for pthread_condattr_setclock... yes
checking for pthread_spin_lock... yes
checking for fork... yes
checking for pthread_attr_setaffinity_np... yes
checking for pthread_setaffinity_np... yes
checking for pthread_getattr_np... yes
checking for pthread_atfork... yes
checking for pthread_setname_np... yes
checking for pthread_setschedprio... yes
checking for sched_getcpu... yes
checking for clock_nanosleep... yes
checking for shm_open... yes
checking for shm_unlink... yes
checking for backtrace... yes
checking whether PTHREAD_PRIO_NONE is declared... yes
checking whether PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP is declared... yes
checking whether PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP is declared... yes
checking for pthread_condattr_setclock... (cached) yes
checking for shm_open... (cached) yes
checking whether the compiler provides atomic builtins... yes
checking for fortify support... autodetect
checking for __vfprintf_chk... yes
checking whether ld supports @file... yes
checking whether to enable dlopening of Xenomai libraries... no
checking whether to enable TLS support... yes
checking for __thread keyword... yes
checking location for test executables... ${exec_prefix}/bin
checking location for demo programs... ${exec_prefix}/demo
checking for test source generation... ok
checking that generated files are newer than configure... done
configure: creating ./config.status
config.status: creating Makefile
config.status: creating config/Makefile
config.status: creating scripts/Makefile
config.status: creating scripts/xeno-config
config.status: creating scripts/xeno
config.status: creating lib/Makefile
config.status: creating lib/boilerplate/Makefile
config.status: creating lib/boilerplate/init/Makefile
config.status: creating lib/cobalt/Makefile
config.status: creating lib/cobalt/arch/Makefile
config.status: creating lib/cobalt/arch/arm/Makefile
config.status: creating lib/cobalt/arch/arm/include/Makefile
config.status: creating lib/cobalt/arch/arm/include/asm/Makefile
config.status: creating lib/cobalt/arch/arm/include/asm/xenomai/Makefile
config.status: creating lib/cobalt/arch/arm64/Makefile
config.status: creating lib/cobalt/arch/arm64/include/Makefile
config.status: creating lib/cobalt/arch/arm64/include/asm/Makefile
config.status: creating lib/cobalt/arch/arm64/include/asm/xenomai/Makefile
config.status: creating lib/cobalt/arch/powerpc/Makefile
config.status: creating lib/cobalt/arch/powerpc/include/Makefile
config.status: creating lib/cobalt/arch/powerpc/include/asm/Makefile
config.status: creating lib/cobalt/arch/powerpc/include/asm/xenomai/Makefile
config.status: creating lib/cobalt/arch/x86/Makefile
config.status: creating lib/cobalt/arch/x86/include/Makefile
config.status: creating lib/cobalt/arch/x86/include/asm/Makefile
config.status: creating lib/cobalt/arch/x86/include/asm/xenomai/Makefile
config.status: creating lib/mercury/Makefile
config.status: creating lib/copperplate/Makefile
config.status: creating lib/copperplate/regd/Makefile
config.status: creating lib/alchemy/Makefile
config.status: creating lib/vxworks/Makefile
config.status: creating lib/psos/Makefile
config.status: creating lib/analogy/Makefile
config.status: creating lib/smokey/Makefile
config.status: creating lib/trank/Makefile
config.status: creating testsuite/Makefile
config.status: creating testsuite/latency/Makefile
config.status: creating testsuite/switchtest/Makefile
config.status: creating testsuite/gpiotest/Makefile
config.status: creating testsuite/spitest/Makefile
config.status: creating testsuite/smokey/Makefile
config.status: creating testsuite/smokey/arith/Makefile
config.status: creating testsuite/smokey/dlopen/Makefile
config.status: creating testsuite/smokey/sched-quota/Makefile
config.status: creating testsuite/smokey/sched-tp/Makefile
config.status: creating testsuite/smokey/setsched/Makefile
config.status: creating testsuite/smokey/rtdm/Makefile
config.status: creating testsuite/smokey/vdso-access/Makefile
config.status: creating testsuite/smokey/posix-cond/Makefile
config.status: creating testsuite/smokey/posix-mutex/Makefile
config.status: creating testsuite/smokey/posix-clock/Makefile
config.status: creating testsuite/smokey/posix-fork/Makefile
config.status: creating testsuite/smokey/posix-select/Makefile
config.status: creating testsuite/smokey/xddp/Makefile
config.status: creating testsuite/smokey/iddp/Makefile
config.status: creating testsuite/smokey/bufp/Makefile
config.status: creating testsuite/smokey/sigdebug/Makefile
config.status: creating testsuite/smokey/timerfd/Makefile
config.status: creating testsuite/smokey/tsc/Makefile
config.status: creating testsuite/smokey/leaks/Makefile
config.status: creating testsuite/smokey/memcheck/Makefile
config.status: creating testsuite/smokey/memory-coreheap/Makefile
config.status: creating testsuite/smokey/memory-heapmem/Makefile
config.status: creating testsuite/smokey/memory-tlsf/Makefile
config.status: creating testsuite/smokey/memory-pshared/Makefile
config.status: creating testsuite/smokey/fpu-stress/Makefile
config.status: creating testsuite/smokey/net_udp/Makefile
config.status: creating testsuite/smokey/net_packet_dgram/Makefile
config.status: creating testsuite/smokey/net_packet_raw/Makefile
config.status: creating testsuite/smokey/net_common/Makefile
config.status: creating testsuite/smokey/cpu-affinity/Makefile
config.status: creating testsuite/smokey/gdb/Makefile
config.status: creating testsuite/clocktest/Makefile
config.status: creating testsuite/xeno-test/Makefile
config.status: creating utils/Makefile
config.status: creating utils/hdb/Makefile
config.status: creating utils/can/Makefile
config.status: creating utils/analogy/Makefile
config.status: creating utils/ps/Makefile
config.status: creating utils/slackspot/Makefile
config.status: creating utils/corectl/Makefile
config.status: creating utils/autotune/Makefile
config.status: creating utils/net/rtnet
config.status: creating utils/net/rtnet.conf
config.status: creating utils/net/Makefile
config.status: creating demo/Makefile
config.status: creating demo/posix/Makefile
config.status: creating demo/posix/cyclictest/Makefile
config.status: creating demo/posix/cobalt/Makefile
config.status: creating demo/alchemy/Makefile
config.status: creating demo/alchemy/cobalt/Makefile
config.status: creating include/Makefile
config.status: creating include/cobalt/uapi/Makefile
config.status: creating include/cobalt/uapi/asm-generic/Makefile
config.status: creating include/cobalt/uapi/kernel/Makefile
config.status: creating include/cobalt/Makefile
config.status: creating include/cobalt/sys/Makefile
config.status: creating include/cobalt/kernel/Makefile
config.status: creating include/cobalt/kernel/rtdm/Makefile
config.status: creating include/cobalt/kernel/rtdm/analogy/Makefile
config.status: creating include/cobalt/boilerplate/Makefile
config.status: creating include/rtdm/Makefile
config.status: creating include/rtdm/uapi/Makefile
config.status: creating include/mercury/Makefile
config.status: creating include/mercury/boilerplate/Makefile
config.status: creating include/boilerplate/Makefile
config.status: creating include/copperplate/Makefile
config.status: creating include/alchemy/Makefile
config.status: creating include/vxworks/Makefile
config.status: creating include/psos/Makefile
config.status: creating include/smokey/Makefile
config.status: creating include/trank/Makefile
config.status: creating include/trank/posix/Makefile
config.status: creating include/trank/native/Makefile
config.status: creating include/trank/rtdm/Makefile
config.status: creating include/xenomai/Makefile
config.status: creating doc/Makefile
config.status: creating doc/doxygen/Makefile
config.status: creating doc/doxygen/xeno3prm-common.conf
config.status: creating doc/doxygen/xeno3prm-html.conf
config.status: creating doc/doxygen/xeno3prm-latex.conf
config.status: creating doc/gitdoc/Makefile
config.status: creating doc/asciidoc/Makefile
config.status: creating include/xeno_config.h
config.status: executing depfiles commands
config.status: executing libtool commands

dhruva@FX504GD ~/gsoc21/bela/xenoBuild                       [18:18:04]
> $ make install                                                       
Making install in doc
make[1]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/doc'
Making install in gitdoc
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/gitdoc'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/gitdoc'
make[3]: Nothing to be done for 'install-exec-am'.
make[3]: Nothing to be done for 'install-data-am'.
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/gitdoc'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/gitdoc'
Making install in doxygen
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/doxygen'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/doxygen'
make[3]: Nothing to be done for 'install-exec-am'.
make[3]: Nothing to be done for 'install-data-am'.
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/doxygen'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/doxygen'
Making install in asciidoc
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/asciidoc'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/asciidoc'
make[3]: Nothing to be done for 'install-exec-am'.
make[3]: Nothing to be done for 'install-data-am'.
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/asciidoc'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/asciidoc'
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/doc'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/doc'
make[3]: Nothing to be done for 'install-exec-am'.
make[3]: Nothing to be done for 'install-data-am'.
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/doc'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/doc'
make[1]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/doc'
Making install in lib
make[1]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib'
Making install in boilerplate
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/boilerplate'
make  install-recursive
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/boilerplate'
Making install in init
make[4]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/boilerplate/init'
  CC       libbootstrap_a-bootstrap.o
  AR       libbootstrap.a
ar: `u' modifier ignored since `D' is the default (see `U')
  CC       libbootstrap_pic_la-bootstrap.lo
  CCLD     libbootstrap-pic.la
make[5]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/boilerplate/init'
make[5]: Nothing to be done for 'install-exec-am'.
mkdir: cannot create directory ‘/usr/xenomai’: Permission denied
mkdir: cannot create directory ‘/usr/xenomai’: Permission denied
make[5]: *** [Makefile:719: install-data-local] Error 1
make[5]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/boilerplate/init'
make[4]: *** [Makefile:598: install-am] Error 2
make[4]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/boilerplate/init'
make[3]: *** [Makefile:833: install-recursive] Error 1
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/boilerplate'
make[2]: *** [Makefile:993: install] Error 2
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/boilerplate'
make[1]: *** [Makefile:427: install-recursive] Error 1
make[1]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib'
make: *** [Makefile:460: install-recursive] Error 1

dhruva@FX504GD ~/gsoc21/bela/xenoBuild                       [18:18:16]
> $ sudo make install                                                  
[sudo] password for dhruva:     
Making install in doc
make[1]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/doc'
Making install in gitdoc
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/gitdoc'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/gitdoc'
make[3]: Nothing to be done for 'install-exec-am'.
make[3]: Nothing to be done for 'install-data-am'.
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/gitdoc'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/gitdoc'
Making install in doxygen
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/doxygen'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/doxygen'
make[3]: Nothing to be done for 'install-exec-am'.
make[3]: Nothing to be done for 'install-data-am'.
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/doxygen'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/doxygen'
Making install in asciidoc
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/asciidoc'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/asciidoc'
make[3]: Nothing to be done for 'install-exec-am'.
make[3]: Nothing to be done for 'install-data-am'.
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/asciidoc'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/doc/asciidoc'
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/doc'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/doc'
make[3]: Nothing to be done for 'install-exec-am'.
make[3]: Nothing to be done for 'install-data-am'.
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/doc'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/doc'
make[1]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/doc'
Making install in lib
make[1]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib'
Making install in boilerplate
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/boilerplate'
make  install-recursive
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/boilerplate'
Making install in init
make[4]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/boilerplate/init'
make[5]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/boilerplate/init'
make[5]: Nothing to be done for 'install-exec-am'.
make[5]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/boilerplate/init'
make[4]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/boilerplate/init'
make[4]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/boilerplate'
  CC       version-version.o
  CCLD     version
  CC       libavl_la-avl.lo
  CCLD     libavl.la
  CC       libversion_la-version.lo
  CCLD     libversion.la
  CC       iniparser/libiniparser_la-dictionary.lo
  CC       iniparser/libiniparser_la-iniparser.lo
  CCLD     libiniparser.la
  CC       libboilerplate_la-ancillaries.lo
  CC       libboilerplate_la-heapmem.lo
  CC       libboilerplate_la-hash.lo
  CC       libboilerplate_la-setup.lo
  CC       libboilerplate_la-time.lo
  CC       libshavl_la-avl.lo
  CCLD     libshavl.la
  CC       tlsf/libtlsf_la-tlsf.lo
  CCLD     libtlsf.la
  CCLD     libboilerplate.la
make[5]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/boilerplate'
 /usr/bin/mkdir -p '/usr/xenomai/sbin'
  /bin/bash ../../libtool   --mode=install /usr/bin/install -c version '/usr/xenomai/sbin'
libtool: install: /usr/bin/install -c version /usr/xenomai/sbin/version
make[5]: Nothing to be done for 'install-data-am'.
make[5]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/boilerplate'
make[4]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/boilerplate'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/boilerplate'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/boilerplate'
Making install in mercury
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/mercury'
  CCLD     libmercury.la
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/mercury'
 /usr/bin/mkdir -p '/usr/xenomai/lib'
 /bin/bash ../../libtool   --mode=install /usr/bin/install -c   libmercury.la '/usr/xenomai/lib'
libtool: install: /usr/bin/install -c .libs/libmercury.so.0.0.0 /usr/xenomai/lib/libmercury.so.0.0.0
libtool: install: (cd /usr/xenomai/lib && { ln -s -f libmercury.so.0.0.0 libmercury.so.0 || { rm -f libmercury.so.0 && ln -s libmercury.so.0.0.0 libmercury.so.0; }; })
libtool: install: (cd /usr/xenomai/lib && { ln -s -f libmercury.so.0.0.0 libmercury.so || { rm -f libmercury.so && ln -s libmercury.so.0.0.0 libmercury.so; }; })
libtool: install: /usr/bin/install -c .libs/libmercury.lai /usr/xenomai/lib/libmercury.la
libtool: install: /usr/bin/install -c .libs/libmercury.a /usr/xenomai/lib/libmercury.a
libtool: install: chmod 644 /usr/xenomai/lib/libmercury.a
libtool: install: ranlib /usr/xenomai/lib/libmercury.a
libtool: finish: PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin:/sbin" ldconfig -n /usr/xenomai/lib
----------------------------------------------------------------------
Libraries have been installed in:
   /usr/xenomai/lib

If you ever happen to want to link against installed libraries
in a given directory, LIBDIR, you must either use libtool, and
specify the full pathname of the library, or use the '-LLIBDIR'
flag during linking and do at least one of the following:
   - add LIBDIR to the 'LD_LIBRARY_PATH' environment variable
     during execution
   - add LIBDIR to the 'LD_RUN_PATH' environment variable
     during linking
   - use the '-Wl,-rpath -Wl,LIBDIR' linker flag
   - have your system administrator add LIBDIR to '/etc/ld.so.conf'

See any operating system documentation about shared libraries for
more information, such as the ld(1) and ld.so(8) manual pages.
----------------------------------------------------------------------
make[3]: Nothing to be done for 'install-data-am'.
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/mercury'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/mercury'
Making install in copperplate
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/copperplate'
Making install in .
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/copperplate'
  CC       libcopperplate_la-clockobj.lo
  CC       libcopperplate_la-cluster.lo
  CC       libcopperplate_la-eventobj.lo
  CC       libcopperplate_la-init.lo
  CC       libcopperplate_la-internal.lo
  CC       libcopperplate_la-syncobj.lo
  CC       libcopperplate_la-semobj.lo
  CC       libcopperplate_la-threadobj.lo
  CC       libcopperplate_la-timerobj.lo
  CC       libcopperplate_la-traceobj.lo
  CC       libcopperplate_la-heapobj-pshared.lo
  CC       libcopperplate_la-reference.lo
  CC       libcopperplate_la-heapobj-heapmem.lo
  CCLD     libcopperplate.la
make[4]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/copperplate'
 /usr/bin/mkdir -p '/usr/xenomai/lib'
 /bin/bash ../../libtool   --mode=install /usr/bin/install -c   libcopperplate.la '/usr/xenomai/lib'
libtool: install: /usr/bin/install -c .libs/libcopperplate.so.0.0.0 /usr/xenomai/lib/libcopperplate.so.0.0.0
libtool: install: (cd /usr/xenomai/lib && { ln -s -f libcopperplate.so.0.0.0 libcopperplate.so.0 || { rm -f libcopperplate.so.0 && ln -s libcopperplate.so.0.0.0 libcopperplate.so.0; }; })
libtool: install: (cd /usr/xenomai/lib && { ln -s -f libcopperplate.so.0.0.0 libcopperplate.so || { rm -f libcopperplate.so && ln -s libcopperplate.so.0.0.0 libcopperplate.so; }; })
libtool: install: /usr/bin/install -c .libs/libcopperplate.lai /usr/xenomai/lib/libcopperplate.la
libtool: install: /usr/bin/install -c .libs/libcopperplate.a /usr/xenomai/lib/libcopperplate.a
libtool: install: chmod 644 /usr/xenomai/lib/libcopperplate.a
libtool: install: ranlib /usr/xenomai/lib/libcopperplate.a
libtool: finish: PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin:/sbin" ldconfig -n /usr/xenomai/lib
----------------------------------------------------------------------
Libraries have been installed in:
   /usr/xenomai/lib

If you ever happen to want to link against installed libraries
in a given directory, LIBDIR, you must either use libtool, and
specify the full pathname of the library, or use the '-LLIBDIR'
flag during linking and do at least one of the following:
   - add LIBDIR to the 'LD_LIBRARY_PATH' environment variable
     during execution
   - add LIBDIR to the 'LD_RUN_PATH' environment variable
     during linking
   - use the '-Wl,-rpath -Wl,LIBDIR' linker flag
   - have your system administrator add LIBDIR to '/etc/ld.so.conf'

See any operating system documentation about shared libraries for
more information, such as the ld(1) and ld.so(8) manual pages.
----------------------------------------------------------------------
make[4]: Nothing to be done for 'install-data-am'.
make[4]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/copperplate'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/copperplate'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/copperplate'
Making install in smokey
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/smokey'
  CC       libsmokey_la-helpers.lo
  CC       libsmokey_la-init.lo
  CCLD     libsmokey.la
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/smokey'
 /usr/bin/mkdir -p '/usr/xenomai/lib'
 /bin/bash ../../libtool   --mode=install /usr/bin/install -c   libsmokey.la '/usr/xenomai/lib'
libtool: install: /usr/bin/install -c .libs/libsmokey.so.0.0.0 /usr/xenomai/lib/libsmokey.so.0.0.0
libtool: install: (cd /usr/xenomai/lib && { ln -s -f libsmokey.so.0.0.0 libsmokey.so.0 || { rm -f libsmokey.so.0 && ln -s libsmokey.so.0.0.0 libsmokey.so.0; }; })
libtool: install: (cd /usr/xenomai/lib && { ln -s -f libsmokey.so.0.0.0 libsmokey.so || { rm -f libsmokey.so && ln -s libsmokey.so.0.0.0 libsmokey.so; }; })
libtool: install: /usr/bin/install -c .libs/libsmokey.lai /usr/xenomai/lib/libsmokey.la
libtool: install: /usr/bin/install -c .libs/libsmokey.a /usr/xenomai/lib/libsmokey.a
libtool: install: chmod 644 /usr/xenomai/lib/libsmokey.a
libtool: install: ranlib /usr/xenomai/lib/libsmokey.a
libtool: finish: PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin:/sbin" ldconfig -n /usr/xenomai/lib
----------------------------------------------------------------------
Libraries have been installed in:
   /usr/xenomai/lib

If you ever happen to want to link against installed libraries
in a given directory, LIBDIR, you must either use libtool, and
specify the full pathname of the library, or use the '-LLIBDIR'
flag during linking and do at least one of the following:
   - add LIBDIR to the 'LD_LIBRARY_PATH' environment variable
     during execution
   - add LIBDIR to the 'LD_RUN_PATH' environment variable
     during linking
   - use the '-Wl,-rpath -Wl,LIBDIR' linker flag
   - have your system administrator add LIBDIR to '/etc/ld.so.conf'

See any operating system documentation about shared libraries for
more information, such as the ld(1) and ld.so(8) manual pages.
----------------------------------------------------------------------
make[3]: Nothing to be done for 'install-data-am'.
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/smokey'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/smokey'
Making install in alchemy
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/alchemy'
  CC       libalchemy_la-init.lo
  CC       libalchemy_la-internal.lo
  CC       libalchemy_la-alarm.lo
  CC       libalchemy_la-buffer.lo
  CC       libalchemy_la-cond.lo
  CC       libalchemy_la-event.lo
  CC       libalchemy_la-heap.lo
  CC       libalchemy_la-mutex.lo
  CC       libalchemy_la-queue.lo
  CC       libalchemy_la-task.lo
  CC       libalchemy_la-sem.lo
  CC       libalchemy_la-timer.lo
  CCLD     libalchemy.la
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/alchemy'
 /usr/bin/mkdir -p '/usr/xenomai/lib'
 /bin/bash ../../libtool   --mode=install /usr/bin/install -c   libalchemy.la '/usr/xenomai/lib'
libtool: install: /usr/bin/install -c .libs/libalchemy.so.0.0.0 /usr/xenomai/lib/libalchemy.so.0.0.0
libtool: install: (cd /usr/xenomai/lib && { ln -s -f libalchemy.so.0.0.0 libalchemy.so.0 || { rm -f libalchemy.so.0 && ln -s libalchemy.so.0.0.0 libalchemy.so.0; }; })
libtool: install: (cd /usr/xenomai/lib && { ln -s -f libalchemy.so.0.0.0 libalchemy.so || { rm -f libalchemy.so && ln -s libalchemy.so.0.0.0 libalchemy.so; }; })
libtool: install: /usr/bin/install -c .libs/libalchemy.lai /usr/xenomai/lib/libalchemy.la
libtool: install: /usr/bin/install -c .libs/libalchemy.a /usr/xenomai/lib/libalchemy.a
libtool: install: chmod 644 /usr/xenomai/lib/libalchemy.a
libtool: install: ranlib /usr/xenomai/lib/libalchemy.a
libtool: finish: PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin:/sbin" ldconfig -n /usr/xenomai/lib
----------------------------------------------------------------------
Libraries have been installed in:
   /usr/xenomai/lib

If you ever happen to want to link against installed libraries
in a given directory, LIBDIR, you must either use libtool, and
specify the full pathname of the library, or use the '-LLIBDIR'
flag during linking and do at least one of the following:
   - add LIBDIR to the 'LD_LIBRARY_PATH' environment variable
     during execution
   - add LIBDIR to the 'LD_RUN_PATH' environment variable
     during linking
   - use the '-Wl,-rpath -Wl,LIBDIR' linker flag
   - have your system administrator add LIBDIR to '/etc/ld.so.conf'

See any operating system documentation about shared libraries for
more information, such as the ld(1) and ld.so(8) manual pages.
----------------------------------------------------------------------
make[3]: Nothing to be done for 'install-data-am'.
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/alchemy'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/alchemy'
Making install in vxworks
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/vxworks'
  CC       libvxworks_la-init.lo
  CC       libvxworks_la-errnoLib.lo
  CC       libvxworks_la-intLib.lo
  CC       libvxworks_la-kernLib.lo
  CC       libvxworks_la-lstLib.lo
  CC       libvxworks_la-memPartLib.lo
  CC       libvxworks_la-msgQLib.lo
  CC       libvxworks_la-rngLib.lo
  CC       libvxworks_la-semLib.lo
  CC       libvxworks_la-taskLib.lo
  CC       libvxworks_la-taskHookLib.lo
  CC       libvxworks_la-taskInfo.lo
  CC       libvxworks_la-tickLib.lo
  CC       libvxworks_la-wdLib.lo
  CC       libvxworks_la-sysLib.lo
  CCLD     libvxworks.la
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/vxworks'
 /usr/bin/mkdir -p '/usr/xenomai/lib'
 /bin/bash ../../libtool   --mode=install /usr/bin/install -c   libvxworks.la '/usr/xenomai/lib'
libtool: install: /usr/bin/install -c .libs/libvxworks.so.0.0.0 /usr/xenomai/lib/libvxworks.so.0.0.0
libtool: install: (cd /usr/xenomai/lib && { ln -s -f libvxworks.so.0.0.0 libvxworks.so.0 || { rm -f libvxworks.so.0 && ln -s libvxworks.so.0.0.0 libvxworks.so.0; }; })
libtool: install: (cd /usr/xenomai/lib && { ln -s -f libvxworks.so.0.0.0 libvxworks.so || { rm -f libvxworks.so && ln -s libvxworks.so.0.0.0 libvxworks.so; }; })
libtool: install: /usr/bin/install -c .libs/libvxworks.lai /usr/xenomai/lib/libvxworks.la
libtool: install: /usr/bin/install -c .libs/libvxworks.a /usr/xenomai/lib/libvxworks.a
libtool: install: chmod 644 /usr/xenomai/lib/libvxworks.a
libtool: install: ranlib /usr/xenomai/lib/libvxworks.a
libtool: finish: PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin:/sbin" ldconfig -n /usr/xenomai/lib
----------------------------------------------------------------------
Libraries have been installed in:
   /usr/xenomai/lib

If you ever happen to want to link against installed libraries
in a given directory, LIBDIR, you must either use libtool, and
specify the full pathname of the library, or use the '-LLIBDIR'
flag during linking and do at least one of the following:
   - add LIBDIR to the 'LD_LIBRARY_PATH' environment variable
     during execution
   - add LIBDIR to the 'LD_RUN_PATH' environment variable
     during linking
   - use the '-Wl,-rpath -Wl,LIBDIR' linker flag
   - have your system administrator add LIBDIR to '/etc/ld.so.conf'

See any operating system documentation about shared libraries for
more information, such as the ld(1) and ld.so(8) manual pages.
----------------------------------------------------------------------
make[3]: Nothing to be done for 'install-data-am'.
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/vxworks'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/vxworks'
Making install in psos
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/psos'
  CC       libpsos_la-init.lo
  CC       libpsos_la-pt.lo
  CC       libpsos_la-queue.lo
  CC       libpsos_la-rn.lo
  CC       libpsos_la-sem.lo
  CC       libpsos_la-task.lo
  CC       libpsos_la-tm.lo
  CCLD     libpsos.la
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/psos'
 /usr/bin/mkdir -p '/usr/xenomai/lib'
 /bin/bash ../../libtool   --mode=install /usr/bin/install -c   libpsos.la '/usr/xenomai/lib'
libtool: install: /usr/bin/install -c .libs/libpsos.so.0.0.0 /usr/xenomai/lib/libpsos.so.0.0.0
libtool: install: (cd /usr/xenomai/lib && { ln -s -f libpsos.so.0.0.0 libpsos.so.0 || { rm -f libpsos.so.0 && ln -s libpsos.so.0.0.0 libpsos.so.0; }; })
libtool: install: (cd /usr/xenomai/lib && { ln -s -f libpsos.so.0.0.0 libpsos.so || { rm -f libpsos.so && ln -s libpsos.so.0.0.0 libpsos.so; }; })
libtool: install: /usr/bin/install -c .libs/libpsos.lai /usr/xenomai/lib/libpsos.la
libtool: install: /usr/bin/install -c .libs/libpsos.a /usr/xenomai/lib/libpsos.a
libtool: install: chmod 644 /usr/xenomai/lib/libpsos.a
libtool: install: ranlib /usr/xenomai/lib/libpsos.a
libtool: finish: PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin:/sbin" ldconfig -n /usr/xenomai/lib
----------------------------------------------------------------------
Libraries have been installed in:
   /usr/xenomai/lib

If you ever happen to want to link against installed libraries
in a given directory, LIBDIR, you must either use libtool, and
specify the full pathname of the library, or use the '-LLIBDIR'
flag during linking and do at least one of the following:
   - add LIBDIR to the 'LD_LIBRARY_PATH' environment variable
     during execution
   - add LIBDIR to the 'LD_RUN_PATH' environment variable
     during linking
   - use the '-Wl,-rpath -Wl,LIBDIR' linker flag
   - have your system administrator add LIBDIR to '/etc/ld.so.conf'

See any operating system documentation about shared libraries for
more information, such as the ld(1) and ld.so(8) manual pages.
----------------------------------------------------------------------
make[3]: Nothing to be done for 'install-data-am'.
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/psos'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib/psos'
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/lib'
make[3]: Nothing to be done for 'install-exec-am'.
make[3]: Nothing to be done for 'install-data-am'.
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib'
make[1]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/lib'
Making install in config
make[1]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/config'
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/config'
make[2]: Nothing to be done for 'install-exec-am'.
make[2]: Nothing to be done for 'install-data-am'.
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/config'
make[1]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/config'
Making install in include
make[1]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include'
Making install in boilerplate
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/boilerplate'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/boilerplate'
make[3]: Nothing to be done for 'install-exec-am'.
 /usr/bin/mkdir -p '/usr/xenomai/include/boilerplate'
 /usr/bin/install -c -m 644 ../../../xenomai_dwld/xenomai-3.1/include/boilerplate/ancillaries.h ../../../xenomai_dwld/xenomai-3.1/include/boilerplate/atomic.h ../../../xenomai_dwld/xenomai-3.1/include/boilerplate/avl.h ../../../xenomai_dwld/xenomai-3.1/include/boilerplate/shavl.h ../../../xenomai_dwld/xenomai-3.1/include/boilerplate/avl-inner.h ../../../xenomai_dwld/xenomai-3.1/include/boilerplate/compiler.h ../../../xenomai_dwld/xenomai-3.1/include/boilerplate/debug.h ../../../xenomai_dwld/xenomai-3.1/include/boilerplate/hash.h ../../../xenomai_dwld/xenomai-3.1/include/boilerplate/heapmem.h ../../../xenomai_dwld/xenomai-3.1/include/boilerplate/libc.h ../../../xenomai_dwld/xenomai-3.1/include/boilerplate/list.h ../../../xenomai_dwld/xenomai-3.1/include/boilerplate/lock.h ../../../xenomai_dwld/xenomai-3.1/include/boilerplate/namegen.h ../../../xenomai_dwld/xenomai-3.1/include/boilerplate/obstack.h ../../../xenomai_dwld/xenomai-3.1/include/boilerplate/private-list.h ../../../xenomai_dwld/xenomai-3.1/include/boilerplate/scope.h ../../../xenomai_dwld/xenomai-3.1/include/boilerplate/setup.h ../../../xenomai_dwld/xenomai-3.1/include/boilerplate/shared-list.h ../../../xenomai_dwld/xenomai-3.1/include/boilerplate/time.h ../../../xenomai_dwld/xenomai-3.1/include/boilerplate/tunables.h '/usr/xenomai/include/boilerplate'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/boilerplate'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/boilerplate'
Making install in copperplate
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/copperplate'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/copperplate'
make[3]: Nothing to be done for 'install-exec-am'.
 /usr/bin/mkdir -p '/usr/xenomai/include/copperplate'
 /usr/bin/install -c -m 644 ../../../xenomai_dwld/xenomai-3.1/include/copperplate/clockobj.h ../../../xenomai_dwld/xenomai-3.1/include/copperplate/cluster.h ../../../xenomai_dwld/xenomai-3.1/include/copperplate/debug.h ../../../xenomai_dwld/xenomai-3.1/include/copperplate/eventobj.h ../../../xenomai_dwld/xenomai-3.1/include/copperplate/heapobj.h ../../../xenomai_dwld/xenomai-3.1/include/copperplate/reference.h ../../../xenomai_dwld/xenomai-3.1/include/copperplate/registry.h ../../../xenomai_dwld/xenomai-3.1/include/copperplate/semobj.h ../../../xenomai_dwld/xenomai-3.1/include/copperplate/syncobj.h ../../../xenomai_dwld/xenomai-3.1/include/copperplate/threadobj.h ../../../xenomai_dwld/xenomai-3.1/include/copperplate/timerobj.h ../../../xenomai_dwld/xenomai-3.1/include/copperplate/traceobj.h ../../../xenomai_dwld/xenomai-3.1/include/copperplate/tunables.h ../../../xenomai_dwld/xenomai-3.1/include/copperplate/wrappers.h '/usr/xenomai/include/copperplate'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/copperplate'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/copperplate'
Making install in smokey
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/smokey'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/smokey'
make[3]: Nothing to be done for 'install-exec-am'.
 /usr/bin/mkdir -p '/usr/xenomai/include/smokey'
 /usr/bin/install -c -m 644 ../../../xenomai_dwld/xenomai-3.1/include/smokey/smokey.h '/usr/xenomai/include/smokey'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/smokey'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/smokey'
Making install in alchemy
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/alchemy'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/alchemy'
make[3]: Nothing to be done for 'install-exec-am'.
 /usr/bin/mkdir -p '/usr/xenomai/include/alchemy'
 /usr/bin/install -c -m 644 ../../../xenomai_dwld/xenomai-3.1/include/alchemy/alarm.h ../../../xenomai_dwld/xenomai-3.1/include/alchemy/buffer.h ../../../xenomai_dwld/xenomai-3.1/include/alchemy/compat.h ../../../xenomai_dwld/xenomai-3.1/include/alchemy/cond.h ../../../xenomai_dwld/xenomai-3.1/include/alchemy/event.h ../../../xenomai_dwld/xenomai-3.1/include/alchemy/heap.h ../../../xenomai_dwld/xenomai-3.1/include/alchemy/mutex.h ../../../xenomai_dwld/xenomai-3.1/include/alchemy/pipe.h ../../../xenomai_dwld/xenomai-3.1/include/alchemy/queue.h ../../../xenomai_dwld/xenomai-3.1/include/alchemy/sem.h ../../../xenomai_dwld/xenomai-3.1/include/alchemy/task.h ../../../xenomai_dwld/xenomai-3.1/include/alchemy/timer.h '/usr/xenomai/include/alchemy'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/alchemy'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/alchemy'
Making install in psos
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/psos'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/psos'
make[3]: Nothing to be done for 'install-exec-am'.
 /usr/bin/mkdir -p '/usr/xenomai/include/psos'
 /usr/bin/install -c -m 644 ../../../xenomai_dwld/xenomai-3.1/include/psos/psos.h ../../../xenomai_dwld/xenomai-3.1/include/psos/tunables.h '/usr/xenomai/include/psos'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/psos'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/psos'
Making install in rtdm
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/rtdm'
Making install in uapi
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/rtdm/uapi'
make[4]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/rtdm/uapi'
make[4]: Nothing to be done for 'install-exec-am'.
 /usr/bin/mkdir -p '/usr/xenomai/include/rtdm/uapi'
 /usr/bin/install -c -m 644 ../../../../xenomai_dwld/xenomai-3.1/include/rtdm/uapi/rtdm.h '/usr/xenomai/include/rtdm/uapi'
make[4]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/rtdm/uapi'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/rtdm/uapi'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/rtdm'
make[4]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/rtdm'
make[4]: Nothing to be done for 'install-exec-am'.
 /usr/bin/mkdir -p '/usr/xenomai/include/rtdm'
 /usr/bin/install -c -m 644 ../../../xenomai_dwld/xenomai-3.1/include/rtdm/rtdm.h '/usr/xenomai/include/rtdm'
make[4]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/rtdm'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/rtdm'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/rtdm'
Making install in trank
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/trank'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/trank'
make[4]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/trank'
make[4]: Nothing to be done for 'install-exec-am'.
 /usr/bin/mkdir -p '/usr/xenomai/include/trank'
 /usr/bin/install -c -m 644 ../../../xenomai_dwld/xenomai-3.1/include/trank/trank.h '/usr/xenomai/include/trank'
make[4]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/trank'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/trank'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/trank'
Making install in vxworks
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/vxworks'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/vxworks'
make[3]: Nothing to be done for 'install-exec-am'.
 /usr/bin/mkdir -p '/usr/xenomai/include/vxworks'
 /usr/bin/install -c -m 644 ../../../xenomai_dwld/xenomai-3.1/include/vxworks/errnoLib.h ../../../xenomai_dwld/xenomai-3.1/include/vxworks/intLib.h ../../../xenomai_dwld/xenomai-3.1/include/vxworks/kernLib.h ../../../xenomai_dwld/xenomai-3.1/include/vxworks/lstLib.h ../../../xenomai_dwld/xenomai-3.1/include/vxworks/memPartLib.h ../../../xenomai_dwld/xenomai-3.1/include/vxworks/msgQLib.h ../../../xenomai_dwld/xenomai-3.1/include/vxworks/rngLib.h ../../../xenomai_dwld/xenomai-3.1/include/vxworks/semLib.h ../../../xenomai_dwld/xenomai-3.1/include/vxworks/sysLib.h ../../../xenomai_dwld/xenomai-3.1/include/vxworks/taskHookLib.h ../../../xenomai_dwld/xenomai-3.1/include/vxworks/taskInfo.h ../../../xenomai_dwld/xenomai-3.1/include/vxworks/taskLib.h ../../../xenomai_dwld/xenomai-3.1/include/vxworks/tickLib.h ../../../xenomai_dwld/xenomai-3.1/include/vxworks/types.h ../../../xenomai_dwld/xenomai-3.1/include/vxworks/wdLib.h '/usr/xenomai/include/vxworks'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/vxworks'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/vxworks'
Making install in xenomai
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/xenomai'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/xenomai'
make[3]: Nothing to be done for 'install-exec-am'.
 /usr/bin/mkdir -p '/usr/xenomai/include/xenomai'
 /usr/bin/install -c -m 644 ../../../xenomai_dwld/xenomai-3.1/include/xenomai/init.h ../../../xenomai_dwld/xenomai-3.1/include/xenomai/tunables.h ../../../xenomai_dwld/xenomai-3.1/include/xenomai/version.h '/usr/xenomai/include/xenomai'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/xenomai'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/xenomai'
Making install in mercury
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/mercury'
Making install in boilerplate
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/mercury/boilerplate'
make[4]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/mercury/boilerplate'
make[4]: Nothing to be done for 'install-exec-am'.
 /usr/bin/mkdir -p '/usr/xenomai/include/mercury/boilerplate'
 /usr/bin/install -c -m 644 ../../../../xenomai_dwld/xenomai-3.1/include/mercury/boilerplate/sched.h ../../../../xenomai_dwld/xenomai-3.1/include/mercury/boilerplate/limits.h ../../../../xenomai_dwld/xenomai-3.1/include/mercury/boilerplate/signal.h ../../../../xenomai_dwld/xenomai-3.1/include/mercury/boilerplate/trace.h ../../../../xenomai_dwld/xenomai-3.1/include/mercury/boilerplate/wrappers.h '/usr/xenomai/include/mercury/boilerplate'
make[4]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/mercury/boilerplate'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/mercury/boilerplate'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/mercury'
make[4]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include/mercury'
make[4]: Nothing to be done for 'install-exec-am'.
make[4]: Nothing to be done for 'install-data-am'.
make[4]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/mercury'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/mercury'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include/mercury'
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/include'
make[3]: Nothing to be done for 'install-exec-am'.
 /usr/bin/mkdir -p '/usr/xenomai/include'
 /usr/bin/install -c -m 644 xeno_config.h '/usr/xenomai/include'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include'
make[1]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/include'
Making install in scripts
make[1]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/scripts'
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/scripts'
 /usr/bin/mkdir -p '/usr/xenomai/bin'
 /usr/bin/install -c xeno-config xeno ../../xenomai_dwld/xenomai-3.1/scripts/wrap-link.sh '/usr/xenomai/bin'
/bin/bash /home/dhruva/gsoc21/bela/xenomai_dwld/xenomai-3.1/config/install-sh -d /usr/xenomai/lib
/usr/bin/install -c -m 644 ../../xenomai_dwld/xenomai-3.1/scripts/dynlist.ld /usr/xenomai/lib
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/scripts'
make[1]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/scripts'
Making install in testsuite
make[1]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite'
Making install in latency
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/latency'
  CC       latency-latency.o
  CCLD     latency
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/latency'
make[3]: Nothing to be done for 'install-exec-am'.
 /usr/bin/mkdir -p '/usr/xenomai/bin'
  /bin/bash ../../libtool   --mode=install /usr/bin/install -c latency '/usr/xenomai/bin'
libtool: install: /usr/bin/install -c .libs/latency /usr/xenomai/bin/latency
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/latency'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/latency'
Making install in smokey
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey'
Making install in memory-heapmem
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey/memory-heapmem'
  CC       libmemory_heapmem_a-heapmem.o
  AR       libmemory-heapmem.a
ar: `u' modifier ignored since `D' is the default (see `U')
make[4]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey/memory-heapmem'
make[4]: Nothing to be done for 'install-exec-am'.
make[4]: Nothing to be done for 'install-data-am'.
make[4]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey/memory-heapmem'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey/memory-heapmem'
Making install in memory-tlsf
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey/memory-tlsf'
  CC       libmemory_tlsf_a-tlsf.o
  AR       libmemory-tlsf.a
ar: `u' modifier ignored since `D' is the default (see `U')
make[4]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey/memory-tlsf'
make[4]: Nothing to be done for 'install-exec-am'.
make[4]: Nothing to be done for 'install-data-am'.
make[4]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey/memory-tlsf'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey/memory-tlsf'
Making install in memcheck
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey/memcheck'
  CC       memcheck.o
  AR       libmemcheck.a
ar: `u' modifier ignored since `D' is the default (see `U')
make[4]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey/memcheck'
make[4]: Nothing to be done for 'install-exec-am'.
make[4]: Nothing to be done for 'install-data-am'.
make[4]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey/memcheck'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey/memcheck'
Making install in memory-pshared
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey/memory-pshared'
  CC       libmemory_pshared_a-pshared.o
  AR       libmemory-pshared.a
ar: `u' modifier ignored since `D' is the default (see `U')
make[4]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey/memory-pshared'
make[4]: Nothing to be done for 'install-exec-am'.
make[4]: Nothing to be done for 'install-data-am'.
make[4]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey/memory-pshared'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey/memory-pshared'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey'
  CC       smokey-main.o
  CCLD     smokey
make[4]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey'
make[4]: Nothing to be done for 'install-exec-am'.
 /usr/bin/mkdir -p '/usr/xenomai/bin'
  /bin/bash ../../libtool   --mode=install /usr/bin/install -c smokey '/usr/xenomai/bin'
libtool: install: /usr/bin/install -c .libs/smokey /usr/xenomai/bin/smokey
make[4]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite/smokey'
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite'
make[3]: Nothing to be done for 'install-exec-am'.
make[3]: Nothing to be done for 'install-data-am'.
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite'
make[1]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/testsuite'
Making install in utils
make[1]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/utils'
Making install in hdb
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/utils/hdb'
  CC       hdb-hdb.o
  CCLD     hdb
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/utils/hdb'
 /usr/bin/mkdir -p '/usr/xenomai/sbin'
  /bin/bash ../../libtool   --mode=install /usr/bin/install -c hdb '/usr/xenomai/sbin'
libtool: install: /usr/bin/install -c .libs/hdb /usr/xenomai/sbin/hdb
make[3]: Nothing to be done for 'install-data-am'.
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/utils/hdb'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/utils/hdb'
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/utils'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/utils'
make[3]: Nothing to be done for 'install-exec-am'.
make[3]: Nothing to be done for 'install-data-am'.
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/utils'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/utils'
make[1]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/utils'
Making install in demo
make[1]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/demo'
Making install in posix
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/demo/posix'
Making install in cyclictest
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/demo/posix/cyclictest'
  CC       cyclictest-cyclictest.o
  CC       cyclictest-error.o
  CC       cyclictest-rt-utils.o
  CCLD     cyclictest
make[4]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/demo/posix/cyclictest'
make[4]: Nothing to be done for 'install-exec-am'.
 /usr/bin/mkdir -p '/usr/xenomai/demo'
  /bin/bash ../../../libtool   --mode=install /usr/bin/install -c cyclictest '/usr/xenomai/demo'
libtool: install: /usr/bin/install -c .libs/cyclictest /usr/xenomai/demo/cyclictest
make[4]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/demo/posix/cyclictest'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/demo/posix/cyclictest'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/demo/posix'
make[4]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/demo/posix'
make[4]: Nothing to be done for 'install-exec-am'.
make[4]: Nothing to be done for 'install-data-am'.
make[4]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/demo/posix'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/demo/posix'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/demo/posix'
Making install in alchemy
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/demo/alchemy'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/demo/alchemy'
  CC       altency-altency.o
  CCLD     altency
make[4]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/demo/alchemy'
make[4]: Nothing to be done for 'install-exec-am'.
 /usr/bin/mkdir -p '/usr/xenomai/demo'
  /bin/bash ../../libtool   --mode=install /usr/bin/install -c altency '/usr/xenomai/demo'
libtool: install: /usr/bin/install -c .libs/altency /usr/xenomai/demo/altency
make[4]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/demo/alchemy'
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/demo/alchemy'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/demo/alchemy'
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/demo'
make[3]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild/demo'
make[3]: Nothing to be done for 'install-exec-am'.
make[3]: Nothing to be done for 'install-data-am'.
make[3]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/demo'
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/demo'
make[1]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild/demo'
make[1]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild'
make[2]: Entering directory '/home/dhruva/gsoc21/bela/xenoBuild'
make[2]: Nothing to be done for 'install-exec-am'.
make[2]: Nothing to be done for 'install-data-am'.
make[2]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild'
make[1]: Leaving directory '/home/dhruva/gsoc21/bela/xenoBuild'
```

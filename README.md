## reex
A little CPU benchmarking tool

## How it works?
reex uses CPU's SSE, SSE2, and AVX SIMD extensions set to calculate floating point numbers. Depending on your CPU, if it supports these three SIMD extensions, you can try it out!

### Info
#### Intel
SSE support: Pentium III\
SSE2 support: Pentium D\
AVX support: Sandy Bridge [see here](https://en.wikipedia.org/wiki/Advanced_Vector_Extensions#CPUs_with_AVX)

#### AMD
SSE support: Athlon XP and Duron\
SSE2 support: Athlon 64 and Opteron\
AVX support: Bulldozer [see here](https://en.wikipedia.org/wiki/Advanced_Vector_Extensions#CPUs_with_AVX)

Note: Benchmarking AVX isn't mandatory if your CPU doesn't support it. Comment out "#define AVX_ENABLE" and remove `-mavx` in the makefile and recompile the program.

Note 2: Default floatings points are different for each operation. And the time between those operations isn't exactly correct, `clock_gettime` may give a different result on a different version of the Linux kernel. The time between calling `clock_gettime` from userspace, is also not calculated. Don't take them as "last values", they're most likely approx values.
